#ifndef AST_H
#define AST_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>


typedef enum Node_Type
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
    FOR_EXPRESSION,
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
} Node_Type;

class AST_Node
{
public:
    enum Node_Type type;
    std::vector<AST_Node *> children;

    AST_Node(Node_Type t) : type(t) {}
};

class None_Terminal_Node : public AST_Node
{
private:
    static Node_Type str_to_type(const std::string &type_name)
    {
        static const std::unordered_map<std::string, Node_Type> type_map = {
            {"PROGRAM", PROGRAM},
            {"DECLARATION", DECLARATION},
            {"SIMPLE_DECLARATION",SIMPLE_DECLARATION},
            {"VARIABLE_DECLARATION", VARIABLE_DECLARATION},
            {"PRIMARY_EXPRESSION", PRIMARY_EXPRESSION},
            {"PRIMARY_NODE",PRIMARY_NODE},
            {"ARRAY_ACCESS",ARRAY_ACCESS},
            {"RECORD_ACCESS",RECORD_ACCESS},
            {"SUMMAND", SUMMAND},
            {"FACTOR",FACTOR},
            {"SIMPLE",SIMPLE},
            {"RELATION",RELATION},
            {"EXPRESSION",EXPRESSION},
            {"TYPE_DECLARATION", TYPE_DECLARATION},
            {"ARRAY_TYPE", ARRAY_TYPE},
            {"RECORD_TYPE", RECORD_TYPE},
            {"VARIABLE_DECLARATIONS",VARIABLE_DECLARATIONS},
            {"STATEMENT", STATEMENT},
            {"ITERATION_STATEMENT", ITERATION_STATEMENT},
            {"WHILE_STATEMENT", WHILE_STATEMENT},
            {"BODY", BODY},
            {"FOR_STATEMENT",FOR_STATEMENT},
            {"RANGE_EX", RANGE_EX},
            {"RANGE_REVERSE",RANGE_REVERSE},
            {"ASSIGN_STATEMENT", ASSIGN_STATEMENT},
            {"IF_STATEMENT",IF_STATEMENT},
            {"IF_STATEMENT_ELSE", IF_STATEMENT_ELSE},
            {"JUMP_STATEMENT", JUMP_STATEMENT},
            {"RETURN_EX", RETURN_EX},
            {"CONTINUE_EX", CONTINUE_EX},
            {"BREAK_EX",BREAK_EX},
            {"Routine_Call",Routine_Call},
            {"Argument_Expression_List", Argument_Expression_List},
            {"PARAMETER_DECLERATION", PARAMETER_DECLERATION},
            {"PARAMETERS_EXPRESSION_LIST",PARAMETERS_EXPRESSION_LIST},
            {"ROUTINE_DECLERATION",ROUTINE_DECLERATION}
        };
        auto it = type_map.find(type_name);
        if (it != type_map.end())
        {
            return it->second;
        }
        else
        {
            return (INVALID);
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
        : AST_Node(IDENTIFIER_NODE_TYPE), identifier_name(name) {}
};

class Type_Node : public AST_Node
{
public:
    std::string type_name;
    Type_Node(const std::string &name)
        : AST_Node(TYPE_NODE), type_name(name) {}
};


class Boolean_Node : public AST_Node
{
public:
    bool val;
    Boolean_Node(const bool &val)
        : AST_Node(BOOLEAN_NODE), val(val) {}
};
class Integer_Node : public AST_Node
{
public:
    int val;
    Integer_Node(const int &val)
        : AST_Node(INTEGER_NODE), val(val) {}
};

class Real_Node : public AST_Node
{
public:
    double val;
    Real_Node(const double &val)
        : AST_Node(REAL_NODE), val(val) {}
};

class Operator : public AST_Node
{
public:
    std::string operation_name;
    Operator(const std::string &operation_name)
        : AST_Node(OPERATOR), operation_name(operation_name) {}
};



void print_ast(AST_Node *node, int indent, const std::string& file_name);
void print_ast_helper(AST_Node *node, int indent,FILE * file);
void Semantic_Analysis_Checks(AST_Node *node);
bool check_return(AST_Node* node, bool inside_function);
bool check_continue(AST_Node* node, bool inside_loop);
bool check_break(AST_Node* node, bool inside_loop);
bool checkVariableDeclarations(AST_Node* node,std::unordered_set<std::string> &declaredVariableNames);
bool checkRoutineDeclarations(AST_Node* node,std::unordered_set<std::string> &declaredRoutineNames);
void optimize(AST_Node* node);
void remove_unused(AST_Node* root);
Identifier_Node* getIdentifierNode(AST_Node* node);

#endif // AST_H