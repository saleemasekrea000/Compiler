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
  double real_val;
  bool bool_val;
}

%type <node> program simple_declarations routine_declaration routine_header parameters parameter statements statement variable_declaration assignment int_expression function_call arguments argument while_loop assertion return_statement type_declaration  array_type record_type

%start program 

%token <id_val> IDENTIFIER
%token <int_val> INTEGER_LITERAL
%token <real_val> REAL_LITERAL
%token <bool_val> BOOL_LITERAL
%token <op_val> OPERATOR
%token <keyword_val> KEYWORD
%token <keyword_val> IS
%token <keyword_val> WHILE
%token <keyword_val> END
%token <keyword_val> ROUTINE
%token <keyword_val> VAR
%token <keyword_val> TYPE
%token <keyword_val> RECORD
%token <keyword_val> TRUE
%token <keyword_val> FALSE
%token <keyword_val> ARRAY
%token <keyword_val> LOOP
%token <keyword_val> FOR
%token <keyword_val> IN
%token <keyword_val> IF
%token <keyword_val> THEN
%token <keyword_val> ELSE
%token <keyword_val> AND
%token <keyword_val> OR
%token <keyword_val> XOR
%token <keyword_val> NOT
%token <keyword_val> RETURN
%token <keyword_val> BREAK
%token <keyword_val> INTEGER_LITERAL_KEYWORD
%token <keyword_val> REAL_LITERAL_KEYWORD
%token <keyword_val> BOOL_LITERAL_KEYWORD
%token LPAR RPAR LBRAC RBRAC RELPAR RERLPR
%token PUNCTUATOR
%% 

program:
  simple_declarations routine_declarations statements {
    $$ = create_node("program", "", $1, $2, $3);
    print_ast($$, 0);
  }
  ;

simple_declarations:
  simple_declaration { 
    $$ = create_node("simple_declarations", "", $1, NULL, NULL);
  }
  | simple_declarations simple_declaration { 
    $$ = create_node("simple_declarations", "", $1, NULL, $2);
  }
  ;

simple_declaration:
  variable_declaration { 
    $$ = create_node("simple_declaration", "variable", $1, NULL, NULL);
  }
  | type_declaration { 
    $$ = create_node("simple_declaration", "type", $1, NULL, NULL);
  }
  ;

routine_declarations:
  routine_declaration { 
    $$ = create_node("routine_declarations", "", $1, NULL, NULL);
  }
  | routine_declarations routine_declaration { 
    $$ = create_node("routine_declarations", "", $1, $2);
  }
  ;

routine_declaration:
  routine_header statements return_statement END { 
    $$ = create_node("routine_declaration", "start", $1, $2, $3);
  }
  ;

routine_header:
  ROUTINE IDENTIFIER LPAR parameters RPAR PUNCTUATOR IDENTIFIER IS { 
    $$ = create_node("routine_header", $2, $4, NULL, NULL);
  }
  ;

parameters:
  parameter { 
    $$ = create_node("parameters", "", $1, NULL, NULL);
  }
  | parameters PUNCTUATOR parameter { 
    $$ = create_node("parameters", "", $1, $3);
  }
  ;

parameter:
  IDENTIFIER PUNCTUATOR IDENTIFIER { 
    $$ = create_node("parameter", $1, NULL, NULL, NULL);
  }
  ;

statements:
  statement { 
    $$ = create_node("statements", "", $1, NULL, NULL);
  }
  | statements statement { 
    $$ = create_node("statements", "", $1, $2, NULL);
  }
  ;

statement:
  variable_declaration PUNCTUATOR { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  | variable_declaration { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  | assignment PUNCTUATOR { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  | assignment { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  | function_call PUNCTUATOR { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  | function_call { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  | while_loop PUNCTUATOR { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  | while_loop { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  | if_statement PUNCTUATOR { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  | if_statement { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  ;

variable_declaration:
  VAR IDENTIFIER PUNCTUATOR INTEGER_LITERAL_KEYWORD IS INTEGER_LITERAL PUNCTUATOR { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  |
  VAR IDENTIFIER PUNCTUATOR REAL_LITERAL IS REAL_LITERAL_KEYWORD PUNCTUATOR { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  |
  VAR IDENTIFIER PUNCTUATOR BOOL_LITERAL IS BOOL_LITERAL_KEYWORD PUNCTUATOR { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  |
  VAR IDENTIFIER PUNCTUATOR INTEGER_LITERAL_KEYWORD IS INTEGER_LITERAL  { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  |
  VAR IDENTIFIER PUNCTUATOR REAL_LITERAL IS REAL_LITERAL_KEYWORD  { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  |
  VAR IDENTIFIER PUNCTUATOR BOOL_LITERAL IS BOOL_LITERAL_KEYWORD  { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  |
  VAR IDENTIFIER IS INTEGER_LITERAL PUNCTUATOR { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  |
  VAR IDENTIFIER IS INTEGER_LITERAL { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  |
  VAR IDENTIFIER IS REAL_LITERAL PUNCTUATOR { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  |
  VAR IDENTIFIER IS REAL_LITERAL { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  |
  VAR IDENTIFIER IS BOOL_LITERAL PUNCTUATOR { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  |
  VAR IDENTIFIER IS BOOL_LITERAL { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  ;

type_declaration:
  TYPE IDENTIFIER IS type { 
    $$ = create_node("type_declaration", $2, $4, NULL, NULL);
  }
  ;

type:
  | array_type { 
    $$ = create_node("type", $1, NULL, NULL);
  }
  | record_type { 
    $$ = create_node("type", $1, NULL, NULL);
  }
  ;

array_type:
  ARRAY LBRAC INTEGER_LITERAL RBRAC type { 
    $$ = create_node("array_type", "", $3, $5, NULL);
  }
  ;

record_type:
  RECORD LBRAC variable_declaration RBRAC END { 
    $$ = create_node("record_type", "", $3, NULL, NULL);
  }
  ;

assignment:
  IDENTIFIER PUNCTUATOR OPERATOR int_expression PUNCTUATOR { 
    $$ = create_node("assignment", $1, $4, NULL, NULL);
  }
  | IDENTIFIER PUNCTUATOR OPERATOR int_expression { 
    $$ = create_node("assignment", $1, $4, NULL, NULL);
  }
  ;

int_expression:
  INTEGER_LITERAL { 
    $$ = create_node("int_expression", "int", NULL, NULL, NULL);
  }
  | REAL_LITERAL { 
    $$ = create_node("int_expression", "real", NULL, NULL, NULL);
  }
  | IDENTIFIER OPERATOR IDENTIFIER { 
    $$ = create_node("int_expression", "id op id", NULL, NULL, NULL);
  }
  | IDENTIFIER OPERATOR INTEGER_LITERAL { 
    $$ = create_node("int_expression", "id op int", NULL, NULL, NULL);
  }
  | INTEGER_LITERAL OPERATOR IDENTIFIER { 
    $$ = create_node("int_expression", "int op id", NULL, NULL, NULL);
  }
  | INTEGER_LITERAL OPERATOR INTEGER_LITERAL { 
    $$ = create_node("int_expression", "int op int", NULL, NULL, NULL);
  }
  | IDENTIFIER OPERATOR REAL_LITERAL { 
    $$ = create_node("int_expression", "id op real", NULL, NULL, NULL);
  }
  | REAL_LITERAL OPERATOR IDENTIFIER { 
    $$ = create_node("int_expression", "real op id", NULL, NULL, NULL);
  }
  | INTEGER_LITERAL OPERATOR BOOL_LITERAL { 
    $$ = create_node("int_expression", "int op bool", NULL, NULL, NULL);
  }
  | BOOL_LITERAL OPERATOR INTEGER_LITERAL { 
    $$ = create_node("int_expression", "bool op int", NULL, NULL, NULL);
  }
  ;
real_expression:
  REAL_LITERAL { 
    $$ = create_node("real_expression", "real", NULL, NULL, NULL);
  }
  | IDENTIFIER OPERATOR IDENTIFIER { 
    $$ = create_node("real_expression", "id op id", NULL, NULL, NULL);
  }
  | IDENTIFIER OPERATOR REAL_LITERAL { 
    $$ = create_node("real_expression", "id op real", NULL, NULL, NULL);
  }
  | REAL_LITERAL OPERATOR IDENTIFIER { 
    $$ = create_node("real_expression", "real op id", NULL, NULL, NULL);
  }
  | REAL_LITERAL OPERATOR REAL_LITERAL { 
    $$ = create_node("real_expression", "real op real", NULL, NULL, NULL);
  }
  | REAL_LITERAL OPERATOR INTEGER_LITERAL { 
    $$ = create_node("real_expression", "real op int", NULL, NULL, NULL);
  }
  | INTEGER_LITERAL OPERATOR REAL_LITERAL { 
    $$ = create_node("real_expression", "int op real", NULL, NULL, NULL);
  }
  | REAL_LITERAL OPERATOR BOOL_LITERAL { 
    $$ = create_node("real_expression", "real op bool", NULL, NULL, NULL);
  }
  | BOOL_LITERAL OPERATOR REAL_LITERAL { 
    $$ = create_node("real_expression", "bool op real", NULL, NULL, NULL);
  }
  ;
  
  bool_expression:
  BOOL_LITERAL { 
    $$ = create_node("bool_expression", "bool", NULL, NULL, NULL);
  }
  | IDENTIFIER OPERATOR IDENTIFIER { 
    $$ = create_node("bool_expression", "id op id", NULL, NULL, NULL);
  }
  | IDENTIFIER OPERATOR BOOL_LITERAL { 
    $$ = create_node("bool_expression", "id op bool", NULL, NULL, NULL);
  }
  | BOOL_LITERAL OPERATOR IDENTIFIER { 
    $$ = create_node("bool_expression", "bool op id", NULL, NULL, NULL);
  }
  | BOOL_LITERAL OPERATOR BOOL_LITERAL { 
    $$ = create_node("bool_expression", "bool op bool", NULL, NULL, NULL);
  }
  ;

function_call:
  IDENTIFIER LPAR arguments RPAR PUNCTUATOR { 
    $$ = create_node("function_call", $1, $3, NULL, NULL);
  }
  | IDENTIFIER LPAR arguments RPAR { 
    $$ = create_node("function_call", $1, $3, NULL, NULL);
  }
  ;

arguments:
  argument { 
    $$ = create_node("arguments", "", $1, NULL, NULL);
  }
  | arguments PUNCTUATOR argument { 
    $$ = create_node("arguments", "", $1, $3, NULL);
  }
  ;

argument:
  IDENTIFIER { 
    $$ = create_node("argument", $1, NULL, NULL, NULL);
  }
  | INTEGER_LITERAL { 
    $$ = create_node("argument", "int", NULL, NULL, NULL);
  }
  ;

while_loop: 
  WHILE assertion LOOP statements END { 
    $$ = create_node("while_loop", "start", $3, NULL, NULL);
  }
  ;

assertion:
  INTEGER_LITERAL OPERATOR INTEGER_LITERAL { 
    $$ = create_node("assertion", "int op int", NULL, NULL, NULL);
  }
  | IDENTIFIER OPERATOR INTEGER_LITERAL { 
    $$ = create_node("assertion", "id op int", NULL, NULL, NULL);
  }
  | INTEGER_LITERAL OPERATOR IDENTIFIER { 
    $$ = create_node("assertion", "int op id", NULL, NULL, NULL);
  }
  | IDENTIFIER OPERATOR IDENTIFIER { 
    $$ = create_node("assertion", "id op id", NULL, NULL, NULL);
  }
  | REAL_LITERAL OPERATOR REAL_LITERAL { 
    $$ = create_node("assertion", "real op real", NULL, NULL, NULL);
  }
  | IDENTIFIER OPERATOR REAL_LITERAL { 
    $$ = create_node("assertion", "id op real", NULL, NULL, NULL);
  }
  | REAL_LITERAL OPERATOR IDENTIFIER { 
    $$ = create_node("assertion", "real op id", NULL, NULL, NULL);
  }
  | INTEGER_LITERAL OPERATOR REAL_LITERAL { 
    $$ = create_node("assertion", "int op real", NULL, NULL, NULL);
  }
  | REAL_LITERAL OPERATOR INTEGER_LITERAL { 
    $$ = create_node("assertion", "real op int", NULL, NULL, NULL);
  }
  | BOOL_LITERAL OPERATOR BOOL_LITERAL { 
    $$ = create_node("assertion", "bool op bool", NULL, NULL, NULL);
  }
  | IDENTIFIER OPERATOR BOOL_LITERAL { 
    $$ = create_node("assertion", "id op bool", NULL, NULL, NULL);
  }
  | BOOL_LITERAL OPERATOR IDENTIFIER { 
    $$ = create_node("assertion", "bool op id", NULL, NULL, NULL);
  }
  | INTEGER_LITERAL OPERATOR BOOL_LITERAL { 
    $$ = create_node("assertion", "int op bool", NULL, NULL, NULL);
  }
  | BOOL_LITERAL OPERATOR INTEGER_LITERAL { 
    $$ = create_node("assertion", "bool op int", NULL, NULL, NULL);
  }
  | REAL_LITERAL OPERATOR BOOL_LITERAL { 
    $$ = create_node("assertion", "real op bool", NULL, NULL, NULL);
  }
  | BOOL_LITERAL OPERATOR REAL_LITERAL { 
    $$ = create_node("assertion", "bool op real", NULL, NULL, NULL);
  }
  ;

return_statement:
  RETURN IDENTIFIER PUNCTUATOR { 
    $$ = create_node("return_statement", $2, NULL, NULL, NULL);
  }
  ;

if_statement:
  IF assertion THEN statements ELSE statements END { 
    $$ = create_node("if_statement", "", $2, $4, $6);
  }
  ;
%%

void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}