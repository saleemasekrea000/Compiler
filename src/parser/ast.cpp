 #include <stdlib.h>
 #include <stdio.h>
 #include "ast.hpp"
#include <cstdio>  // For printf
#include <memory>  // For std::shared_ptr
#include <string>  // For std::string

// ASTNode *create_node(char *nodeType, char *nodeName, ASTNode *left, ASTNode *right, ASTNode *next, char *type, int intValue, float floatValue){
//   ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
//   node->nodeType = nodeType;
//   node->nodeName = nodeName;
//   node->left = left;
//   node->right = right;
//   node->next = next;
//   node->type= type;
//   node->intValue= intValue;
//   node->floatValue= floatValue;
//   return node;
// }

// void print_ast(ASTNode *node, int indent)
// {
//   if (!node)
//     return;
//   for (int i = 0; i < indent; i++)
//     printf("  ");
//   printf("%s: %s: %d\n", node->nodeType, node->nodeName, node->intValue);
//   print_ast(node->left, indent + 1);
//   print_ast(node->right, indent + 1);
//   print_ast(node->next, indent);
// }



// Assume AST_Node and related classes are defined properly as discussed

void print_ast(AST_Node* node, int indent) {
    if (!node) {
        return;  // Base case: if node is null, do nothing
    }

    // Print the current node type with indentation
    for (int i = 0; i < indent; i++) {
        printf("  ");  // Indentation for the current level
    }

    // Determine the node type as a string
    const char* nodeType = "";
    switch (node->type) {
        case PROGRAM:
            nodeType = "Program";
            break;
        case SIMPLE_DECLARATION:
            nodeType = "Simple Declaration";
            break;
        case VARIABLE_DECLARATION:
            nodeType = "Variable Declaration";
            break;
        // Add other cases for additional node types
        default:
            nodeType = "Unknown";
            break;
    }

    // Print the node type
    printf("%s\n", nodeType);

    // Recursively print each child node
    for (const auto& child : node->children) {
        print_ast(child, indent + 1);  // Increase indentation for child nodes
    }
}
