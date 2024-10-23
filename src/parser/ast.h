#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <stdio.h>

// Define the structure for AST nodes
typedef struct ASTNode
{
  char *type;
  char *value;
  struct ASTNode *left;
  struct ASTNode *right;
  struct ASTNode *next;
} ASTNode;

// Function to create a new AST node
ASTNode *create_node(char *type, char *value, ASTNode *left, ASTNode *right, ASTNode *next);

// Function to print the AST
void print_ast(ASTNode *node, int indent);

#endif // AST_H