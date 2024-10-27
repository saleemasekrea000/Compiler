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

%type <node> program primary_expression argument_expression_list unary_expression 
%type <node> unary_operator cast_expression multiplicative_expression additive_expression relational_expression and_expression 
%type <node> exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression

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

program : 
  statement ;

// normal primary_expression 
primary_expression
	: IDENTIFIER
  | INTEGER_LITERAL
//   | REAL_LITERAL
//   | BOOLEAN_LITERAL
// 	| '(' expression ')'
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

unary_expression
	: postfix_expression
	;

cast_expression
	: unary_expression
	// | '(' type_specifier ')' cast_expression
	;

// multiplicative_expression
// 	: cast_expression
// 	| multiplicative_expression '*' cast_expression
// 	| multiplicative_expression '/' cast_expression
// 	| multiplicative_expression '%' cast_expression
// 	;

// additive_expression
// 	: multiplicative_expression
// 	| additive_expression '+' multiplicative_expression
// 	| additive_expression '-' multiplicative_expression
// 	;

// relational_expression
// 	: additive_expression
// 	| relational_expression '<' additive_expression
// 	| relational_expression '>' additive_expression
// 	| relational_expression LE_OP additive_expression
// 	| relational_expression GE_OP additive_expression
// 	;

// equality_expression
// 	: relational_expression
// 	| equality_expression '=' relational_expression
// 	| equality_expression NE_OP relational_expression
// 	;

// and_expression
// 	: equality_expression
// 	| and_expression AND equality_expression
// 	;

// exclusive_or_expression
// 	: and_expression
// 	| exclusive_or_expression XOR and_expression
// 	;

// inclusive_or_expression
// 	: exclusive_or_expression
// 	| inclusive_or_expression OR exclusive_or_expression
// 	;

// logical_and_expression
// 	: inclusive_or_expression
// 	| logical_and_expression AND_OP inclusive_or_expression
// 	;

// logical_or_expression
// 	: logical_and_expression
// 	| logical_or_expression OR_OP logical_and_expression
// 	;

// conditional_expression
// 	: logical_or_expression
// 	;

// assignment_expression
// 	: conditional_expression
// 	| unary_expression assignment_operator assignment_expression
// 	;

// assignment_operator
// 	: ASSIGN_OP
// 	| MUL_ASSIGN
// 	| DIV_ASSIGN
// 	| MOD_ASSIGN
// 	| ADD_ASSIGN
// 	| SUB_ASSIGN
// 	;

// expression
// 	: assignment_expression
// 	| expression ',' assignment_expression
// 	;

// constant_expression
// 	: conditional_expression
// 	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator ';'
	;

declaration_specifiers
	: type_specifier
	| type_specifier declaration_specifiers
	;
record_specifier
    : TYPE IDENTIFIER ':' RECORD '{' record_field_list '}' END // Named record definition
    ;

record_field_list
    : record_field
    | record_field_list record_field
    ;

record_field
    : VAR IDENTIFIER ':' type_specifier ';'  // Field declaration with explicit type
    ;

array_type_specifier
    : TYPE IDENTIFIER IS ARRAY '[' array_size ']' type_specifier  ';'
    ;

array_size
    : expression                                  // Expression defining a compile-time constant size
    ;

type_specifier
    : INTEGER_LITERAL_KEYWORD
    | REAL_LITERAL_KEYWORD
    | BOOLEAN_LITERAL_KEYWORD
    | IDENTIFIER                                  // Named types, including records or other types
    | record_specifier                            // Record as a type
    | array_type_specifier                        // Array as a type
    ;

init_declarator
	: declarator
	| declarator IS initializer
	;

declarator
	: direct_declarator
	;

direct_declarator 
  :IDENTIFIER
;

initializer
	: assignment_expression
;

statement
	: expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF  expression THEN statement END
	| IF  expression  THEN statement ELSE statement ELSE 
	;

iteration_statement
	: WHILE expression LOOP statement END
  | FOR IDENTIFIER IN expression RANGE expression LOOP statement END
	;

jump_statement 
	: CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;


%%

void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}