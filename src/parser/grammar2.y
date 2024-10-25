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

%type <node> program simple_declaration variable_declaration type_declaration
%type <node> routine_declaration parameters parameter_declaration type
%type <node> primitive_type array_type record_type body statement
%type <node> assignment routine_call while_loop for_loop range if_statement expression relation
%type <node> simple factor summand primary modifiable_primary

%start program 

%token <id_val> IDENTIFIER
%token <int_val> INTEGER_LITERAL
%token <real_val> REAL_LITERAL
%token <bool_val> BOOLEAN_LITERAL
%token <op_val> OPERATOR
%token <keyword_val> IS WHILE END ROUTINE VAR INTEGER_LITERAL_KEYWORD REAL_LITERAL_KEYWORD OR AND XOR NOT
%token <keyword_val> BOOLEAN_LITERAL_KEYWORD RECORD ARRAY FOR RETURN THEN TRUE FALSE TYPE LOOP IN IF ELSE BREAK
%token LE_OP GE_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN ASSIGN_OP;

%%
program:
    simple_declarations
    | routine_declarations
    ;
simple_declarations : 
simple_declaration
simple_declaration:
    variable_declaration
    | type_declaration
    ;

%%

void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}