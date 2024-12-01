
#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/FileSystem.h"
#include <memory>
#include "codegen.hpp"


static std::unique_ptr<llvm::LLVMContext> TheContext;
static std::unique_ptr<llvm::IRBuilder<>> Builder;
static std::unique_ptr<llvm::Module> TheModule;
static std::map<std::string, llvm::Value *> NamedValues;
static std::map<std::string, llvm::Type *> NamedTypes;
static std::map<std::string, std::pair<llvm::Value *, llvm::Type *>> Arrays;
struct recordVariable
{
    std::string name;
    llvm::Type *type;
    llvm::Value *value;
};
static std::map<std::string, std::vector<recordVariable>> Records;
static std::map<std::pair<std::string, std::string>, std::pair<llvm::Value *, llvm::Type *>> RecordsValues;
void code_generation(AST_Node *node);

std::string get_name(AST_Node *node)
{
    AST_Node *child = node->children[0];
    Identifier_Node *Identifier_node = static_cast<Identifier_Node *>(child);
    return Identifier_node->identifier_name.c_str();
}
std::string get_name_id(AST_Node *node)
{
    if (node->type != IDENTIFIER_NODE_TYPE)
        return "";
    Identifier_Node *Identifier_node = static_cast<Identifier_Node *>(node);
    return Identifier_node->identifier_name.c_str();
}

std::string get_op(AST_Node *node)
{
    Operator *op_node = static_cast<Operator *>(node);
    return op_node->operation_name.c_str();
}

llvm::Value *createBinaryOp(const std::string &op, llvm::Value *left, llvm::Value *right)
{
    if (op == "+")
        return Builder->CreateAdd(left, right, "sum");
    else if (op == "-")
        return Builder->CreateSub(left, right, "diff");
    else if (op == "*")
        return Builder->CreateMul(left, right, "mul");
    else if (op == "/")
        return Builder->CreateSDiv(left, right, "sdiv");
    else if (op == "%")
        return Builder->CreateSRem(left, right, "srem");
    else if (op == "<")
        return Builder->CreateICmpSLT(left, right, "lt");
    else if (op == "<=")
        return Builder->CreateICmpSLE(left, right, "le");
    else if (op == ">")
        return Builder->CreateICmpSGT(left, right, "gt");
    else if (op == ">=")
        return Builder->CreateICmpSGE(left, right, "ge");
    else if (op == "=")
        return Builder->CreateICmpEQ(left, right, "eq");
    else if (op == "and")
        return Builder->CreateAnd(left, right, "and");
    else if (op == "or")
        return Builder->CreateOr(left, right, "or");
    else if (op == "xor")
        return Builder->CreateXor(left, right, "xor");
    return nullptr;
}

llvm::Value *createCompoundAssignment(const std::string &op, llvm::Value *left, llvm::Value *right)
{
    llvm::Value *result = createBinaryOp(op.substr(0, 1), left, right);
    Builder->CreateStore(result, left);
    return result;
}

llvm::Value *AST_Node::codegen()
{
    switch (this->type)
    {
    case IDENTIFIER_NODE_TYPE:
    {
        std::string name = get_name_id(this);
        llvm::Value *ptr = NamedValues[name];
        llvm::Type *varType = NamedTypes[name];
        return Builder->CreateLoad(varType, ptr, name);
    }
    case ARRAY_ACCESS:
    {
        std::string array_name = get_name_id(this->children[0]);
        llvm::Value *arrayPointer = NamedValues[array_name];
        llvm::Value *index = this->children[1]->codegen();
        llvm::Value *elementPointer = Builder->CreateGEP(NamedTypes[array_name], arrayPointer, index);
        return Builder->CreateLoad(NamedTypes[array_name], elementPointer, array_name);
    }
    case RECORD_ACCESS:
    {
        std::string record_name = get_name(this);
        std::string access_operand_name = get_name_id(this->children[1]);
        return Builder->CreateLoad(RecordsValues[{record_name, access_operand_name}].second,
                                   RecordsValues[{record_name, access_operand_name}].first,
                                   record_name + " " + access_operand_name);
    }
    case INTEGER_NODE:
    {
        return llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), static_cast<Integer_Node *>(this)->val);
    }
    case REAL_NODE:
    {
        return llvm::ConstantFP::get(llvm::Type::getDoubleTy(*TheContext), static_cast<Real_Node *>(this)->val);
    }
    case BOOLEAN_NODE:
    {
        return llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), static_cast<Boolean_Node *>(this)->val ? 1 : 0);
    }
    case PRIMARY_EXPRESSION:
    {
        if (this->children.size() == 2)
        {
            llvm::Value *x = this->children[1]->codegen();
            return llvm::BinaryOperator::CreateNot(x, "not");
        }
        return this->children[0]->codegen();
    }
    case PRIMARY_NODE:
    case SUMMAND:
    {
        return this->children[0]->codegen();
    }
    case SIMPLE:
    case FACTOR:
    case RELATION:
    case EXPRESSION:
    {
        if (this->children.size() == 1)
        {
            return this->children[0]->codegen();
        }

        llvm::Value *leftChild = this->children[0]->codegen();
        llvm::Value *rightChild = this->children[2]->codegen();
        std::string op = get_op(this->children[1]);

        llvm::Value *result = createBinaryOp(op, leftChild, rightChild);
        if (result)
            return result;
        if (op == "+=" || op == "-=" || op == "*=" || op == "/=" || op == "%=")
        {
            return createCompoundAssignment(op, leftChild, rightChild);
        }
        break;
    }
    case RETURN_EX:
    {
        AST_Node *expr = this->children[0];
        llvm::Value *returnValue = expr->codegen();
        return Builder->CreateRet(returnValue);
    }
    case Routine_Call:
    {
        llvm::Function *function = TheModule->getFunction(get_name_id(this->children[0]));
        std::vector<llvm::Value *> args;
        for (auto child : this->children[1]->children)
        {
            args.push_back(child->codegen());
        }
        // std::cout<<args.size()<<'\n';
        llvm::Value *callInst = Builder->CreateCall(function, args, get_name_id(this->children[0]) + "_call");
        return callInst;
    }
    default:
        break;
    }
    return nullptr;
}
std::string get_type_name(AST_Node *node)
{
    Type_Node *type_node = static_cast<Type_Node *>(node);
    return type_node->type_name.c_str();
}

llvm::Type *get_type(AST_Node *node)
{
    Type_Node *type_node = static_cast<Type_Node *>(node);
    std::string name = get_type_name(type_node);
    if (name == "integer")
    {
        return llvm::Type::getInt32Ty(*TheContext);
    }
    else if (name == "real")
    {
        return llvm::Type::getDoubleTy(*TheContext);
    }
    else if (name == "boolean")
    {
        return llvm::Type::getInt1Ty(*TheContext);
    }
    else if (name == "identifier")
    {
        return NamedTypes[get_name_id(node->children[0])];
    }
    else
    {
        return llvm::Type::getInt32Ty(*TheContext);
    }
}

void Varible_Decleration_code_Gen(AST_Node *node)
{
    if (get_type_name(node->children[1]) == "identifier" &&
        Arrays.count(get_name_id(node->children[1]->children[0])))
    {

        std::pair<llvm::Value *, llvm::Type *> arrayInfo = Arrays[get_name_id(node->children[1]->children[0])];
        llvm::Value *arraySizeValue = arrayInfo.first;
        llvm::Type *elementType = arrayInfo.second;

        llvm::Function *mallocFunction = TheModule->getFunction("malloc");
        if (!mallocFunction)
        {
            llvm::FunctionType *mallocType = llvm::FunctionType::get(
                llvm::PointerType::get(llvm::Type::getInt8Ty(*TheContext), 0),
                {llvm::Type::getInt64Ty(*TheContext)},
                false);
            mallocFunction = llvm::Function::Create(
                mallocType,
                llvm::Function::ExternalLinkage,
                "malloc",
                *TheModule);
        }

        uint64_t elementSize = TheModule->getDataLayout().getTypeAllocSize(elementType);
        llvm::Value *elementSizeValue = llvm::ConstantInt::get(
            llvm::Type::getInt64Ty(*TheContext),
            elementSize);

        llvm::Value *totalSize = Builder->CreateMul(
            elementSizeValue,
            arraySizeValue,
            "total_array_size");

        llvm::Value *mallocCall = Builder->CreateCall(
            mallocFunction,
            {totalSize},
            "malloc_call");

        llvm::Value *arrayPointer = Builder->CreateBitCast(
            mallocCall,
            llvm::PointerType::get(elementType, 0),
            "array_ptr");

        NamedValues[get_name(node)] = arrayPointer;
        NamedTypes[get_name(node)] = elementType;
    }
    else if (get_type_name(node->children[1]) == "identifier" &&
             Records.count(get_name_id(node->children[1]->children[0])))
    {
        std::string RecordTypeName = get_name(node->children[1]);
        std::string RecordName = get_name(node);
        for (auto recordVar : Records[RecordTypeName])
        {
            RecordsValues[{RecordName, recordVar.name}] = {
                Builder->CreateAlloca(recordVar.type, nullptr, RecordTypeName + " " + RecordName + " " + recordVar.name),
                recordVar.type};
            Builder->CreateStore(recordVar.value, RecordsValues[{RecordName, recordVar.name}].first);
        }
    }
    else
    {
        std::string name = get_name(node);
        llvm::Value *v = Builder->CreateAlloca(get_type(node->children[1]), nullptr, name);

        llvm::Value *initial_value = nullptr;
        if (node->children.size() > 2)
        {
            initial_value = node->children[2]->codegen();
        }
        else
        {
            initial_value = llvm::Constant::getNullValue(get_type(node->children[1]));
        }

        Builder->CreateStore(initial_value, v);
        NamedValues[name] = v;
        NamedTypes[name] = get_type(node->children[1]);
    }
}

void Assign_code_gen(AST_Node *node)
{
    llvm::Value *leftChild = nullptr;
    if (node->children[0]->children[0]->type == ARRAY_ACCESS)
    {
        std::string array_name = get_name_id(node->children[0]->children[0]->children[0]);
        llvm::Value *arrayPointer = NamedValues[array_name];
        llvm::Value *index = node->children[0]->children[0]->children[1]->codegen();
        llvm::Value *elementPointer = Builder->CreateGEP(llvm::Type::getInt32Ty(*TheContext), arrayPointer, index);
        leftChild = elementPointer;
    }
    else if (node->children[0]->children[0]->type == RECORD_ACCESS)
    {
        std::string recordName = get_name(node->children[0]->children[0]);
        std::string access_operand = get_name_id(node->children[0]->children[0]->children[1]);
        leftChild = RecordsValues[{recordName, access_operand}].first;
    }
    else
    {
        std::string name = get_name(node->children[0]->children[0]);
        leftChild = NamedValues[name];
        llvm::Type *leftType = NamedTypes[name];
    }
    llvm::Value *rightChild = node->children[2]->codegen();
    std::string op = get_op(node->children[1]);
    if (op == ":=")
    {
        Builder->CreateStore(rightChild, leftChild);
    }
    /* else if (op == "+=")
    {
        llvm::Value *leftValue = Builder->CreateLoad(leftType, leftChild, "left_val");
        llvm::Value *sum = Builder->CreateAdd(leftValue, rightChild, "sum");
        Builder->CreateStore(sum, leftChild);
    }
    else if (op == "-=")
    {
        llvm::Value *leftValue = Builder->CreateLoad(leftType, leftChild, "left_val");
        llvm::Value *diff = Builder->CreateSub(leftValue, rightChild, "diff");
        Builder->CreateStore(diff, leftChild);
    }
    else if (op == "*=")
    {
        llvm::Value *leftValue = Builder->CreateLoad(leftType, leftChild, "left_val");
        llvm::Value *product = Builder->CreateMul(leftValue, rightChild, "product");
        Builder->CreateStore(product, leftChild);
    }
    else if (op == "/=")
    {
        llvm::Value *leftValue = Builder->CreateLoad(leftType, leftChild, "left_val");
        llvm::Value *quotient = Builder->CreateSDiv(leftValue, rightChild, "quotient");
        Builder->CreateStore(quotient, leftChild);
    }
    else if (op == "%=")
    {
        llvm::Value *leftValue = Builder->CreateLoad(leftType, leftChild, "left_val");
        llvm::Value *remainder = Builder->CreateSRem(leftValue, rightChild, "remainder");
        Builder->CreateStore(remainder, leftChild);
    } */
}
void If_statement_code_gen(AST_Node *node)
{
    llvm::Value *CondV = node->children[0]->codegen();

    llvm::BasicBlock *ifTrue = llvm::BasicBlock::Create(*TheContext, "if_true");
    llvm::BasicBlock *endIf = llvm::BasicBlock::Create(*TheContext, "end_if");

    CondV = Builder->CreateICmpEQ(
        CondV,
        llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), 0),
        "is_false");

    Builder->CreateCondBr(CondV, endIf, ifTrue);
    llvm::Function *TheFunction = Builder->GetInsertBlock()->getParent();

    TheFunction->getBasicBlockList().push_back(ifTrue);
    Builder->SetInsertPoint(ifTrue);

    code_generation(node->children[1]);
    Builder->CreateBr(endIf);

    TheFunction->getBasicBlockList().push_back(endIf);
    Builder->SetInsertPoint(endIf);
}
void If_else_statement_code_gen(AST_Node *node)
{
    llvm::Value *CondV = node->children[0]->codegen();

    llvm::BasicBlock *ifTrue = llvm::BasicBlock::Create(*TheContext, "if_true");
    llvm::BasicBlock *ifFalse = llvm::BasicBlock::Create(*TheContext, "if_false");
    llvm::BasicBlock *endIf = llvm::BasicBlock::Create(*TheContext, "end_if");

    CondV = Builder->CreateICmpEQ(
        CondV,
        llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), 0),
        "is_false");

    llvm::Function *TheFunction = Builder->GetInsertBlock()->getParent();
    Builder->CreateCondBr(CondV, ifFalse, ifTrue);

    TheFunction->getBasicBlockList().push_back(ifTrue);
    Builder->SetInsertPoint(ifTrue);
    code_generation(node->children[1]);
    Builder->CreateBr(endIf);

    TheFunction->getBasicBlockList().push_back(ifFalse);
    Builder->SetInsertPoint(ifFalse);
    code_generation(node->children[2]);
    Builder->CreateBr(endIf);

    TheFunction->getBasicBlockList().push_back(endIf);
    Builder->SetInsertPoint(endIf);
}
std::stack<llvm::BasicBlock *> loopCondBlockStack;
std::stack<llvm::BasicBlock *> loopExitBlockStack;

void While_code_gen(AST_Node *node)
{
    llvm::BasicBlock *loop_cond = llvm::BasicBlock::Create(*TheContext, "loop_cond");
    llvm::BasicBlock *loop_body = llvm::BasicBlock::Create(*TheContext, "loop_body");
    llvm::BasicBlock *loop_exit = llvm::BasicBlock::Create(*TheContext, "loop_exit");

    llvm::Function *TheFunction = Builder->GetInsertBlock()->getParent();

    TheFunction->getBasicBlockList().push_back(loop_cond);
    Builder->CreateBr(loop_cond);
    Builder->SetInsertPoint(loop_cond);
    loopCondBlockStack.push(loop_cond);
    loopExitBlockStack.push(loop_exit);

    llvm::Value *cond = node->children[0]->codegen();
    if (cond->getType() != llvm::Type::getInt1Ty(*TheContext))
    {
        cond = Builder->CreateICmpNE(cond, llvm::ConstantInt::get(cond->getType(), 0), "non_zero_condition");
    }
    Builder->CreateCondBr(cond, loop_body, loop_exit);

    TheFunction->getBasicBlockList().push_back(loop_body);
    Builder->SetInsertPoint(loop_body);

    code_generation(node->children[1]);

    Builder->CreateBr(loop_cond);

    TheFunction->getBasicBlockList().push_back(loop_exit);
    Builder->SetInsertPoint(loop_exit);
    loopCondBlockStack.pop();
    loopExitBlockStack.pop();
}

void For_code_gen(AST_Node *node)
{
    llvm::BasicBlock *loop_init = llvm::BasicBlock::Create(*TheContext, "loop_init");
    llvm::BasicBlock *loop_cond = llvm::BasicBlock::Create(*TheContext, "loop_cond");
    llvm::BasicBlock *loop_body = llvm::BasicBlock::Create(*TheContext, "loop_body");
    llvm::BasicBlock *loop_exit = llvm::BasicBlock::Create(*TheContext, "loop_exit");

    llvm::Function *TheFunction = Builder->GetInsertBlock()->getParent();

    TheFunction->getBasicBlockList().push_back(loop_init);
    Builder->CreateBr(loop_init);
    Builder->SetInsertPoint(loop_init);
    loopCondBlockStack.push(loop_cond);
    loopExitBlockStack.push(loop_exit);

    std::string name = get_name(node);
    llvm::Value *iter_var = Builder->CreateAlloca(llvm::Type::getInt32Ty(*TheContext), nullptr, name);
    NamedValues[name] = iter_var;
    NamedTypes[name] = llvm::Type::getInt32Ty(*TheContext);
    bool is_reverse = (node->children[1]->type == RANGE_REVERSE);

    llvm::Value *start_value = node->children[1]->children[0]->codegen();
    llvm::Value *end_value = node->children[1]->children[1]->codegen();
    if(is_reverse)
    {
        Builder->CreateStore(end_value, iter_var);

    }
    else{
        Builder->CreateStore(start_value, iter_var);
    }

    Builder->CreateBr(loop_cond);

    TheFunction->getBasicBlockList().push_back(loop_cond);
    Builder->SetInsertPoint(loop_cond);

    llvm::Value *current_value = Builder->CreateLoad(llvm::Type::getInt32Ty(*TheContext), iter_var, "current_iter");
    llvm::Value *cond;
    if (is_reverse)
    {
        cond = Builder->CreateICmpSGE(current_value, start_value, "loop_cond"); 
    }
    else
    {
        cond = Builder->CreateICmpSLT(current_value, end_value, "loop_cond"); 
    }

    Builder->CreateCondBr(cond, loop_body, loop_exit);

    TheFunction->getBasicBlockList().push_back(loop_body);
    Builder->SetInsertPoint(loop_body);

    code_generation(node->children[2]);
    llvm::Value *incremented_value;
    if(is_reverse){
        incremented_value = Builder->CreateAdd(current_value, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), -1), "decrement");
    }
    else{
        incremented_value = Builder->CreateAdd(current_value, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 1), "increment");

    }

    Builder->CreateStore(incremented_value, iter_var);
    Builder->CreateBr(loop_cond);

    NamedValues.erase(name);
    NamedTypes.erase(name);
    TheFunction->getBasicBlockList().push_back(loop_exit);
    Builder->SetInsertPoint(loop_exit);
    loopCondBlockStack.pop();
    loopExitBlockStack.pop();
}

void Type_Declaration_primitive_type_codegen(AST_Node *node)
{
    AST_Node *identifierNode = node->children[0];
    AST_Node *typeNode = node->children[1];
    Identifier_Node *idNode = static_cast<Identifier_Node *>(identifierNode);
    std::string identifierName = idNode->identifier_name;
    llvm::Type *llvmType = get_type(typeNode);
    NamedTypes[identifierName] = llvmType;
}
void Type_Declaration_Array_codegen(AST_Node *node)
{
    AST_Node *identifierNode = node->children[0];
    AST_Node *typeNode = node->children[1]->children[0];
    llvm::Type *llvmType = get_type(typeNode->children[1]);
    llvm::Value *arraySize = typeNode->children[0]->codegen();
    Arrays[get_name_id(identifierNode)] = {arraySize, llvmType};
}

void Type_Declaration_Record_codgen(AST_Node *node)
{
    std::string RecordName = get_name(node);
    AST_Node *variblesNode = node->children[1]->children[0]->children[0];
    std::vector<recordVariable> recordVaribles;
    for (auto u : variblesNode->children)
    {
        recordVariable newRecordVariable;
        newRecordVariable.name = get_name(u);
        newRecordVariable.type = get_type(u->children[1]);
        if (u->children.size() > 2)
        {
            newRecordVariable.value = u->children[2]->codegen();
        }
        else
        {
            if (newRecordVariable.type->isIntegerTy())
            {
                newRecordVariable.value = llvm::ConstantInt::get(newRecordVariable.type, 0);
            }
            else if (newRecordVariable.type->isFloatingPointTy())
            {
                newRecordVariable.value = llvm::ConstantFP::get(newRecordVariable.type, 0.0);
            }
            else if (newRecordVariable.type->isIntegerTy(1))
            {
                newRecordVariable.value = llvm::ConstantInt::get(newRecordVariable.type, 0);
            }
        }
        recordVaribles.push_back(newRecordVariable);
    }
    Records[RecordName] = recordVaribles;
}
void Type_Declaration_codegen(AST_Node *node)
{
    if (get_type_name(node->children[1]) == "integer" || get_type_name(node->children[1]) == "real" || get_type_name(node->children[1]) == "boolean")
    {
        Type_Declaration_primitive_type_codegen(node);
    }
    else if (get_type_name(node->children[1]) == "arrayType")
    {
        print_ast(node, 0, "output.txt");

        Type_Declaration_Array_codegen(node);
    }
    else if (get_type_name(node->children[1]) == "recordType")
    {
        Type_Declaration_Record_codgen(node);
    }
}

void Routine_decleration_code_gen(AST_Node *node)
{
    bool hasReturnType = node->children.size() == 4;
    llvm::FunctionType *funcType;
    llvm::Function *function;
    std::vector<llvm::Type *> paramTypes;
    AST_Node *params = node->children[1];

    for (auto &param : params->children)
    {
        paramTypes.push_back(get_type(param->children[1]));
    }

    llvm::Type *returnType = nullptr;
    if (hasReturnType)
    {
        returnType = get_type(node->children[3]);
    }
    else
        returnType = llvm::Type::getInt32Ty(*TheContext);

    funcType = llvm::FunctionType::get(returnType, paramTypes, false);
    function = llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage,
        get_name_id(node->children[0]),
        *TheModule);

    llvm::BasicBlock *entry = llvm::BasicBlock::Create(*TheContext, "entry", function);
    llvm::IRBuilderBase::InsertPoint savedPoint = Builder->saveIP();
    Builder->SetInsertPoint(entry);

    auto funcArgs = function->args();
    int idx = 0;
    for (auto &arg : funcArgs)
    {
        std::string paramName = get_name(params->children[idx]);
        llvm::AllocaInst *alloc = Builder->CreateAlloca(get_type(params->children[idx]->children[1]), nullptr, paramName);
        Builder->CreateStore(&arg, alloc);
        NamedValues[paramName] = alloc;
        NamedTypes[paramName] = get_type(params->children[idx]->children[1]);
        idx++;
    }

    code_generation(node->children[2]);

    /* if (hasReturnType) {
        Builder->CreateRet(llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0));
    } else {
        Builder->CreateRetVoid();
    } */
    Builder->restoreIP(savedPoint);
}

void PrintNodeCodeGen(AST_Node *printNode)
{
    llvm::Function *printfFunc = TheModule->getFunction("printf");
    if (!printfFunc)
    {
        std::vector<llvm::Type *> printfArgs = {llvm::Type::getInt8PtrTy(*TheContext)};
        llvm::FunctionType *printfType = llvm::FunctionType::get(
            llvm::Type::getInt32Ty(*TheContext), printfArgs, true);
        printfFunc = llvm::Function::Create(
            printfType, llvm::Function::ExternalLinkage, "printf", *TheModule);
    }
    AST_Node *expression = printNode->children[0];
    llvm::Value *exprValue = expression->codegen();
    llvm::Type *exprType = llvm::Type::getInt32Ty(*TheContext);
    llvm::Value *formatStr = nullptr;

    if (exprType->isIntegerTy(32))
    {
        formatStr = Builder->CreateGlobalStringPtr("%d\n");
    }
    else if (exprType->isDoubleTy())
    {
        formatStr = Builder->CreateGlobalStringPtr("%f\n");
    }
    else if (exprType->isIntegerTy(1))
    {
        formatStr = Builder->CreateGlobalStringPtr("%d\n");
    }
    else
    {
        llvm::errs() << "Unsupported type for print statement!\n";
        return;
    }

    // Call printf with the format string and the expression value
    Builder->CreateCall(printfFunc, {formatStr, exprValue});
}

void Routine_call_code_gen(AST_Node *node)
{
    node->codegen();
}

void code_generation(AST_Node *node)
{
    if (!node)
        return;
    switch (node->type)
    {
    case VARIABLE_DECLARATION:
    {
        Varible_Decleration_code_Gen(node);
        break;
    }
    case TYPE_DECLARATION:
    {
        Type_Declaration_codegen(node);
        break;
    }
    case ASSIGN_STATEMENT:
    {
        Assign_code_gen(node);
        break;
    }
    case IF_STATEMENT:
    {
        If_statement_code_gen(node);
        break;
    }
    case IF_STATEMENT_ELSE:
    {
        If_else_statement_code_gen(node);
        break;
    }
    case WHILE_STATEMENT:
    {
        While_code_gen(node);
        break;
    }
    case FOR_STATEMENT:
    {
        For_code_gen(node);
        break;
    }
    case BREAK_EX:
    {
        llvm::BasicBlock *loop_exit = loopExitBlockStack.top();
        Builder->CreateBr(loop_exit);

        break;
    }

    case CONTINUE_EX:
{
    llvm::BasicBlock *loop_cond = loopCondBlockStack.top();

    Builder->CreateBr(loop_cond);

    break;
}


    case ROUTINE_DECLERATION:
    {
        Routine_decleration_code_gen(node);
        break;
    }
    case Routine_Call:
    {
        Routine_call_code_gen(node);
        break;
    }
    case RETURN_EX:
    {
        node->codegen();
        break;
    }
    case PRINT_STATMENT:
    {
        PrintNodeCodeGen(node);
        break;
    }
    case PROGRAM:
    case ITERATION_STATEMENT:
    case DECLARATION:
    case SIMPLE_DECLARATION:
    case BODY:
    case STATEMENT:
    case JUMP_STATEMENT:
    case RANGE_EX:
    {
        for (const auto &child : node->children)
        {
            code_generation(child);
        }
        break;
    }
    default:
        break;
    }
}

static void InitializeModule()
{
    TheContext = std::make_unique<llvm::LLVMContext>();
    TheModule = std::make_unique<llvm::Module>("KSS", *TheContext);
    Builder = std::make_unique<llvm::IRBuilder<>>(*TheContext);

    llvm::FunctionType *funcType = llvm::FunctionType::get(llvm::Type::getVoidTy(*TheContext), false);

    llvm::Function *function = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", *TheModule);

    llvm::BasicBlock *entry = llvm::BasicBlock::Create(*TheContext, "entry", function);

    Builder->SetInsertPoint(entry);
}

void Codegen::start_llvm(AST_Node *root)
{
    InitializeModule();
    code_generation(root);

    Builder->CreateRetVoid();
    std::error_code EC;

    if (EC)
    {
        llvm::errs() << "Error opening file: " << EC.message() << "\n";
        return;
    }
    llvm::raw_fd_ostream outputFile("output.ll", EC, llvm::sys::fs::OF_None);
    TheModule->print(outputFile, nullptr);
    return;
}
