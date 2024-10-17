%{
#include <stdio.h>
#include "lexer_2.hpp"
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
}
%start program 

%token <id_val> IDENTIFIER
%token <int_val> INTEGER_LITERAL
%token <op_val> OPERATOR
%token <keyword_val> KEYWORD
%token <keyword_val> IS
%token <keyword_val> WHILE
%token <keyword_val> ROUTINE
%token <keyword_val> END
%token LPAR RPAR LBRAC RBRAC RELPAR RERLPR
%token PUNCTUATOR

%%

program:
  routine_declarations statements { print_indent(); printf("%d: Main program\n", counter++);}
  ;

routine_declarations:
  routine_declaration { print_indent(); printf("%d: List of routine declarations\n", counter++); }
  | routine_declarations routine_declaration { print_indent(); printf("%d: List of routine declarations\n", counter++); }
  ;

routine_declaration:
  routine_header
  statements
  return_statement
  END { print_indent(); printf("%d: end\n", counter++); }
  ;

routine_header:
  ROUTINE IDENTIFIER LPAR parameters RPAR PUNCTUATOR IDENTIFIER IS { print_indent(); printf("%d: routine declaration for %s\n", counter++, $2);}
  | ROUTINE IDENTIFIER LPAR parameters RPAR IS { print_indent(); printf("%d: routine declaration for %s\n", counter++, $2); }

parameters:
  parameter
  | parameters PUNCTUATOR parameter
  ;

parameter:
  IDENTIFIER
  | INTEGER_LITERAL
  ;

statements:
  statement
  | statements statement
  ;

statement:
  variable_declaration 
  | assignment
  | function_call
  | while_loop
  ;

variable_declaration:
  IDENTIFIER IDENTIFIER PUNCTUATOR IDENTIFIER IS INTEGER_LITERAL PUNCTUATOR { print_indent(); printf("%d: variable declaration for %s\n", counter++, $2); }
  | IDENTIFIER IDENTIFIER PUNCTUATOR IDENTIFIER PUNCTUATOR { print_indent(); printf("%d: variable declaration for %s\n", counter++, $2); }
  ;

assignment:
  IDENTIFIER PUNCTUATOR OPERATOR int_expression PUNCTUATOR { print_indent(); printf("%d: assignment for %s\n", counter++, $1); }
  ;

int_expression:
  INTEGER_LITERAL
  | IDENTIFIER OPERATOR IDENTIFIER
  | IDENTIFIER OPERATOR INTEGER_LITERAL
  | INTEGER_LITERAL OPERATOR IDENTIFIER
  | INTEGER_LITERAL OPERATOR INTEGER_LITERAL

function_call:
  IDENTIFIER LPAR arguments RPAR PUNCTUATOR { print_indent(); printf("%d: function call for %s\n", counter++, $1);}
  ;

arguments:
  argument
  | arguments PUNCTUATOR argument
  ;

argument:
  IDENTIFIER
  | INTEGER_LITERAL
  ;

while_loop: 
  WHILE assertion KEYWORD { print_indent(); printf("%d: while loop start\n", counter++); }
  statements
  END { print_indent(); printf("%d: while loop end\n", counter++); }
  ;

assertion:
  INTEGER_LITERAL OPERATOR INTEGER_LITERAL
  | IDENTIFIER OPERATOR INTEGER_LITERAL
  | INTEGER_LITERAL OPERATOR IDENTIFIER
  | IDENTIFIER OPERATOR IDENTIFIER
  ;


return_statement:
  KEYWORD IDENTIFIER PUNCTUATOR { print_indent(); printf("%d: return value is %s\n", counter++, $2); }
  | KEYWORD INTEGER_LITERAL PUNCTUATOR { print_indent(); printf("%d: return value is %d\n", counter++, $2);  }
  ;

%%

int main() {
  yyparse();
}

void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}