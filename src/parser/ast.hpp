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

typedef enum Node_Type
{
	PROGRAM,
	DECLARATION,
	SIMPLE_DECLARATION,
	IDENTIFIER_NODE_TYPE,
	VARIABLE_DECLARATION,
	TYPE_DECLARATION,
	EXPRESSION,
	STATEMENT,
	ITERATION_STATEMENT,
	WHILE_EXPRESSION,
	FOR_EXPRESSION,
	TYPE_NODE,
	BOOLEAN_NODE,
	INTEGER_NODE,
	REAL_NODE,
	UNARY_OP,
	PRIMARY_EXPRESSION,
	PRIMARY_NODE,
	ARRAY_ACCESS,
    RECORD_ACCESS,
	SUMMAND,
	FACTOR,
	SIMPLE,
	RELATION,
	RECORD_TYPE,
	ARRAY_TYPE,
} Node_Type;

class AST_Node
{
public:
	enum Node_Type type;
	std::vector<AST_Node *> children;

	AST_Node(Node_Type t) : type(t) {}
};

class Program_Node : public AST_Node
{
public:
	Program_Node() : AST_Node(PROGRAM) {}
};
class Declaration_Node : public AST_Node
{
public:
	Declaration_Node() : AST_Node(DECLARATION) {}
};
class SimpleDeclaration_Node : public AST_Node
{
public:
	SimpleDeclaration_Node() : AST_Node(SIMPLE_DECLARATION) {}
};

class Identifier_Node : public AST_Node
{
public:
	std::string identifier_name;
	Identifier_Node(const std::string &name)
		: AST_Node(IDENTIFIER_NODE_TYPE), identifier_name(name) {}
};

class Type_Node : public AST_Node
{
public:
	std::string type_name;
	Type_Node(const std::string &name)
		: AST_Node(TYPE_NODE), type_name(name) {}
};

class VariableDeclaration_Node : public AST_Node
{
public:
	std::string var_type; // Store variable type as a string
	int var_value;
	VariableDeclaration_Node()
		: AST_Node(VARIABLE_DECLARATION) {}
};

class Boolean_Node : public AST_Node
{
public:
	bool val;
	Boolean_Node(const bool &val)
		: AST_Node(BOOLEAN_NODE), val(val) {}
};
class Integer_Node : public AST_Node
{
public:
	int val;
	Integer_Node(const int &val)
		: AST_Node(INTEGER_NODE), val(val) {}
};

class Real_Node : public AST_Node
{
public:
	double val;
	Real_Node(const double &val)
		: AST_Node(REAL_NODE), val(val) {}
};

class Unary_OP : public AST_Node
{
public:
    std:: string operation_name;
	Unary_OP(const std::string &operation_name)
		: AST_Node(UNARY_OP), operation_name(operation_name) {}
};

class Primary_Expression_Node : public AST_Node
{
public:
	Primary_Expression_Node() : AST_Node(PRIMARY_EXPRESSION) {}
};
class Array_Access_Node : public AST_Node
{
public:
	Array_Access_Node() : AST_Node(ARRAY_ACCESS) {}
};
class Primary_Node : public AST_Node
{
public:
	Primary_Node() : AST_Node(PRIMARY_NODE) {}
};
class Record_Access_Node : public AST_Node
{
public:
	Record_Access_Node() : AST_Node(RECORD_ACCESS) {}
};

class Record_Type_Node : public AST_Node
{
public:
	Record_Type_Node() : AST_Node(RECORD_TYPE) {}
};
class Array_Type_Node : public AST_Node
{
public:
	Array_Type_Node() : AST_Node(ARRAY_TYPE) {}
};


class Summand_Node : public AST_Node {
public:
    Summand_Node()
        : AST_Node(SUMMAND){}
};
class Type_Decleration_Node : public AST_Node {
public:
    Type_Decleration_Node()
        : AST_Node(TYPE_DECLARATION){}
};
class Factor_Node : public AST_Node {
public:
    char operation;
    Factor_Node(char op)
        : AST_Node(FACTOR), operation(op) {}
};
class Simple_Node : public AST_Node {
public:
    char operation;
    Simple_Node(char op)
        : AST_Node(SIMPLE), operation(op) {}
};
class Relation_Node : public AST_Node {
public:
    std::string operation;
    Relation_Node(const std::string & op)
        : AST_Node(RELATION), operation(op) {}
};
class Expression_Node : public AST_Node {
public:
    std::string operation;
    Expression_Node(const std::string & op)
        : AST_Node(EXPRESSION), operation(op) {}
};
void print_ast(AST_Node *node, int indent);
#endif // AST_H