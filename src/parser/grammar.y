%{
#include <stdio.h>
#include <stdlib.h>
#include "lexer_2.hpp"
#include "ast.hpp"

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
  double real_val;
  bool bool_val;
  char *op_val;
  char *keyword_val;
  AST_Node* node; 
  char * type_name;

}
%type <node> program simpleDeclaration variableDeclaration declarations identifier type primary_expression
%type <node> int_exp real_exp boolean_exp primary unary_op array_access_expression

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
  : declarations { 
      $$ = new Program_Node(); 
      $$->children.push_back($1); 
      print_ast($$, 0);
    }
  ;
declarations
  : declarations simpleDeclaration {
      $$ = $1;
      $$->children.push_back($2);
    }
  // | declarations statement {
  //     $$ = $1;
  //     $$->children.push_back($2);
  //   }
  // | declarations function {
  //     $$ = $1;
  //     $$->children.push_back($2);
  //   }
  | /* empty */ {
      $$ = new Declaration_Node(); 
    }
  ;

simpleDeclaration 
  : variableDeclaration { 
      $$ = new SimpleDeclaration_Node();
      $$->children.push_back($1);
    }
;

variableDeclaration
  : VAR identifier IS primary ';' { 
      $$ = new VariableDeclaration_Node();
      $$->children.push_back($2);
      $$->children.push_back(new Type_Node("none"));
      $$->children.push_back($4);
    }
  | VAR identifier ':' type IS primary ';' { 
      $$ = new VariableDeclaration_Node();
      $$->children.push_back($2);
      $$->children.push_back($4);
      $$->children.push_back($6);
    }
;
identifier :
 IDENTIFIER{
  $$ = new Identifier_Node(std::string($1));
 }
;
type 
  : INTEGER_LITERAL_KEYWORD {
    $$ = new Type_Node("integer");
  } 
  | REAL_LITERAL_KEYWORD { 
    $$ = new Type_Node("real");
  }
  | BOOLEAN_LITERAL_KEYWORD {
    $$ = new Type_Node("boolean");
  }
  | identifier {
      $$ = new Type_Node("identifier");
      $$->children.push_back($1);
  }
  //   | recordType
//   | arrayType
;

// normal primary_expression 
primary_expression
	: int_exp{
    $$ = new Primary_Expression_Node();
    $$->children.push_back($1);
  }
  | real_exp{
    $$ = new Primary_Expression_Node();
    $$->children.push_back($1);
  }
  |  boolean_exp{
    $$ = new Primary_Expression_Node();
    $$->children.push_back($1);
  }
  | unary_op primary
	| identifier{
    $$ = new Primary_Expression_Node();
    $$->children.push_back($1);
  }
;
unary_op:
   NOT{
    $$ = new Unary_OP("!");
   }
;
int_exp
  : INTEGER_LITERAL{
    $$ = new Integer_Node($1);
  }
;
real_exp
   : REAL_LITERAL{
    $$ = new Real_Node($1);
  }
;
boolean_exp
   : BOOLEAN_LITERAL{
    $$ = new Boolean_Node($1);
  }
;

primary
 	: primary_expression{
    $$ = new Primary_Node();
    $$->children.push_back($1);
  }    
  | array_access_expression{
    $$ = new Primary_Node();
    $$->children.push_back($1);
  }
//     | record_expession_access
// 	// | primary '(' ')'
// 	// | primary '(' argument_expression_list ')'
;
array_access_expression  
  : identifier '[' primary ']' {
    $$ = new Array_Access_Node();
    $$->children.push_back($1);
    $$->children.push_back($3);

  }
  | array_access_expression '[' primary ']' {
    $$ = new Array_Access_Node();
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
;
/*
simpleDeclarations 
  : simpleDeclaration
  | simpleDeclaration simpleDeclarations
;
simpleDeclaration 
  : variableDecleration
  | typeDecleration 
;



// // Optional Sign for positive and negative numbers

// summand
//   : primary
//   | '(' expression ')'
// ;
// factor
//   : summand
//   | factor '+' summand
//   | factor '-' summand
// ;

// expression
//   : relation 
//   | relation AND relation
//   | relation OR relation
//   | relation XOR relation
// ;

// relation
//   : simple
//   | simple '<' simple
//   | simple LE_OP simple
//   | simple '>' simple
//   | simple GE_OP simple
//   | simple '=' simple
//   | simple op_ass simple
// ;
// op_ass
//   : ASSIGN_OP
//   | SUB_ASSIGN
//   | ADD_ASSIGN
//   | MUL_ASSIGN
//   | DIV_ASSIGN
//   | MOD_ASSIGN
// ;
// simple
//   : factor
//   | simple '*' factor
//   | simple '/' factor
//   | simple '%' factor
// ;


// //make saleem see it 
// record_expession_access
//   : IDENTIFIER '.' IDENTIFIER 
//   | array_access_expression '.' IDENTIFIER 
//   | record_expession_access '.'  IDENTIFIER 
//   | record_expession_access '.' array_access_expression 
// ;

// recordType
//   : RECORD variableDeclerations END 
// ;

// //note this should be written without a semicolon 

// arrayType 
//   : ARRAY '[' expression ']' type 
// ;
// variableDeclerations 
//   : variableDecleration
//   | variableDecleration variableDeclerations
// ;

// typeDecleration 
//   : TYPE IDENTIFIER IS type 
// ;

// body :
//   statement
//   | simpleDeclaration
//   | statement body
//   | simpleDeclaration body
// ;

// statement :
//   iteration_statement
// ;

// iteration_statement
// 	: while_expression
//   |  for_expression
// ;
// while_expression :
//   WHILE expression LOOP body END
// ;
// for_expression :
//   FOR IDENTIFIER range LOOP body END  
// ;
// range :
//   IN expression RANGE expression 
//   | IN REVERSE expression RANGE expression
// ;
*/
%%

void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}