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
            printf("Declaration\n");
            break;
        case SIMPLE_DECLARATION:
            printf("Simple Declaration\n");
            break;
        case PRIMARY_EXPRESSION :
           printf("PRIMARY_EXPRESSION\n");
           break;
        case PRIMARY_NODE:
           printf("PRIMARY_NODE\n");
           break;
        case VARIABLE_DECLARATION: {
            printf("VARIABLE_DECLARATION\n");
            break;
        }
        case ARRAY_ACCESS: {
            printf("ARRAY_ACCESS\n");
            break;
        }
        case RECORD_ACCESS: {
            printf("RECORD_ACCESS\n");
            break;
        }
        case SUMMAND: {
            printf("SUMMAND_NODE\n");
            break;
        }
        case TYPE_DECLARATION: {
            printf("TYPE_DECLARATION\n");
            break;
        }
        case ARRAY_TYPE: {
            printf("ARRAY_TYPE\n");
            break;
        }
        case RECORD_TYPE: {
            printf("RECORD_TYPE\n");
            break;
        }
        case FACTOR : {
            Factor_Node* factor_node = static_cast<Factor_Node*>(node);
            if (factor_node&& factor_node->operation!='n') {
                printf("Factor : Operation '%c'\n", factor_node->operation);
            }
            else if (factor_node&& factor_node->operation=='n') {
                printf("Factor\n");
            }
            break;
        }
        case SIMPLE : {
            Simple_Node* simple_node = static_cast<Simple_Node*>(node);
            if (simple_node&& simple_node->operation!='n') {
                printf("SIMPLE : Operation '%c'\n", simple_node->operation);
            }
            else if (simple_node&& simple_node->operation=='n') {
                printf("SIMPLE\n");
            }
            break;
        }
        case RELATION: {
            Relation_Node* relation_node = static_cast<Relation_Node*>(node);
            if (relation_node&& relation_node->operation.c_str()!="n") {
                printf("Relation Node: Operation '%s'\n", relation_node->operation.c_str());
            }
            else if (relation_node){
                printf("Relation Node\n");
            }
            break;
        }
        case EXPRESSION: {
            Expression_Node* expression_node = static_cast<Expression_Node*>(node);
            if (expression_node&& expression_node->operation.c_str()!="n") {
                printf("Expression Node: Operation '%s'\n", expression_node->operation.c_str());
            }
            else if (expression_node){
                printf("Expression Node\n");
            }
            break;
        }
        case IDENTIFIER_NODE_TYPE:{
          Identifier_Node* Identifier_node = static_cast<Identifier_Node*>(node);
          printf("IDENTIFIER: %s\n", Identifier_node->identifier_name.c_str());
          break;
        }
        case TYPE_NODE:{
          Type_Node* type_node = static_cast<Type_Node*>(node);
          printf("TYPE: %s\n", type_node->type_name.c_str());
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
        case UNARY_OP: {
            Unary_OP* unary_op_node = static_cast<Unary_OP*>(node);
            std::cout << "Unary Operation: " << unary_op_node->operation_name << std::endl;
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
