#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>

#include "ast.hpp"
#include "parser.hpp"

static const std::unordered_map<Node_Type, std::string> type_map = {
    {Node_Type::PROGRAM, "Program"},
    {Node_Type::DECLARATION, "Declarations"},
    {Node_Type::SIMPLE_DECLARATION, "Simple declaration"},
    {Node_Type::VARIABLE_DECLARATION, "Variable declaration"},
    {Node_Type::PRIMARY_EXPRESSION, "Primary expresson"},
    {Node_Type::PRIMARY_NODE, "Primary node"},
    {Node_Type::ARRAY_ACCESS, "Array access"},
    {Node_Type::RECORD_ACCESS, "Record access"},
    {Node_Type::SUMMAND, "Summand"},
    {Node_Type::FACTOR, "Factor"},
    {Node_Type::SIMPLE, "Simple"},
    {Node_Type::RELATION, "Relation"},
    {Node_Type::EXPRESSION, "Expression"},
    {Node_Type::TYPE_DECLARATION, "Type declaration"},
    {Node_Type::ARRAY_TYPE, "Array type"},
    {Node_Type::RECORD_TYPE, "Record type"},
    {Node_Type::VARIABLE_DECLARATIONS, "Variable Declarations"},
    {Node_Type::STATEMENT, "Statement"},
    {Node_Type::ITERATION_STATEMENT, "Iteration statement"},
    {Node_Type::WHILE_STATEMENT, "While statement"},
    {Node_Type::BODY, "Body"},
    {Node_Type::FOR_STATEMENT, "For statement"},
    {Node_Type::RANGE_EX, "Range"},
    {Node_Type::RANGE_REVERSE, "Range reverse"},
    {Node_Type::ASSIGN_STATEMENT, "Assignment statement"},
    {Node_Type::IF_STATEMENT, "if statement"},
    {Node_Type::IF_STATEMENT_ELSE, "if and else statement"},
    {Node_Type::JUMP_STATEMENT, "Jump Statement"},
    {Node_Type::RETURN_EX, "Return"},
    {Node_Type::CONTINUE_EX, "Continue"},
    {Node_Type::BREAK_EX, "Break"},
    {Node_Type::Routine_Call, "Routine Call"},
    {Node_Type::Argument_Expression_List, "Arguments Expression List"},
    {Node_Type::PARAMETER_DECLERATION, "Parameter Decleration"},
    {Node_Type::PARAMETERS_EXPRESSION_LIST, "Parameters Expression List"},
    {Node_Type::ROUTINE_DECLERATION, "Routine Decleration"},
    {Node_Type::PRINT_STATMENT, "PRINT"},
    {Node_Type::DIMENSION_LIST, "DIMENSION_LIST"},
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
        case Node_Type::IDENTIFIER_NODE_TYPE:
        {
            Identifier_Node *Identifier_node = static_cast<Identifier_Node *>(node);
            fprintf(output_file, "Identifier: %s\n", Identifier_node->identifier_name.c_str());
            break;
        }
        case Node_Type::TYPE_NODE:
        {
            Type_Node *type_node = static_cast<Type_Node *>(node);
            fprintf(output_file, "Type: %s\n", type_node->type_name.c_str());
            break;
        }
        case Node_Type::BOOLEAN_NODE:
        {
            Boolean_Node *boolean_node = static_cast<Boolean_Node *>(node);
            fprintf(output_file, "Boolean: %s\n", (boolean_node->val ? "true" : "false"));
            break;
        }
        case Node_Type::INTEGER_NODE:
        {
            Integer_Node *integer_node = static_cast<Integer_Node *>(node);
            fprintf(output_file, "Integer: %d\n", integer_node->val);
            break;
        }
        case Node_Type::REAL_NODE:
        {
            Real_Node *real_node = static_cast<Real_Node *>(node);
            fprintf(output_file, "Real: %f\n", real_node->val);
            break;
        }
        case Node_Type::OPERATOR:
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

