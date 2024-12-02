#ifndef AST_H
#define AST_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include "llvm/IR/Value.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"


typedef enum class Node_Type
{
    PROGRAM,
    DECLARATION,
    SIMPLE_DECLARATION,
    IDENTIFIER_NODE_TYPE,
    VARIABLE_DECLARATION,
    VARIABLE_DECLARATIONS,
    TYPE_DECLARATION,
    EXPRESSION,
    STATEMENT,
    ITERATION_STATEMENT,
    WHILE_STATEMENT,
    TYPE_NODE,
    BOOLEAN_NODE,
    INTEGER_NODE,
    REAL_NODE,
    UNARY_OP,
    PRIMARY_EXPRESSION,
    PRIMARY_NODE,
    ARRAY_ACCESS,
    RECORD_ACCESS,
    SUMMAND,
    FACTOR,
    SIMPLE,
    RELATION,
    RECORD_TYPE,
    ARRAY_TYPE,
    INVALID,
    OPERATOR,
    BODY,
    FOR_STATEMENT,
    RANGE_REVERSE,
    RANGE_EX,
    ASSIGN_STATEMENT,
    IF_STATEMENT,
    IF_STATEMENT_ELSE,
    JUMP_STATEMENT,
    RETURN_EX,
    CONTINUE_EX,
    BREAK_EX,
    Routine_Call,
    Argument_Expression_List,
    PARAMETER_DECLERATION,
    PARAMETERS_EXPRESSION_LIST,
    ROUTINE_DECLERATION,
    PRINT_STATMENT,
    DIMENSION_LIST,
} Node_Type;

class AST_Node
{
public:
    enum Node_Type type;
    std::vector<AST_Node *> children;
    AST_Node(Node_Type t) : type(t) {}
    std::pair<llvm::Value*, llvm::Type*>  codegen();
};

class None_Terminal_Node : public AST_Node
{
private:
    static Node_Type str_to_type(const std::string &type_name)
    {
        static const std::unordered_map<std::string, Node_Type> type_map = {
            {"PROGRAM", Node_Type::PROGRAM},
            {"DECLARATION", Node_Type::DECLARATION},
            {"SIMPLE_DECLARATION", Node_Type::SIMPLE_DECLARATION},
            {"VARIABLE_DECLARATION", Node_Type::VARIABLE_DECLARATION},
            {"PRIMARY_EXPRESSION", Node_Type::PRIMARY_EXPRESSION},
            {"PRIMARY_NODE", Node_Type::PRIMARY_NODE},
            {"ARRAY_ACCESS", Node_Type::ARRAY_ACCESS},
            {"RECORD_ACCESS", Node_Type::RECORD_ACCESS},
            {"SUMMAND", Node_Type::SUMMAND},
            {"FACTOR", Node_Type::FACTOR},
            {"SIMPLE", Node_Type::SIMPLE},
            {"RELATION", Node_Type::RELATION},
            {"EXPRESSION", Node_Type::EXPRESSION},
            {"TYPE_DECLARATION", Node_Type::TYPE_DECLARATION},
            {"ARRAY_TYPE", Node_Type::ARRAY_TYPE},
            {"RECORD_TYPE", Node_Type::RECORD_TYPE},
            {"VARIABLE_DECLARATIONS", Node_Type::VARIABLE_DECLARATIONS},
            {"STATEMENT", Node_Type::STATEMENT},
            {"ITERATION_STATEMENT", Node_Type::ITERATION_STATEMENT},
            {"WHILE_STATEMENT", Node_Type::WHILE_STATEMENT},
            {"BODY", Node_Type::BODY},
            {"FOR_STATEMENT", Node_Type::FOR_STATEMENT},
            {"RANGE_EX", Node_Type::RANGE_EX},
            {"RANGE_REVERSE", Node_Type::RANGE_REVERSE},
            {"ASSIGN_STATEMENT", Node_Type::ASSIGN_STATEMENT},
            {"IF_STATEMENT", Node_Type::IF_STATEMENT},
            {"IF_STATEMENT_ELSE", Node_Type::IF_STATEMENT_ELSE},
            {"JUMP_STATEMENT", Node_Type::JUMP_STATEMENT},
            {"RETURN_EX", Node_Type::RETURN_EX},
            {"CONTINUE_EX", Node_Type::CONTINUE_EX},
            {"BREAK_EX", Node_Type::BREAK_EX},
            {"Routine_Call", Node_Type::Routine_Call},
            {"Argument_Expression_List", Node_Type::Argument_Expression_List},
            {"PARAMETER_DECLERATION", Node_Type::PARAMETER_DECLERATION},
            {"PARAMETERS_EXPRESSION_LIST", Node_Type::PARAMETERS_EXPRESSION_LIST},
            {"ROUTINE_DECLERATION", Node_Type::ROUTINE_DECLERATION},
            {"PRINT_STATMENT", Node_Type::PRINT_STATMENT},
            {"DIMENSION_LIST", Node_Type::DIMENSION_LIST},
        };
        auto it = type_map.find(type_name);
        if (it != type_map.end())
        {
            return it->second;
        }
        else
        {
            return (Node_Type::INVALID);
        }
    }

public:

    None_Terminal_Node(std::string node_type) : AST_Node(str_to_type(node_type)) {}
};

class Identifier_Node : public AST_Node
{
public:
    std::string identifier_name;
    Identifier_Node(const std::string &name)
        : AST_Node(Node_Type::IDENTIFIER_NODE_TYPE), identifier_name(name) {}
};

class Type_Node : public AST_Node
{
public:
    std::string type_name;
    Type_Node(const std::string &name)
        : AST_Node(Node_Type::TYPE_NODE), type_name(name) {}
};

class Boolean_Node : public AST_Node
{
public:
    bool val;
    Boolean_Node(const bool &val)
        : AST_Node(Node_Type::BOOLEAN_NODE), val(val) {}
};
class Integer_Node : public AST_Node
{
public:
    int val;
    Integer_Node(const int &val)
        : AST_Node(Node_Type::INTEGER_NODE), val(val) {}
};

class Real_Node : public AST_Node
{
public:
    double val;
    Real_Node(const double &val)
        : AST_Node(Node_Type::REAL_NODE), val(val) {}
};

class Operator : public AST_Node
{
public:
    std::string operation_name;
    Operator(const std::string &operation_name)
        : AST_Node(Node_Type::OPERATOR), operation_name(operation_name) {}
};

void print_ast(AST_Node *node, int indent, const std::string &file_name);
void print_ast_helper(AST_Node *node, int indent, FILE *file);
#endif // AST_H