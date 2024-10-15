%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.hpp"
extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror(const char *s);
%}

%union {
  Node *node;
  BlockNode *block;
  ExpressionNode *expr;
  StatementNode *stmt;
  std::string *string;
  int token;
}

%token <string> IDENTIFIER INTEGER_LITERAL
%token <token> PLUS MINUS MULTIPLY DIVIDE ASSIGN
%token <token> WHILE RETURN VAR FUNCTION
%token <token> LEFT_PAREN RIGHT_PAREN LEFT_BRACE RIGHT_BRACE

%%

program:
  function
  ;

function:
  FUNCTION IDENTIFIER LEFT_PAREN parameters RIGHT_PAREN block { $$ = new RoutineNode(*$2, $4, $6); }
  ;

parameters:
  /* empty */ { $$ = new std::vector<VariableDeclarationNode *>; }
  | parameters VAR IDENTIFIER { $1->push_back(new VariableDeclarationNode(*$3, "int")); $$ = $1; }
  ;

block:
  LEFT_BRACE statements RIGHT_BRACE { $$ = new BlockNode(); for(auto stmt : *$2) $$->add_statement(stmt); }
  ;

statements:
  /* empty */ { $$ = new std::vector<StatementNode *>; }
  | statements statement { $1->push_back($2); $$ = $1; }
  ;

statement:
  assignment
  | declaration
  | while_loop
  | return_stmt
  | function_call
  ;

assignment:
  IDENTIFIER ASSIGN expression { $$ = new AssignmentNode(*$1, $3); }
  ;

declaration:
  VAR IDENTIFIER { $$ = new VariableDeclarationNode(*$2, "int"); }
  ;

while_loop:
  WHILE LEFT_PAREN expression RIGHT_PAREN block { $$ = new WhileNode($3, $5); }
  ;

return_stmt:
  RETURN expression { $$ = new ReturnNode($2); }
  ;

function_call:
  IDENTIFIER LEFT_PAREN arguments RIGHT_PAREN { $$ = new FunctionCallNode(*$1, $3); }
  ;

arguments:
  /* empty */ { $$ = new std::vector<ExpressionNode *>; }
  | arguments expression { $1->push_back($2); $$ = $1; }
  ;

expression:
  INTEGER_LITERAL { $$ = new IntegerLiteralNode($1); }
  | IDENTIFIER { $$ = new IdentifierNode(*$1); }
  | expression PLUS expression { $$ = new BinaryOperationNode($1, "+", $3); }
  | expression MINUS expression { $$ = new BinaryOperationNode($1, "-", $3); }
  | expression MULTIPLY expression { $$ = new BinaryOperationNode($1, "*", $3); }
  | expression DIVIDE expression { $$ = new BinaryOperationNode($1, "/", $3); }
  ;

%%

void yyerror(const char *s) {
  fprintf(stderr, "Error: %s\n", s);
}

int main(int argc, char **argv) {
  yyin = fopen(argv[1], "r");
  if(!yyin) {
    printf("Error: Cannot open file\n");
    return 1;
  }

  yyparse();

  fclose(yyin);
  return 0;
}