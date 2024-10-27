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
