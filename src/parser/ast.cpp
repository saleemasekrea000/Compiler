#include <stdlib.h>
#include <stdio.h>
#include "ast.hpp"
#include "lexer_2.hpp"
#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/FileSystem.h"
#include <memory>

static std::unique_ptr<llvm::LLVMContext> TheContext;
static std::unique_ptr<llvm::IRBuilder<>> Builder;
static std::unique_ptr<llvm::Module> TheModule;
static std::map<std::string, llvm::Value *> NamedValues;
static std::map<std::string, llvm::Type *> NamedTypes;
static std::map<std::string, std::pair<llvm::Value*, llvm::Type*>>Arrays;
static const std::unordered_map<Node_Type, std::string> type_map = {
    {PROGRAM, "Program"},
    {DECLARATION, "Declarations"},
    {SIMPLE_DECLARATION, "Simple declaration"},
    {VARIABLE_DECLARATION, "Variable declaration"},
    {PRIMARY_EXPRESSION, "Primary expresson"},
    {PRIMARY_NODE, "Primary node"},
    {ARRAY_ACCESS, "Array access"},
    {RECORD_ACCESS, "Record access"},
    {SUMMAND, "Summand"},
    {FACTOR, "Factor"},
    {SIMPLE, "Simple"},
    {RELATION, "Relation"},
    {EXPRESSION, "Expression"},
    {TYPE_DECLARATION, "Type declaration"},
    {ARRAY_TYPE, "Array type"},
    {RECORD_TYPE, "Record type"},
    {VARIABLE_DECLARATIONS, "Variable Declarations"},
    {STATEMENT, "Statement"},
    {ITERATION_STATEMENT, "Iteration statement"},
    {WHILE_STATEMENT, "While statement"},
    {BODY, "Body"},
    {FOR_STATEMENT, "For statement"},
    {RANGE_EX, "Range"},
    {RANGE_REVERSE, "Range reverse"},
    {ASSIGN_STATEMENT, "Assignment statement"},
    {IF_STATEMENT, "if statement"},
    {IF_STATEMENT_ELSE, "if and else statement"},
    {JUMP_STATEMENT, "Jump Statement"},
    {RETURN_EX, "Return"},
    {CONTINUE_EX, "Continue"},
    {BREAK_EX, "Break"},
    {Routine_Call, "Routine Call"},
    {Argument_Expression_List, "Arguments Expression List"},
    {PARAMETER_DECLERATION, "Parameter Decleration"},
    {PARAMETERS_EXPRESSION_LIST, "Parameters Expression List"},
    {ROUTINE_DECLERATION, "Routine Decleration"},
    {PRINT_STATMENT, "PRINT"},
};

void print_ast_helper(AST_Node *node, int indent, FILE *output_file)
{
    if (!node)
    {
        return;
    }

    for (int i = 0; i < indent; i++)
    {
        fprintf(output_file, "  ");
    }
    if (type_map.find(node->type) != type_map.end())
    {
        fprintf(output_file, "%s\n", type_map.at(node->type).c_str());
    }
    else
    {
        switch (node->type)
        {
        case IDENTIFIER_NODE_TYPE:
        {
            Identifier_Node *Identifier_node = static_cast<Identifier_Node *>(node);
            fprintf(output_file, "Identifier: %s\n", Identifier_node->identifier_name.c_str());
            break;
        }
        case TYPE_NODE:
        {
            Type_Node *type_node = static_cast<Type_Node *>(node);
            fprintf(output_file, "Type: %s\n", type_node->type_name.c_str());
            break;
        }
        case BOOLEAN_NODE:
        {
            Boolean_Node *boolean_node = static_cast<Boolean_Node *>(node);
            fprintf(output_file, "Boolean: %s\n", (boolean_node->val ? "true" : "false"));
            break;
        }
        case INTEGER_NODE:
        {
            Integer_Node *integer_node = static_cast<Integer_Node *>(node);
            fprintf(output_file, "Integer: %d\n", integer_node->val);
            break;
        }
        case REAL_NODE:
        {
            Real_Node *real_node = static_cast<Real_Node *>(node);
            fprintf(output_file, "Real: %f\n", real_node->val);
            break;
        }
        case OPERATOR:
        {
            Operator *op_node = static_cast<Operator *>(node);
            fprintf(output_file, "Operator: %s\n", op_node->operation_name.c_str());
            break;
        }
        default:
            fprintf(output_file, "Unknown Node Type\n");
            break;
        }
    }
    for (const auto &child : node->children)
    {
        print_ast_helper(child, indent + 1, output_file);
    }
}

void print_ast(AST_Node *node, int indent, const std::string &file_name)
{
    FILE *file = fopen(file_name.c_str(), "w");
    print_ast_helper(node, indent, file);
    fclose(file);
}

Identifier_Node *getIdentifierNode(AST_Node *node)
{
    if (!node)
        return nullptr;

    if (!node->children.empty() && node->children[0]->type == IDENTIFIER_NODE_TYPE)
    {
        return static_cast<Identifier_Node *>(node->children[0]);
    }
    return nullptr;
}

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
bool checkRoutineDeclarations(AST_Node *node, std::unordered_set<std::string> &declaredRoutineNames)
{
    if (node->type == ROUTINE_DECLERATION)
    {
        Identifier_Node *identifierNode = getIdentifierNode(node);
        if (identifierNode)
        {
            declaredRoutineNames.insert(identifierNode->identifier_name);
        }
    }
    else if (node->type == Routine_Call)
    {
        if (!node->children.empty() && node->children[0]->type == IDENTIFIER_NODE_TYPE)
        {
            Identifier_Node *identifierNode = static_cast<Identifier_Node *>(node->children[0]);
            return declaredRoutineNames.count(identifierNode->identifier_name) > 0;
        }
    }

    for (AST_Node *child : node->children)
    {
        if (!checkRoutineDeclarations(child, declaredRoutineNames))
        {
            return false;
        }
    }

    return true;
}

bool checkVariableDeclarations(AST_Node *node, std::unordered_set<std::string> declaredVariableNames)
{
    if (!node)
        return true;
    if (node->type == IDENTIFIER_NODE_TYPE)
    {
        if (declaredVariableNames.size() == 0)
        {
            return 0;
        }
        if (declaredVariableNames.find(get_name_id(node)) == declaredVariableNames.end())
        {
            return false;
        }
    }
    bool ans = true;
    for (int i = 0; i < node->children.size(); i++)
    {
        AST_Node *child = node->children[i];
        if (child->type == SIMPLE_DECLARATION && child->children[0]->type == VARIABLE_DECLARATION)
        {
            AST_Node *grand = child->children[0];
            if (grand->children.size() >= 3)
                ans &= checkVariableDeclarations(grand->children[2], declaredVariableNames);
            declaredVariableNames.insert(get_name(grand));
            continue;
        }
        if (child->type == SIMPLE_DECLARATION && child->children[0]->type == TYPE_DECLARATION)
        {
            AST_Node *grand = child->children[0];
            if (grand->children.size() >= 3)
                ans &= checkVariableDeclarations(grand->children[2], declaredVariableNames);
            continue;
        }
        if (child->type == ROUTINE_DECLERATION)
        {
            AST_Node *grand = child->children[1];
            // printf("%s\n", type_map.at(child->type).c_str());
            for (int j = 0; j < grand->children.size(); j++)
            {
                declaredVariableNames.insert(get_name(grand->children[j]));
            }
            ans &= checkVariableDeclarations(child->children[2], declaredVariableNames);
            continue;
        }
        if (child->type == Routine_Call)
        {
            ans &= checkVariableDeclarations(child->children[1], declaredVariableNames);
            continue;
        }
        if (child->type == FOR_STATEMENT)
        {
            declaredVariableNames.insert(get_name_id(child->children[0]));
            ans &= checkVariableDeclarations(child->children[1], declaredVariableNames);
            ans &= checkVariableDeclarations(child->children[2], declaredVariableNames);
            continue;
        }
        ans &= checkVariableDeclarations(child, declaredVariableNames);
    }
    return ans;
}

bool checkTypeDeclarations(AST_Node *node, std::unordered_set<std::string> declaredTypeNames)
{
    if (!node)
        return true;
    if (node->type == TYPE_NODE && node->children.size() > 0 && node->children[0]->type == IDENTIFIER_NODE_TYPE)
    {
        if (declaredTypeNames.size() == 0)
        {
            return false;
        }
        if (declaredTypeNames.find(get_name_id(node->children[0])) == declaredTypeNames.end())
        {
            return false;
        }
    }
    bool ans = true;
    for (int i = 0; i < node->children.size(); i++)
    {
        AST_Node *child = node->children[i];
        if (child->type == SIMPLE_DECLARATION && child->children[0]->type == TYPE_DECLARATION)
        {
            AST_Node *grand = child->children[0];
            declaredTypeNames.insert(get_name_id(grand->children[0]));
            continue;
        }
        ans &= checkTypeDeclarations(child, declaredTypeNames);
    }
    return ans;
}
bool check_return(AST_Node *node, bool inside_function)
{
    if (node->type == RETURN_EX && !inside_function)
    {
        return 0;
    }
    bool cur_inside = inside_function;
    if (node->type == ROUTINE_DECLERATION)
    {
        cur_inside = 1;
    }
    bool ans = 1;
    for (const auto &child : node->children)
    {
        ans &= check_return(child, cur_inside);
    }
    return ans;
}
bool check_continue(AST_Node *node, bool inside_loop)
{
    if (node->type == CONTINUE_EX && !inside_loop)
    {
        return 0;
    }
    bool cur_inside = inside_loop;
    if (node->type == ITERATION_STATEMENT)
    {
        cur_inside = 1;
    }
    bool ans = 1;
    for (const auto &child : node->children)
    {
        ans &= check_continue(child, cur_inside);
    }
    return ans;
}
bool check_break(AST_Node *node, bool inside_loop)
{
    if (node->type == BREAK_EX && !inside_loop)
    {
        return 0;
    }
    bool cur_inside = inside_loop;
    if (node->type == ITERATION_STATEMENT)
    {
        cur_inside = 1;
    }
    bool ans = 1;
    for (const auto &child : node->children)
    {
        ans &= check_break(child, cur_inside);
    }
    return ans;
}

void Semantic_Analysis_Checks(AST_Node *root)
{
    std::unordered_set<std::string> declaredVariableNames;
    std::unordered_set<std::string> declaredRoutineNames;
    std::unordered_set<std::string> declaredTypesNames;
    if (!check_return(root, 0))
    {
        printf("Return statement exist outside of a function\n");
        return;
    }
    if (!check_continue(root, 0))
    {
        printf("Continue statement exist outside of a loop\n");
        return;
    }
    if (!check_break(root, 0))
    {
        printf("Break statement exist outside of a loop\n");
        return;
    }

    if (!checkVariableDeclarations(root, declaredVariableNames))
    {
        printf("varible is not deaclerd \n");
        return;
    }
    if (!checkRoutineDeclarations(root, declaredRoutineNames))
    {
        printf("function is not deaclerd \n");
        return;
    }
    if (!checkTypeDeclarations(root, declaredTypesNames))
    {
        printf("A type is not deaclerd\n");
    }
}

void remove_unreachable_code(AST_Node *node)
{
    if (!node)
    {
        return;
    }
    int cnt = 1e9;
    for (int i = 0; i < (node->children).size(); i++)
    {
        if ((node->children)[i]->type == STATEMENT &&
            ((node->children)[i]->children).size() > 0 &&
            (node->children)[i]->children[0]->type == JUMP_STATEMENT)
        {
            cnt = i;
            break;
        }
    }
    cnt++;
    while ((node->children).size() > cnt)
    {
        (node->children).pop_back();
    }
    for (const auto &child : node->children)
    {
        remove_unreachable_code(child);
    }
}

bool used_routine(AST_Node *node, std::string function_name)
{
    if (node && node->type == Routine_Call && get_name(node) == function_name)
        return 1;
    bool ans = false;
    for (const auto &child : node->children)
    {
        ans |= used_routine(child, function_name);
    }
    return ans;
}
void remove_unused_routines(AST_Node *node)
{
    if (!node)
        return;
    int childrenNumber = node->children.size();
    std::vector<AST_Node *> curChildren;
    for (int i = 0; i < childrenNumber; i++)
    {
        AST_Node *child = node->children[i];
        if (child->type != ROUTINE_DECLERATION)
        {
            curChildren.push_back(child);
            continue;
        }
        bool add = false;
        std::string routine_name = get_name(child);
        for (int j = i + 1; j < childrenNumber; j++)
        {
            if (used_routine(node->children[j], routine_name))
                add = true;
        }
        if (add)
        {
            curChildren.push_back(child);
        }
    }
    node->children.clear();
    if (curChildren.size() > 0)
    {
        node->children = curChildren;
    }
    for (const auto &child : node->children)
    {
        remove_unused_routines(child);
    }
}
bool used_var(AST_Node *node, std::string var_name, bool inside_expression)
{
    if (!node)
        return false;
    if (node->type == IDENTIFIER_NODE_TYPE)
    {
        return (get_name_id(node) == var_name && inside_expression);
    }
    if (node->type == SIMPLE_DECLARATION)
    {
        AST_Node *child = node->children[0];
        if (child->type == VARIABLE_DECLARATION && get_name(child) == var_name)
            return used_var(child->children[2], var_name, true);
    }
    if (node->type == ROUTINE_DECLERATION)
    {
        if (get_name(node) == var_name)
            return 0;
        AST_Node *params_node = node->children[1];
        for (const auto &param : params_node->children)
        {
            if (get_name(param) == var_name)
                return 0;
        }
    }
    if (node->type == FOR_STATEMENT && get_name(node) == var_name)
        return 0;
    bool ans = false;
    if (node->type == EXPRESSION)
        inside_expression = true;
    for (const auto &child : node->children)
    {
        ans |= used_var(child, var_name, inside_expression);
    }
    return ans;
}
std::string get_name_assign(AST_Node *node)
{
    if (node->type != ASSIGN_STATEMENT)
        return "";
    AST_Node *primary_node = node->children[0];
    if (primary_node->type != PRIMARY_NODE)
        return "";
    AST_Node *primary_exp_node = primary_node->children[0];
    if (primary_exp_node->type != PRIMARY_EXPRESSION)
        return "";
    AST_Node *id_node = primary_exp_node->children[0];
    if (id_node->type != IDENTIFIER_NODE_TYPE)
        return "";
    return get_name_id(id_node);
}
void remove_assignment(AST_Node *node, std::string var_name)
{
    if (!node)
        return;
    if (node->type == VARIABLE_DECLARATION && get_name(node) == var_name)
        return;
    int childrenNumber = node->children.size();
    std::vector<AST_Node *> curChildren;
    for (int i = 0; i < childrenNumber; i++)
    {
        AST_Node *child = node->children[i];
        if (child->type != STATEMENT)
        {
            curChildren.push_back(child);
            continue;
        }
        AST_Node *grand = child->children[0];
        if (grand->type != ASSIGN_STATEMENT)
        {
            curChildren.push_back(child);
            continue;
        }
        if (get_name_assign(grand) != var_name)
        {
            curChildren.push_back(child);
        }
    }
    node->children.clear();
    if (curChildren.size() > 0)
    {
        node->children = curChildren;
    }
    for (const auto &child : node->children)
    {
        remove_assignment(child, var_name);
    }
}
void remove_unused_varible(AST_Node *node)
{
    if (!node)
        return;
    int childrenNumber = node->children.size();
    std::vector<AST_Node *> curChildren;
    for (int i = 0; i < childrenNumber; i++)
    {
        AST_Node *child = node->children[i];
        if (child->type != SIMPLE_DECLARATION)
        {
            curChildren.push_back(child);
            continue;
        }
        AST_Node *grand = child->children[0];
        if (grand->type != VARIABLE_DECLARATION)
        {
            curChildren.push_back(child);
            continue;
        }
        bool add = false;
        std::string var_name = get_name(grand);
        for (int j = i + 1; j < childrenNumber; j++)
        {
            add |= used_var(node->children[j], var_name, false);
        }
        if (add)
            curChildren.push_back(child);
        else
        {
            for (int j = i + 1; j < childrenNumber; j++)
            {
                /// remove_assignment(node->children[j],var_name);
            }
        }
    }
    node->children.clear();
    if (curChildren.size() > 0)
    {
        node->children = curChildren;
    }
    for (const auto &child : node->children)
    {
        remove_unused_varible(child);
    }
}
std::string get_type_name(AST_Node *node)
{
    Type_Node *type_node = static_cast<Type_Node *>(node);
    return type_node->type_name.c_str();
}
bool used_type(AST_Node *node, std::string type_name)
{
    if (!node)
        return false;
    if (node->type == TYPE_NODE)
    {
        return (get_type_name(node) == type_name);
    }
    bool ans = false;
    for (const auto &child : node->children)
    {
        ans |= used_type(child, type_name);
    }
    return ans;
}
void remove_unused_types(AST_Node *node)
{
    if (!node)
        return;
    int childrenNumber = node->children.size();
    std::vector<AST_Node *> curChildren;
    for (int i = 0; i < childrenNumber; i++)
    {
        AST_Node *child = node->children[i];
        if (child->type != SIMPLE_DECLARATION)
        {
            curChildren.push_back(child);
            continue;
        }
        AST_Node *grand = child->children[0];
        if (grand->type != TYPE_DECLARATION)
        {
            curChildren.push_back(child);
            continue;
        }
        bool add = false;
        std::string type_name = get_name(grand);
        for (int j = i + 1; j < childrenNumber; j++)
        {
            add |= used_type(node->children[j], type_name);
        }
        if (add)
            curChildren.push_back(child);
    }
    node->children.clear();
    if (curChildren.size() > 0)
    {
        node->children = curChildren;
    }
    for (const auto &child : node->children)
    {
        remove_unused_types(child);
    }
}
void remove_unused(AST_Node *root)
{
    remove_unused_routines(root);
    remove_unused_varible(root);
    remove_unused_types(root);
}
void optimize(AST_Node *root)
{
    remove_unreachable_code(root);
    remove_unused(root);
}

////////////////////////////////////////////////////////////////////////////////////////////////

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
    case ARRAY_ACCESS: {
        std::string array_name = get_name_id(this->children[0]);
        llvm::Value* arrayPointer = NamedValues[array_name];
        llvm::Value* index = this->children[1]->codegen();
        llvm::Value* elementPointer = Builder->CreateGEP(NamedTypes[array_name],arrayPointer, index);
        return Builder->CreateLoad(NamedTypes[array_name], elementPointer, array_name);
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

void Varible_Decleration_code_Gen(AST_Node *node)
{
    if (get_type_name(node->children[1]) == "identifier" && 
        Arrays.count(get_name_id(node->children[1]->children[0]))) {

        std::pair<llvm::Value*, llvm::Type*> arrayInfo = Arrays[get_name_id(node->children[1]->children[0])];
        llvm::Value* arraySizeValue = arrayInfo.first;  
        llvm::Type* elementType = arrayInfo.second;    

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
    }
    else {
        std::string name = get_name(node);
        llvm::Value* v = Builder->CreateAlloca(get_type(node->children[1]), nullptr, name);
        
        llvm::Value* initial_value = nullptr;
        if (node->children.size() > 2) {
            initial_value = node->children[2]->codegen(); 
        } else {
            initial_value = llvm::Constant::getNullValue(get_type(node->children[1]));
        }
        
        Builder->CreateStore(initial_value, v);
        NamedValues[name] = v;
        NamedTypes[name] = get_type(node->children[1]);
    }
}

void Assign_code_gen(AST_Node *node){
    llvm::Value *leftChild=nullptr;
    if(node->children[0]->children[0]->type==ARRAY_ACCESS){
       // print_ast(node->children[0]->children[0],0,"output.txt");
        std::string array_name = get_name_id(node->children[0]->children[0]->children[0]);
        llvm::Value* arrayPointer = NamedValues[array_name];
        llvm::Value* index = node->children[0]->children[0]->children[1]->codegen();
        llvm::Value* elementPointer = Builder->CreateGEP(llvm::Type::getInt32Ty(*TheContext),arrayPointer, index);
        leftChild=elementPointer;
    }
    else{
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

void Type_Declaration_primitive_type_codegen(AST_Node* node){
    AST_Node *identifierNode = node->children[0];
    AST_Node *typeNode = node->children[1];
    Identifier_Node *idNode = static_cast<Identifier_Node *>(identifierNode);
    std::string identifierName = idNode->identifier_name;
    llvm::Type *llvmType = get_type(typeNode);
    NamedTypes[identifierName] = llvmType;
}
void Type_Declaration_Array_codegen(AST_Node* node){
    AST_Node *identifierNode = node->children[0];
    AST_Node *typeNode = node->children[1]->children[0];
    llvm::Type* llvmType = get_type(typeNode->children[1]);
    llvm::Value* arraySize= typeNode->children[0]->codegen();
    Arrays[get_name_id(identifierNode)]={arraySize,llvmType};
}

void Type_Declaration_codegen(AST_Node *node)
{
    if(get_type_name(node->children[1])=="integer" 
    || get_type_name(node->children[1])=="real" 
    || get_type_name(node->children[1])=="boolean"){
        Type_Declaration_primitive_type_codegen(node);
    }   
    else if (get_type_name(node->children[1])=="arrayType"){
      Type_Declaration_Array_codegen(node);
    }
    else if (get_type_name(node)=="recordType"){
     //   Type_Declaration_Record_codgen(node);
     return ;
    }
}

void Routine_decleration_code_gen(AST_Node* node) {
    bool hasReturnType = node->children.size() == 4;  
    llvm::FunctionType* funcType;
    llvm::Function* function;
    std::vector<llvm::Type*> paramTypes;
    AST_Node* params = node->children[1]; 

    for (auto& param : params->children) {
        paramTypes.push_back(get_type(param->children[1])); 
    }

    llvm::Type* returnType = nullptr ;
    if (hasReturnType) {
       returnType=get_type(node->children[3]);
    }
    else returnType = llvm::Type::getInt32Ty(*TheContext);

    funcType = llvm::FunctionType::get(returnType, paramTypes, false);
    function = llvm::Function::Create(
        funcType, 
        llvm::Function::ExternalLinkage, 
        get_name_id(node->children[0]), 
        *TheModule
    );

    llvm::BasicBlock* entry = llvm::BasicBlock::Create(*TheContext, "entry", function);
    llvm::IRBuilderBase::InsertPoint savedPoint = Builder->saveIP();
    Builder->SetInsertPoint(entry);

    auto funcArgs = function->args();
    int idx = 0;
    for (auto& arg : funcArgs) {
        std::string paramName = get_name(params->children[idx]);
        llvm::AllocaInst* alloc = Builder->CreateAlloca(get_type(params->children[idx]->children[1]), nullptr, paramName);
        Builder->CreateStore(&arg, alloc);
        NamedValues[paramName] = alloc; 
        NamedTypes[paramName]= get_type(params->children[idx]->children[1]);
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

void PrintNodeCodeGen(AST_Node* printNode) {
    llvm::Function* printfFunc = TheModule->getFunction("printf");
    if (!printfFunc) {
        std::vector<llvm::Type*> printfArgs = { llvm::Type::getInt8PtrTy(*TheContext) };
        llvm::FunctionType* printfType = llvm::FunctionType::get(
            llvm::Type::getInt32Ty(*TheContext), printfArgs, true
        );
        printfFunc = llvm::Function::Create(
            printfType, llvm::Function::ExternalLinkage, "printf", *TheModule
        );
    }
    AST_Node* expression = printNode->children[0];
    llvm::Value* exprValue = expression->codegen(); 
    llvm::Type* exprType = llvm::Type::getInt32Ty(*TheContext);
    llvm::Value* formatStr = nullptr;

    if (exprType->isIntegerTy(32)) {
        formatStr = Builder->CreateGlobalStringPtr("%d\n");
    } else if (exprType->isDoubleTy()) {
        formatStr = Builder->CreateGlobalStringPtr("%f\n");
    } else if (exprType->isIntegerTy(1)) {
        formatStr = Builder->CreateGlobalStringPtr("%d\n"); 
    } else {
        llvm::errs() << "Unsupported type for print statement!\n";
        return;
    }

    // Call printf with the format string and the expression value
    Builder->CreateCall(printfFunc, { formatStr, exprValue });
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
    case PRINT_STATMENT:{
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

void start_llvm(AST_Node *root)
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