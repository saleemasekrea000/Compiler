#include <stdlib.h>
#include <stdio.h>
#include "ast.hpp"
#include <cstdio>
#include <memory>
#include <string>

void print_ast(AST_Node* node, int indent) {
    if (!node) {
        return; // Base case: if node is null, do nothing
    }

    // Print the current node type with indentation
    for (int i = 0; i < indent; i++) {
        printf("  "); // Indentation for the current level
    }

    // Print node type
    switch (node->type) {
        case PROGRAM:
            printf("Program\n");
            break;
        case DECLARATION:
            printf("Declarations\n");
            break;
        case SIMPLE_DECLARATION:
            printf("Simple declaration\n");
            break;
        case PRIMARY_EXPRESSION :
           printf("Primary expresson\n");
           break;
        case PRIMARY_NODE:
           printf("Primary node\n");
           break;
        case VARIABLE_DECLARATION: {
            printf("Variable declaration\n");
            break;
        }
        case ARRAY_ACCESS: {
            printf("Array access\n");
            break;
        }
        case RECORD_ACCESS: {
            printf("Record access\n");
            break;
        }
        case SUMMAND: {
            printf("Summand\n");
            break;
        }
        case TYPE_DECLARATION: {
            printf("Type declaration\n");
            break;
        }
        case ARRAY_TYPE: {
            printf("Array type\n");
            break;
        }
        case RECORD_TYPE: {
            printf("Record type\n");
            break;
        }
        case FACTOR : {
            printf("Factor\n");
            break;
        }
        case SIMPLE : {
            printf("Simple\n");
            break;
        }
        case RELATION: {
           printf("Relation\n");
           break;
        }
        case EXPRESSION: {
           printf("Expression\n");
           break;
        }
        case STATEMENT: {
            printf("Statement\n");
            break;
        }
        case ITERATION_STATEMENT:{
            printf("Iteration statement\n");
            break;
        }
        case WHILE_STATEMENT:{
            printf("While statement\n");
            break;
        }
        case FOR_STATEMENT:{
            printf("For statement\n");
            break;
        }
        case ASSIGN_STATEMENT:{
            printf("Assignment statement\n");
            break;
        }
        case RANGE_EX:{
            printf("Range\n");
            break;
        }
        case RANGE_REVERSE:{
            printf("Range reverse\n");
            break;
        }
        case BODY:{
            printf("body\n");
            break;
        }
        case VARIABLE_DECLARATIONS:{
           printf("Variable Declarations\n");
           break;
        }
        case IDENTIFIER_NODE_TYPE:{
          Identifier_Node* Identifier_node = static_cast<Identifier_Node*>(node);
          printf("Identifier: %s\n", Identifier_node->identifier_name.c_str());
          break;
        }
        case TYPE_NODE:{
          Type_Node* type_node = static_cast<Type_Node*>(node);
          printf("Type: %s\n", type_node->type_name.c_str());
          break;
        }
         case BOOLEAN_NODE: {
            Boolean_Node* boolean_node = static_cast<Boolean_Node*>(node);
            std::cout << "Boolean : " << (boolean_node->val ? "true" : "false") << std::endl;
            break;
        }
        case INTEGER_NODE: {
            Integer_Node* integer_node = static_cast<Integer_Node*>(node);
            std::cout << "Integer : " << integer_node->val << std::endl;
            break;
        }
        case REAL_NODE: {
            Real_Node* real_node = static_cast<Real_Node*>(node);
            std::cout << "Real : " << real_node->val << std::endl;
            break;
        }
        case OPERATOR: {
            Operator* op_node = static_cast<Operator*>(node);
            printf("Operator: %s\n", op_node->operation_name.c_str());
            break;
        }
        default:
            printf("Unknown Node Type\n");
            break;
    }
  
    // Recursively print each child node
    for (const auto& child : node->children) {
        print_ast(child, indent + 1); // Increase indentation for child nodes
    }
}
