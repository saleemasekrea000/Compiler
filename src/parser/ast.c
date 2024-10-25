#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

ASTNode *create_node(char *nodeType, char *nodeName, ASTNode *left, ASTNode *right, ASTNode *next, char *type, int intValue, float floatValue){
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->nodeType = nodeType;
  node->nodeName = nodeName;
  node->left = left;
  node->right = right;
  node->next = next;
  node->type= type;
  node->intValue= intValue;
  node->floatValue= floatValue;
  return node;
}

void print_ast(ASTNode *node, int indent)
{
  if (!node)
    return;
  for (int i = 0; i < indent; i++)
    printf("  ");
  printf("%s: %s: %d\n", node->nodeType, node->nodeName, node->intValue);
  print_ast(node->left, indent + 1);
  print_ast(node->right, indent + 1);
  print_ast(node->next, indent);
}