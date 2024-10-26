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
%token <keyword_val> IS WHILE END ROUTINE VAR INTEGER_LITERAL_KEYWORD REAL_LITERAL_KEYWORD OR AND XOR NOT RANGE REVERSE
%token <keyword_val> BOOLEAN_LITERAL_KEYWORD RECORD ARRAY FOR RETURN THEN TRUE FALSE TYPE LOOP IN IF ELSE BREAK CONTINUE
%token LE_OP GE_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN ASSIGN_OP;
%%

program 
  : body
;

/*
simpleDeclarations 
  : simpleDeclaration
  | simpleDeclaration simpleDeclarations
;*/
simpleDeclaration 
  : variableDecleration | typeDecleration 
;
 
variableDecleration
  : VAR IDENTIFIER IS expression ';'
  | VAR IDENTIFIER ':' type IS expression ';'
;
// normal primary_expression 
primary_expression
	: optional_sign INTEGER_LITERAL
    | optional_sign REAL_LITERAL
    | TRUE
    | FALSE
	| NOT primary
	| IDENTIFIER

;
primary
	: primary_expression
    | array_access_expression
    | record_expession_access
	// | primary '(' ')'
	// | primary '(' argument_expression_list ')'
;

array_access_expression  
  : IDENTIFIER '[' expression ']' 
  | array_access_expression '[' expression ']' 
;

// Optional Sign for positive and negative numbers
optional_sign
  : /* empty */  // This makes it optional
  | '+'
  | '-'
;
summand
  : primary
  | '(' expression ')'
;
factor
  : summand
  | factor '+' summand
  | factor '-' summand
;

expression
  : relation 
  | relation AND relation
  | relation OR relation
  | relation XOR relation
;

relation
  : simple
  | simple '<' simple
  | simple LE_OP simple
  | simple '>' simple
  | simple GE_OP simple
  | simple '=' simple
  | simple op_ass simple
;
op_ass
  : ASSIGN_OP
  | SUB_ASSIGN
  | ADD_ASSIGN
  | MUL_ASSIGN
  | DIV_ASSIGN
  | MOD_ASSIGN
;
simple
  : factor
  | simple '*' factor
  | simple '/' factor
  | simple '%' factor
;

type 
  : INTEGER_LITERAL_KEYWORD
  | REAL_LITERAL_KEYWORD 
  | BOOLEAN_LITERAL_KEYWORD
  | recordType
  | arrayType
  | IDENTIFIER
;

//make saleem see it 
record_expession_access
  : IDENTIFIER '.' IDENTIFIER 
  | array_access_expression '.' IDENTIFIER 
  | record_expession_access '.'  IDENTIFIER 
  | record_expession_access '.' array_access_expression 
;

recordType
  : RECORD variableDeclerations END 
;

//note this should be written without a semicolon 

arrayType 
  : ARRAY '[' expression ']' type 
;
variableDeclerations 
  : variableDecleration
  | variableDecleration variableDeclerations
;

typeDecleration 
  : TYPE IDENTIFIER IS type 
;

body :
  statement
  | simpleDeclaration
  | statement body
  | simpleDeclaration body
;

statement :
  iteration_statement
;

iteration_statement
	: while_expression
  |  for_expression
;
while_expression :
  WHILE expression LOOP body END
;
for_expression :
  FOR IDENTIFIER range LOOP body END  
;
range :
  IN expression RANGE expression 
  | IN REVERSE expression RANGE expression
;
%%

void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}