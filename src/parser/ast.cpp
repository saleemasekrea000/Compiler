#include <stdlib.h>
#include <stdio.h>
#include "ast.hpp"
#include "lexer_2.hpp"
#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>


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

