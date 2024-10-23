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
}

%type <node> program routine_declarations routine_declaration routine_header parameters parameter statements statement variable_declaration assignment int_expression function_call arguments argument while_loop assertion return_statement

%start program 

%token <id_val> IDENTIFIER
%token <int_val> INTEGER_LITERAL
%token <op_val> OPERATOR
%token <keyword_val> KEYWORD
%token <keyword_val> IS
%token <keyword_val> WHILE
%token <keyword_val> END
%token <keyword_val> ROUTINE
%token LPAR RPAR LBRAC RBRAC RELPAR RERLPR
%token PUNCTUATOR

%%

program:
  routine_declarations statements { 
    $$ = create_node("program", "", $1, $2, NULL);
    print_ast($$, 0);
  }
  ;

routine_declarations:
  routine_declaration { 
    $$ = create_node("routine_declarations", "", $1, NULL, NULL);
  }
  | routine_declarations routine_declaration { 
    $$ = create_node("routine_declarations", "", $1, NULL, $2);
  }
  ;

routine_declaration:
  routine_header
  statements
  return_statement
  END { 
    $$ = create_node("routine_declaration", "start", $1, $2, $3);
  }
  ;

routine_header:
  ROUTINE IDENTIFIER LPAR parameters RPAR PUNCTUATOR IDENTIFIER IS { 
    $$ = create_node("routine_header", $2, $4, NULL, NULL);
  }
  | ROUTINE IDENTIFIER LPAR parameters RPAR IS { 
    $$ = create_node("routine_header", $2, $4, NULL, NULL);
  }

parameters:
  parameter { 
    $$ = create_node("parameters", "", $1, NULL, NULL);
  }
  | parameters PUNCTUATOR parameter { 
    $$ = create_node("parameters", "", $1, NULL, $3);
  }
  ;

parameter:
  IDENTIFIER PUNCTUATOR IDENTIFIER { 
    $$ = create_node("parameter", $1, NULL, NULL, NULL);
  }
  | IDENTIFIER { 
    $$ = create_node("parameter", $1, NULL, NULL, NULL);
  }
  ;

statements:
  statement { 
    $$ = create_node("statements", "", $1, NULL, NULL);
  }
  | statements statement { 
    $$ = create_node("statements", "", $1, NULL, $2);
  }
  ;

statement:
  variable_declaration { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  | assignment { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  | function_call { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  | while_loop { 
    $$ = create_node("statement", $1->type, $1, NULL, NULL);
  }
  ;

variable_declaration:
  IDENTIFIER IDENTIFIER PUNCTUATOR IDENTIFIER IS INTEGER_LITERAL PUNCTUATOR { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  | IDENTIFIER IDENTIFIER PUNCTUATOR IDENTIFIER PUNCTUATOR { 
    $$ = create_node("variable_declaration", $2, NULL, NULL, NULL);
  }
  ;

assignment:
  IDENTIFIER PUNCTUATOR OPERATOR int_expression PUNCTUATOR { 
    $$ = create_node("assignment", $1, $4, NULL, NULL);
  }
  ;

int_expression:
  INTEGER_LITERAL { 
    $$ = create_node("int_expression", "int", NULL, NULL, NULL);
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

function_call:
  IDENTIFIER LPAR arguments RPAR PUNCTUATOR { 
    $$ = create_node("function_call", $1, $3, NULL, NULL);
  }
  ;

arguments:
  argument { 
    $$ = create_node("arguments", "", $1, NULL, NULL);
  }
  | arguments PUNCTUATOR argument { 
    $$ = create_node("arguments", "", $1, NULL, $3);
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
  WHILE assertion KEYWORD 
  statements
  END { 
    $$ = create_node("while_loop", "start", $4, NULL, NULL);
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
  ;

return_statement:
  KEYWORD IDENTIFIER PUNCTUATOR { 
    $$ = create_node("return_statement", $2, NULL, NULL, NULL);
  }
  | KEYWORD INTEGER_LITERAL PUNCTUATOR { 
    $$ = create_node("return_statement", "Return integer", NULL, NULL, NULL);
  }
  ;

%%


void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}