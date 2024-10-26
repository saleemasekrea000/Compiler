%{
#include <stdio.h>
#include <stdlib.h>
#include "lexer_2.hpp"
#include "ast.h"

void yyerror(char *s);
int counter = 1;
int indent = 0;
void print_indent() {
  for(int i = 0; i < indent; i++) printf("  ");
}
%}

%union {
  char *id_val;
  int int_val;
  char *op_val;
  char *keyword_val;
  ASTNode *node;
  float real_val;
  char* bool_val;
}

%start program 

%token <id_val> IDENTIFIER
%token <int_val> INTEGER_LITERAL
%token <real_val> REAL_LITERAL
%token <bool_val> BOOLEAN_LITERAL
%token <op_val> OPERATOR
%token <keyword_val> IS WHILE END ROUTINE VAR INTEGER_LITERAL_KEYWORD REAL_LITERAL_KEYWORD OR AND XOR NOT RANGE
%token <keyword_val> BOOLEAN_LITERAL_KEYWORD RECORD ARRAY FOR RETURN THEN TRUE FALSE TYPE LOOP IN IF ELSE BREAK CONTINUE
%token LE_OP GE_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN ASSIGN_OP;
%%

program 
  : simpleDeclarations
;
simpleDeclarations 
  : simpleDeclaration
  | simpleDeclaration simpleDeclarations
;
simpleDeclaration 
  : variableDecleration
;
variableDecleration
  : VAR IDENTIFIER IS additive_expression ';'
  | VAR IDENTIFIER ':' type IS additive_expression ';'
;

primary_expression
  : IDENTIFIER
  | INTEGER_LITERAL
  | REAL_LITERAL
  | BOOLEAN_LITERAL
  | '(' additive_expression ')'
;

postfix_expression
	: primary_expression
	// | postfix_expression '[' expression ']'
	// | postfix_expression '(' ')'
	// | postfix_expression '(' argument_expression_list ')'
	// | postfix_expression '.' IDENTIFIER
	;

// argument_expression_list
// 	: assignment_expression
// 	| argument_expression_list ',' assignment_expression
// 	;


multiplicative_expression
	: postfix_expression
	| multiplicative_expression '*' postfix_expression
	| multiplicative_expression '/' postfix_expression
	| multiplicative_expression '%' postfix_expression
;
additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
;
type 
  : INTEGER_LITERAL_KEYWORD
  | REAL_LITERAL_KEYWORD 
  | BOOLEAN_LITERAL_KEYWORD
;
%%

void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}