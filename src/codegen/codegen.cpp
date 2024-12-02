
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
struct ArrayTypes {
    llvm::Value* sz;
    std::vector<llvm::Value*> dimensions;
    llvm::Type* type;
};
static std::map<std::string, ArrayTypes> Arrays;
struct recordVariable{
    std::string name;
    llvm::Type* type;
    llvm::Value* value;
    uint64_t sz;
};
static std::map<std::string, std::vector<recordVariable> >Records;
static std::map<std::string,llvm::Type*>RecordsTypes;
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
std::string get_type_name(AST_Node *node)
{
    Type_Node *type_node = static_cast<Type_Node *>(node);
    return type_node->type_name.c_str();
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

std::pair<llvm::Value*, llvm::Type*> AST_Node::codegen()
{
    switch (this->type)
    {
    case IDENTIFIER_NODE_TYPE:
    {
        std::string name = get_name_id(this);
        llvm::Value *ptr = NamedValues[name];
        llvm::Type *varType = NamedTypes[name];
        return {Builder->CreateLoad(varType, ptr, name),varType};
    }
    case ARRAY_ACCESS:
    {
        std::string array_name = get_name_id(this->children[0]);
        llvm::Value *arrayPointer = NamedValues[array_name];
        llvm::Type *elementType = NamedTypes[array_name];
        const auto &arrayInfo = Arrays[array_name];
        llvm::Value *flatIndex = this->children[1]->children[0]->codegen().first;
        for (size_t i = 1; i < this->children[1]->children.size(); i++) {
            llvm::Value *dimIndex = this->children[1]->children[i]->codegen().first;
            llvm::Value *dimSize = arrayInfo.dimensions[i];
            flatIndex = Builder->CreateMul(flatIndex, dimSize, "multDim");
            flatIndex = Builder->CreateAdd(flatIndex, dimIndex, "flatIndex");
        }
        llvm::Value *elementPointer = Builder->CreateGEP(elementType, arrayPointer, flatIndex, "elementPointer");
        return {Builder->CreateLoad(elementType, elementPointer, "loadArrayElement"), elementType};
    }
    case RECORD_ACCESS: {
        std::string recordName = get_name(this);
        llvm::Value* recordPtr = NamedValues[recordName];
        llvm::StructType* recordType = llvm::dyn_cast<llvm::StructType>(NamedTypes[recordName]);
        AST_Node* currentNode = this;
        llvm::Value* currentPtr = recordPtr;
        llvm::Type* currentType = recordType;
        while (currentNode->children.size() > 1) {
            std::string fieldName ="";
            if(currentNode->children[1]->type==RECORD_ACCESS){
                 fieldName = get_name(currentNode->children[1]);
            }
            else{
                fieldName = get_name_id(currentNode->children[1]);
            }
            const auto& fields = Records[get_name(currentNode)];
            int fieldIndex = -1;
            llvm::Type* fieldType = nullptr;
            for (unsigned i = 0; i < fields.size(); ++i) {
                if (fields[i].name == fieldName) {
                    fieldIndex = i;
                    fieldType = fields[i].type;
                    break;
                }
            }
            llvm::Value* fieldPtr = Builder->CreateStructGEP(currentType, currentPtr, fieldIndex, "fieldPtr");
            if (llvm::isa<llvm::StructType>(fieldType)) {
                currentNode = currentNode->children[1];
                currentPtr=fieldPtr;
                currentType = llvm::dyn_cast<llvm::StructType>(fieldType);
            } else {
                llvm::Value* fieldValue = Builder->CreateLoad(fieldType, fieldPtr, "fieldValue");
                return {fieldValue,fieldType};
            }
        }
    }
    case INTEGER_NODE:
    {
        return {llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), static_cast<Integer_Node *>(this)->val),
          llvm::Type::getInt32Ty(*TheContext)};
    }
    case REAL_NODE:
    {
        return {llvm::ConstantFP::get(llvm::Type::getDoubleTy(*TheContext), static_cast<Real_Node *>(this)->val),
        llvm::Type::getDoubleTy(*TheContext)};
    }
    case BOOLEAN_NODE:
    {
        return {llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), static_cast<Boolean_Node *>(this)->val ? 1 : 0),
        llvm::Type::getInt1Ty(*TheContext)};
    }
    case PRIMARY_EXPRESSION:
    {
        if (this->children.size() == 2)
        {
            std::pair<llvm::Value*, llvm::Type*> x = this->children[1]->codegen();
            return {llvm::BinaryOperator::CreateNot(x.first, "not"),x.second};
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
        if (this->children.size() == 1) {
            return this->children[0]->codegen();
        }
        auto leftChild = this->children[0]->codegen(); 
        auto rightChild = this->children[2]->codegen();
        std::string op = get_op(this->children[1]);
        llvm::Value *leftValue = leftChild.first;
        llvm::Value *rightValue = rightChild.first;
        llvm::Type *leftType = leftChild.second;
        llvm::Type *rightType = rightChild.second;
        if (leftType != rightType) {
            if (leftType->isIntegerTy(32) && rightType->isDoubleTy()) {
                leftValue = Builder->CreateSIToFP(leftValue, rightType, "intToReal");
                leftType = rightType;
            }
            else if (leftType->isDoubleTy() && rightType->isIntegerTy(32)) {
                rightValue = Builder->CreateSIToFP(rightValue, leftType, "intToReal");
                rightType = leftType;
            }
            else if (leftType->isIntegerTy(1) && rightType->isIntegerTy(32)) {
                rightValue = Builder->CreateICmpNE(rightValue, llvm::ConstantInt::get(rightType, 0), "intToBool");
                rightValue = Builder->CreateZExt(rightValue, llvm::Type::getInt1Ty(*TheContext), "zextBool");
                leftType=rightType;
            }
            else if (leftType->isIntegerTy(32) && rightType->isIntegerTy(1)) {
                leftValue = Builder->CreateZExt(leftValue, rightType, "boolToInt");
                rightType = leftType;
            }
            else if (leftType->isDoubleTy() && rightType->isIntegerTy(1)) {
                rightValue = Builder->CreateZExtOrBitCast(rightValue, llvm::Type::getDoubleTy(*TheContext), "boolToDouble");
                rightType = leftType;
            }
            else if (leftType->isIntegerTy(1) && rightType->isDoubleTy()) {
                leftValue = Builder->CreateFCmpONE(leftValue, llvm::ConstantFP::get(leftType, 0.0), "doubleToBool");
                leftValue = Builder->CreateZExt(leftValue, llvm::Type::getInt1Ty(*TheContext), "doubleToBoolExt");
                leftType = rightType;
            }
        }
        if (leftType->isIntegerTy(1) || rightType->isIntegerTy(1)) {
            if (op == "and" || op == "or" || op == "xor") {
                if (!leftType->isIntegerTy(1)) {
                    leftValue = Builder->CreateICmpNE(leftValue, llvm::ConstantInt::get(leftType, 0), "toBool");
                    leftValue = Builder->CreateZExt(leftValue, llvm::Type::getInt1Ty(*TheContext), "zextBool");
                }
                if (!rightType->isIntegerTy(1)) {
                    rightValue = Builder->CreateICmpNE(rightValue, llvm::ConstantInt::get(rightType, 0), "toBool");
                    rightValue = Builder->CreateZExt(rightValue, llvm::Type::getInt1Ty(*TheContext), "zextBool");
                }
            }
        }
        if (leftType == rightType) {
            if (leftType->isIntegerTy(32)) {
            if (op == "+") return {Builder->CreateAdd(leftValue, rightValue, "intAdd"), leftType};
            if (op == "-") return {Builder->CreateSub(leftValue, rightValue, "intSub"), leftType};
            if (op == "*") return {Builder->CreateMul(leftValue, rightValue, "intMul"), leftType};
            if (op == "/") return {Builder->CreateSDiv(leftValue, rightValue, "intDiv"), leftType};
            if (op == "%") return {Builder->CreateSRem(leftValue, rightValue, "intMod"), leftType};
            if (op == "=") return {Builder->CreateICmpEQ(leftValue, rightValue, "intEq"), llvm::Type::getInt1Ty(*TheContext)};
            if (op == "<") return {Builder->CreateICmpSLT(leftValue, rightValue, "intLT"), llvm::Type::getInt1Ty(*TheContext)};
            if (op == "<=") return {Builder->CreateICmpSLE(leftValue, rightValue, "intLE"), llvm::Type::getInt1Ty(*TheContext)};
            if (op == ">") return {Builder->CreateICmpSGT(leftValue, rightValue, "intGT"), llvm::Type::getInt1Ty(*TheContext)};
            if (op == ">=") return {Builder->CreateICmpSGE(leftValue, rightValue, "intGE"), llvm::Type::getInt1Ty(*TheContext)};
        } 
        else if (leftType->isDoubleTy()) {
            if (op == "+") return {Builder->CreateFAdd(leftValue, rightValue, "realAdd"), leftType};
            if (op == "-") return {Builder->CreateFSub(leftValue, rightValue, "realSub"), leftType};
            if (op == "*") return {Builder->CreateFMul(leftValue, rightValue, "realMul"), leftType};
            if (op == "/") return {Builder->CreateFDiv(leftValue, rightValue, "realDiv"), leftType};
            if (op == "=") return {Builder->CreateFCmp(llvm::CmpInst::FCMP_OEQ, leftValue, rightValue, "realEq"), llvm::Type::getInt1Ty(*TheContext)};
            if (op == "<") return {Builder->CreateFCmp(llvm::CmpInst::FCMP_OLT, leftValue, rightValue, "realLT"), llvm::Type::getInt1Ty(*TheContext)};
            if (op == "<=") return {Builder->CreateFCmp(llvm::CmpInst::FCMP_OLE, leftValue, rightValue, "realLE"), llvm::Type::getInt1Ty(*TheContext)};
            if (op == ">") return {Builder->CreateFCmp(llvm::CmpInst::FCMP_OGT, leftValue, rightValue, "realGT"), llvm::Type::getInt1Ty(*TheContext)};
            if (op == ">=") return {Builder->CreateFCmp(llvm::CmpInst::FCMP_OGE, leftValue, rightValue, "realGE"), llvm::Type::getInt1Ty(*TheContext)};
        } 
        else if (leftType->isIntegerTy(1)) {
            if (op == "and") return {Builder->CreateAnd(leftValue, rightValue, "boolAnd"), leftType};
            if (op == "or") return {Builder->CreateOr(leftValue, rightValue, "boolOr"), leftType};
            if (op == "xor") return {Builder->CreateXor(leftValue, rightValue, "boolXor"), leftType};
            if (op == "+") return {Builder->CreateAdd(leftValue, rightValue, "intAdd"), leftType};
            if (op == "-") return {Builder->CreateSub(leftValue, rightValue, "intSub"), leftType};
            if (op == "*") return {Builder->CreateMul(leftValue, rightValue, "intMul"), leftType};
            if (op == "/") return {Builder->CreateSDiv(leftValue, rightValue, "intDiv"), leftType};
            if (op == "=") return {Builder->CreateICmpEQ(leftValue, rightValue, "boolEq"), llvm::Type::getInt1Ty(*TheContext)};
            if (op == "<") return {Builder->CreateICmpSLT(leftValue, rightValue, "boolLT"), llvm::Type::getInt1Ty(*TheContext)};
            if (op == "<=") return {Builder->CreateICmpSLE(leftValue, rightValue, "boolLE"), llvm::Type::getInt1Ty(*TheContext)};
            if (op == ">") return {Builder->CreateICmpSGT(leftValue, rightValue, "boolGT"), llvm::Type::getInt1Ty(*TheContext)};
            if (op == ">=") return {Builder->CreateICmpSGE(leftValue, rightValue, "boolGE"), llvm::Type::getInt1Ty(*TheContext)};
        }
        }
    }
    case RETURN_EX:
    {
        AST_Node *expr = this->children[0];
        auto returnValue = expr->codegen();
        return {Builder->CreateRet(returnValue.first),returnValue.second};
    }
    case Routine_Call:
    {
        llvm::Function *function = TheModule->getFunction(get_name_id(this->children[0]));
        std::vector<llvm::Value *> args;
        for (auto child : this->children[1]->children)
        {
            args.push_back(child->codegen().first);
        }
        llvm::Value *callInst = Builder->CreateCall(function, args, get_name_id(this->children[0]) + "_call");
        return {callInst,function->getReturnType()};
    }
    default:
        break;
    }
    return {nullptr,nullptr};
}

llvm::Type *get_type(AST_Node *node)
{   
    Type_Node *type_node = static_cast<Type_Node*>(node);
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
    else if (name=="identifier")
    { 
        return NamedTypes[get_name_id(node->children[0])];
    }
    else{
        return llvm::Type::getInt32Ty(*TheContext);
    }
}

uint64_t calculateRecordSize(const std::string& recordName) {
    uint64_t totalSize = 0;
    for (const auto& field : Records[recordName]) {
        if (llvm::isa<llvm::StructType>(field.type)) {
            std::string nestedRecordName = field.type->getStructName().str();
            totalSize += calculateRecordSize(nestedRecordName);
        } else {
            totalSize += field.sz;
        }
        uint64_t alignment = TheModule->getDataLayout().getABITypeAlignment(field.type);
        totalSize = llvm::alignTo(totalSize, alignment);
    }
    return totalSize;
}

void initializeNestedRecordFields(llvm::Value* parentPtr, llvm::StructType* parentType, const std::vector<recordVariable>& fields) {
    for (unsigned i = 0; i < fields.size(); ++i) {
        const recordVariable& field = fields[i];
        llvm::Value* fieldPtr = Builder->CreateStructGEP(parentType, parentPtr, i, field.name);
        if (llvm::isa<llvm::StructType>(field.type)) {
            const auto& nestedFields = Records[field.type->getStructName().str()];
            initializeNestedRecordFields(fieldPtr, llvm::dyn_cast<llvm::StructType>(field.type), nestedFields);
        } else {
            llvm::Value* initialValue = llvm::Constant::getNullValue(field.type);
            Builder->CreateStore(initialValue, fieldPtr);
        }
    }
}


void Varible_Decleration_code_Gen(AST_Node *node) {
    if (get_type_name(node->children[1]) == "identifier" && 
        Arrays.count(get_name_id(node->children[1]->children[0]))) {
        auto arrayInfo = Arrays[get_name_id(node->children[1]->children[0])];
        llvm::Value* arraySizeValue = arrayInfo.sz;  
        llvm::Type* elementType = arrayInfo.type;    
        llvm::Function* mallocFunction = TheModule->getFunction("malloc");
        if (!mallocFunction) {
            llvm::FunctionType* mallocType = llvm::FunctionType::get(
                llvm::PointerType::get(llvm::Type::getInt8Ty(*TheContext), 0), 
                { llvm::Type::getInt64Ty(*TheContext) },                      
                false                                    
            );
            mallocFunction = llvm::Function::Create(
                mallocType,
                llvm::Function::ExternalLinkage,
                "malloc",
                *TheModule
            );
        }

        uint64_t elementSize = TheModule->getDataLayout().getTypeAllocSize(elementType);
        llvm::Value* elementSizeValue = llvm::ConstantInt::get(
            llvm::Type::getInt64Ty(*TheContext),
            elementSize
        );

        llvm::Value* totalSize = Builder->CreateMul(
            elementSizeValue,
            arraySizeValue,
            "total_array_size"
        );

        llvm::Value* mallocCall = Builder->CreateCall(
            mallocFunction,
            { totalSize },
            "malloc_call"
        );

        llvm::Value* arrayPointer = Builder->CreateBitCast(
            mallocCall,
            llvm::PointerType::get(elementType, 0),
            "array_ptr"
        );

        NamedValues[get_name(node)] = arrayPointer;
        NamedTypes[get_name(node)] = elementType;
        Arrays[get_name(node)] = arrayInfo;
    }
    else if (get_type_name(node->children[1]) == "identifier" &&
     Records.count(get_name_id(node->children[1]->children[0]))) {
        std::string recordTypeName = get_name(node->children[1]);
        std::string recordName = get_name(node);
        llvm::Type* recordType = RecordsTypes[recordTypeName];
        llvm::Value* recordAlloc = Builder->CreateAlloca(recordType, nullptr, recordName);
        NamedValues[recordName] = recordAlloc;
        NamedTypes[recordName] = recordType;
        Records[recordName] = Records[recordTypeName];
        initializeNestedRecordFields(recordAlloc, llvm::dyn_cast<llvm::StructType>(recordType), Records[recordTypeName]);
    } else {
        std::string name = get_name(node);
        llvm::Type* varType = get_type(node->children[1]);
        llvm::Value* varAlloc = Builder->CreateAlloca(varType, nullptr, name);

        llvm::Value* initialValue = nullptr;
        if (node->children.size() > 2) {
            initialValue = node->children[2]->codegen().first;
        } else {
            initialValue = llvm::Constant::getNullValue(varType);
        }

        Builder->CreateStore(initialValue, varAlloc);
        NamedValues[name] = varAlloc;
        NamedTypes[name] = varType;
    }
}
void Assign_code_gen(AST_Node *node)
{
    llvm::Type *leftType = nullptr;
    llvm::Value *leftChild = nullptr;
    if (node->children[0]->children[0]->type == ARRAY_ACCESS) {
        std::string array_name = get_name_id(node->children[0]->children[0]->children[0]);
        llvm::Value *arrayPointer = NamedValues[array_name];
        llvm::Type *elementType = NamedTypes[array_name];
        auto arrayInfo = Arrays[array_name];
        llvm::Value *flatIndex = node->children[0]->children[0]->children[1]->children[0]->codegen().first;
        for (size_t i = 1; i < node->children[0]->children[0]->children[1]->children.size(); i++) {
            llvm::Value *dimIndex = node->children[0]->children[0]->children[1]->children[i]->codegen().first;
            llvm::Value *dimSize = arrayInfo.dimensions[i];
            flatIndex = Builder->CreateMul(flatIndex, dimSize, "multDim");
            flatIndex = Builder->CreateAdd(flatIndex, dimIndex, "flatIndex");
        }
        llvm::Value *elementPointer = Builder->CreateGEP(elementType, arrayPointer, flatIndex, "elementPointer");
        leftChild= elementPointer;
        leftType = elementType;
    }
    else if (node->children[0]->children[0]->type == RECORD_ACCESS) {
        AST_Node* leftNode = node->children[0]->children[0];
        std::string recordName = get_name(leftNode);
        llvm::Value* recordPtr = NamedValues[recordName];
        llvm::StructType* recordType = llvm::dyn_cast<llvm::StructType>(NamedTypes[recordName]);
        AST_Node* currentNode = leftNode;
        llvm::Value* currentPtr = recordPtr;
        llvm::Type* currentType = recordType;

        while (currentNode->children.size() > 1) {
            std::string fieldName = (currentNode->children[1]->type == RECORD_ACCESS) ? get_name(currentNode->children[1]) : get_name_id(currentNode->children[1]);
            const auto& fields = Records[get_name(currentNode)];
            int fieldIndex = -1;
            llvm::Type* fieldType = nullptr;
            for (unsigned i = 0; i < fields.size(); ++i) {
                if (fields[i].name == fieldName) {
                    fieldIndex = i;
                    fieldType = fields[i].type;
                    break;
                }
            }

            llvm::Value* fieldPtr = Builder->CreateStructGEP(currentType, currentPtr, fieldIndex, "fieldPtr");

            if (llvm::isa<llvm::StructType>(fieldType)) {
                currentNode = currentNode->children[1];
                currentPtr = fieldPtr;
                currentType = llvm::dyn_cast<llvm::StructType>(fieldType);
            } else {
                leftChild = fieldPtr;
                leftType = fieldType;
                break;
            }
        }
    }
    else {
        std::string name = get_name(node->children[0]->children[0]);
        leftChild = NamedValues[name];
        leftType=NamedTypes[name];
    }
    llvm::Value *rightChild = node->children[2]->codegen().first;
    llvm::Type* rightType = node->children[2]->codegen().second;
    if (leftType != rightType) {
        if (leftType->isIntegerTy(32) && rightType->isDoubleTy()) {
            rightChild = Builder->CreateFPToSI(rightChild, leftType, "fpToInt");
        }
        else if (leftType->isDoubleTy() && rightType->isIntegerTy(32)) {
            rightChild = Builder->CreateSIToFP(rightChild, leftType, "intToFP");
        }
        else if (leftType->isIntegerTy(1) && rightType->isIntegerTy(32)) {
            rightChild = Builder->CreateICmpNE(rightChild, llvm::ConstantInt::get(rightType, 0), "intToBool");
            rightChild = Builder->CreateZExt(rightChild, leftType, "intToBoolExt");
        }
        else if (leftType->isIntegerTy(32) && rightType->isIntegerTy(1)) {
            rightChild = Builder->CreateZExt(rightChild, leftType, "boolToInt");
        }
        else if (leftType->isDoubleTy() && rightType->isIntegerTy(1)) {
            rightChild = Builder->CreateZExtOrBitCast(rightChild, llvm::Type::getDoubleTy(*TheContext), "boolToDouble");
        }
        else if (leftType->isIntegerTy(1) && rightType->isDoubleTy()) {
            rightChild = Builder->CreateFCmpONE(rightChild, llvm::ConstantFP::get(rightType, 0.0), "doubleToBool");
            rightChild = Builder->CreateZExt(rightChild, leftType, "doubleToBoolExt");
        }
    }

    std::string op = get_op(node->children[1]);
    if (op == ":=") {
        Builder->CreateStore(rightChild, leftChild);
    }
}

void If_statement_code_gen(AST_Node *node)
{
    llvm::Value *CondV = node->children[0]->codegen().first;
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
    llvm::Value *CondV = node->children[0]->codegen().first;

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

    llvm::Value *cond = node->children[0]->codegen().first;
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

    llvm::Value *start_value = node->children[1]->children[0]->codegen().first;
    llvm::Value *end_value = node->children[1]->children[1]->codegen().first;
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
    AST_Node *dimensionListNode = typeNode->children[0];
    llvm::Value *totalSize = llvm::ConstantInt::get(llvm::Type::getInt64Ty(*TheContext), 1);
    std::vector<llvm::Value*>v;
    for (AST_Node *dim : dimensionListNode->children) {
        llvm::Value *dimSize = dim->codegen().first;
        v.push_back(dimSize);
        totalSize = Builder->CreateMul(totalSize, dimSize, "totalSize");
    }
    ArrayTypes arrayType ;
    arrayType.sz=totalSize;
    arrayType.type=llvmType;
    arrayType.dimensions=v;
    Arrays[get_name_id(identifierNode)] = arrayType;
}

void Type_Declaration_Record_codgen(AST_Node* node) {
    std::string recordName = get_name(node);
    std::vector<llvm::Type*> memberTypes;
    AST_Node* fieldListNode = node->children[1]->children[0]->children[0];

    for (const auto& fieldNode : fieldListNode->children) {
        memberTypes.push_back(get_type(fieldNode->children[1]));
    }

    auto recordType = llvm::StructType::create(*TheContext, memberTypes, recordName, false);
    RecordsTypes[recordName] = recordType;

    std::vector<recordVariable> fieldVariables;
    for (const auto& fieldNode : fieldListNode->children) {
        recordVariable fieldVar;
        fieldVar.name = get_name(fieldNode);
        fieldVar.type = get_type(fieldNode->children[1]);

        if (llvm::isa<llvm::StructType>(fieldVar.type)) {
            fieldVar.sz = calculateRecordSize(fieldVar.type->getStructName().str());
            Records[fieldVar.name] = Records[get_name(fieldNode->children[1])];
        } else {
            fieldVar.sz = TheModule->getDataLayout().getTypeAllocSize(fieldVar.type);
        }

        fieldVariables.push_back(fieldVar);
    }

    Records[recordName] = fieldVariables;
    NamedTypes[recordName] = recordType;
}

void Type_Declaration_codegen(AST_Node *node)
{
    if (get_type_name(node->children[1]) == "integer" || get_type_name(node->children[1]) == "real" || get_type_name(node->children[1]) == "boolean")
    {
        Type_Declaration_primitive_type_codegen(node);
    }
    else if (get_type_name(node->children[1]) == "arrayType")
    {
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
        if (llvm::isa<llvm::StructType>(get_type(params->children[idx]->children[1]))) {
            Records[paramName] = Records[get_name(params->children[idx]->children[1])];
        }
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
    llvm::Value *exprValue = expression->codegen().first;
    llvm::Type *exprType = expression->codegen().second;
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