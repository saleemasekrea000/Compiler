#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <stdio.h>

// Define the structure for AST nodes
typedef struct ASTNode
{
  char *nodeType;
  char *nodeName;
  struct ASTNode *left;
  struct ASTNode *right;
  struct ASTNode *next;
  char *type;
  int intValue;
  float floatValue;
} ASTNode;

// Function to create a new AST node
ASTNode *create_node(char *nodeType, char *nodeName, ASTNode *left, ASTNode *right, ASTNode *next, char *type, int intValue, float floatValue);

// Function to print the AST
void print_ast(ASTNode *node, int indent);

#endif // AST_H