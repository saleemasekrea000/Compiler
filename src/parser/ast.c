#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

ASTNode *create_node(char *type, char *value, ASTNode *left, ASTNode *right, ASTNode *next)
{
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = type;
  node->value = value;
  node->left = left;
  node->right = right;
  node->next = next;
  return node;
}

void print_ast(ASTNode *node, int indent)
{
  if (!node)
    return;
  for (int i = 0; i < indent; i++)
    printf("  ");
  printf("%s: %s\n", node->type, node->value);
  print_ast(node->left, indent + 1);
  print_ast(node->right, indent + 1);
  print_ast(node->next, indent);
}