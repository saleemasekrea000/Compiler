#ifndef AST_H
#define AST_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
// // Define the structure for AST nodes
// typedef struct ASTNode
// {
//   char *nodeType;
//   char *nodeName;
//   struct ASTNode *left;
//   struct ASTNode *right;
//   struct ASTNode *next;
//   char *type;
//   int intValue;
//   float floatValue;
// } ASTNode;

// // Function to create a new AST node
// ASTNode *create_node(char *nodeType, char *nodeName, ASTNode *left, ASTNode *right, ASTNode *next, char *type, int intValue, float floatValue);

// // Function to print the AST
// void print_ast(ASTNode *node, int indent);

typedef enum Variable_Type{
	INTEGER,
	REAL,
	BOOLEAN
}Variable_Type;

typedef enum Node_Type
{
	PROGRAM,
	SIMPLE_DECLARATION,
	VARIABLE_DECLARATION,
	TYPE_DECLARATION,
	PRIMARY_EXPRESSION,
	ARRAY_ACCESS_EXPRESSION,
	RECORD_EXPRESSION_ACCESS,
	EXPRESSION,
	STATEMENT,
	ITERATION_STATEMENT,
	WHILE_EXPRESSION,
	FOR_EXPRESSION,
} Node_Type;


class AST_Node{
public:
	enum Node_Type type;
	std::vector<AST_Node *>children;

	AST_Node(Node_Type t) : type(t){}

};

class Program : public AST_Node {
public:
    Program() : AST_Node(PROGRAM) {}
};

class SimpleDeclaration : public AST_Node {
public:
    SimpleDeclaration() : AST_Node(SIMPLE_DECLARATION) {}
};

class VariableDeclaration : public AST_Node {
public:
	std::string identifier_name;
	Variable_Type var_type;
	int var_value;
     VariableDeclaration(const std::string& idName, Variable_Type type, int value) 
        : AST_Node(VARIABLE_DECLARATION), identifier_name(idName), var_type(type) , var_value(value) {}
};


void print_ast(AST_Node *node, int indent);
#endif // AST_H