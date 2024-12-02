%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.hpp"
#include "ast.hpp"
#include "../semantic/semantic.hpp"
#include "../codegen/codegen.hpp"
 
int yylex();
void yyerror(char *s);
int counter = 1;
int indent = 0;
AST_Node* root;
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
%type <node> program simpleDeclaration variableDeclaration declarations identifier type primary_expression print_statement
%type <node> int_exp real_exp boolean_exp primary unary_op array_access_expression record_expession_access summand
%type <node> factor simple relation expression typeDecleration arrayType variableDeclerations recordType jumpStatement
%type <node> body while_expression iteration_statement statement range for_expression assign_expression IfStatement dimensionList
%type <node>return_exp break_exp continue_exp routine_call argument_expression_list parameter_decleration parameters_list routine_deceration

%start program 

%token <id_val> IDENTIFIER
%token <int_val> INTEGER_LITERAL
%token <real_val> REAL_LITERAL
%token <bool_val> BOOLEAN_LITERAL
%token <keyword_val> IS WHILE END ROUTINE VAR INTEGER_LITERAL_KEYWORD REAL_LITERAL_KEYWORD OR AND XOR NOT RANGE REVERSE
%token <keyword_val> BOOLEAN_LITERAL_KEYWORD RECORD ARRAY FOR RETURN THEN TRUE FALSE TYPE LOOP IN IF ELSE BREAK CONTINUE PRINT
%token LE_OP GE_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN ASSIGN_OP;
%%

program 
  : declarations { 
      $$ = new None_Terminal_Node("PROGRAM"); 
      $$->children.push_back($1); 
      print_ast($$, 0,"output.txt");
      root = $$;

      Codegen codegen_llvm(root);
      codegen_llvm.start_llvm(root);
    }
  ;

declarations
  : declarations simpleDeclaration {
      $$ = $1;
      $$->children.push_back($2);
    }
  | declarations statement {
      $$ = $1;
      $$->children.push_back($2);
    }
  | declarations routine_deceration {
       $$ = $1;
       $$->children.push_back($2);
     }

  | /* empty */ {
      $$ = new None_Terminal_Node("DECLARATION"); 
    }
  ;

routine_deceration 
   : ROUTINE identifier '(' parameters_list ')' IS body END{
      $$ = new None_Terminal_Node("ROUTINE_DECLERATION");
      $$->children.push_back($2);
      $$->children.push_back($4);
      $$->children.push_back($7);
   }
   | ROUTINE identifier '(' parameters_list ')' ':' type IS body END{
      $$ = new None_Terminal_Node("ROUTINE_DECLERATION");
      $$->children.push_back($2);
      $$->children.push_back($4);
      $$->children.push_back($9);
      $$->children.push_back($7);
   } 
;
parameters_list 
  : parameter_decleration {
      $$ = new None_Terminal_Node("PARAMETERS_EXPRESSION_LIST");
      $$->children.push_back($1);
    }
  | parameters_list',' parameter_decleration {
      $$ = $1;
      $$->children.push_back($3);
    }
  | /* empty */ {
      $$ = new None_Terminal_Node("PARAMETERS_EXPRESSION_LIST");
    }
;
parameter_decleration 
    : identifier ':' type  { 
      $$ = new None_Terminal_Node("PARAMETER_DECLERATION");
      $$->children.push_back($1);
      $$->children.push_back($3);
    } 
;
simpleDeclaration 
  : variableDeclaration { 
      $$ = new None_Terminal_Node("SIMPLE_DECLARATION");
      $$->children.push_back($1);
    }
  | typeDecleration{
      $$ = new None_Terminal_Node("SIMPLE_DECLARATION");
      $$->children.push_back($1);
  }
;

variableDeclaration
  : VAR identifier IS expression ';' { 
      $$ = new None_Terminal_Node("VARIABLE_DECLARATION");
      $$->children.push_back($2);
      $$->children.push_back(new Type_Node("none"));
      $$->children.push_back($4);
    }
  | VAR identifier ':' type IS expression ';' { 
      $$ = new None_Terminal_Node("VARIABLE_DECLARATION");
      $$->children.push_back($2);
      $$->children.push_back($4);
      $$->children.push_back($6);
    }
  | VAR identifier ':' type';' { 
      $$ = new None_Terminal_Node("VARIABLE_DECLARATION");
      $$->children.push_back($2);
      $$->children.push_back($4);
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
  | recordType{
      $$ = new Type_Node("recordType");
      $$->children.push_back($1);
  }
  | arrayType{
      $$ = new Type_Node("arrayType");
      $$->children.push_back($1);
  }
;

// normal primary_expression 
primary_expression
	: int_exp{
    $$ = new None_Terminal_Node("PRIMARY_EXPRESSION");
    $$->children.push_back($1);
  }
  | real_exp{
    $$ = new None_Terminal_Node("PRIMARY_EXPRESSION");
    $$->children.push_back($1);
  }
  | boolean_exp{
    $$ = new None_Terminal_Node("PRIMARY_EXPRESSION");
    $$->children.push_back($1);
  }
  | unary_op primary{
    $$ = new None_Terminal_Node("PRIMARY_EXPRESSION");
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
	| identifier{
    $$ = new None_Terminal_Node("PRIMARY_EXPRESSION");
    $$->children.push_back($1);
  }
;
unary_op:
   NOT{
    $$ = new Operator("!");
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
    $$ = new None_Terminal_Node("PRIMARY_NODE");
    $$->children.push_back($1);
  }    
  | array_access_expression{
    $$ = new None_Terminal_Node("PRIMARY_NODE");
    $$->children.push_back($1);
  }     
  | record_expession_access{
    $$ = new None_Terminal_Node("PRIMARY_NODE");
    $$->children.push_back($1);
  }
  | routine_call{
    $$ = new None_Terminal_Node("PRIMARY_NODE");
    $$->children.push_back($1);
  }
;

routine_call
  : identifier '(' argument_expression_list ')' {
      $$ = new None_Terminal_Node("Routine_Call");
      $$->children.push_back($1);
      $$->children.push_back($3);
    }
;

argument_expression_list
  : expression {
      $$ = new None_Terminal_Node("Argument_Expression_List");
      $$->children.push_back($1);
    }
  | argument_expression_list ',' expression {
      $$ = $1;
      $$->children.push_back($3);
    }
  | /* empty */ {
      $$ = new None_Terminal_Node("Argument_Expression_List");
    }
;

record_expession_access
   : identifier '.' identifier {
     $$ = new None_Terminal_Node("RECORD_ACCESS");
     $$->children.push_back($1);
     $$->children.push_back($3);
   }
    | array_access_expression '.' identifier {
     $$ = new None_Terminal_Node("RECORD_ACCESS");
     $$->children.push_back($1);
     $$->children.push_back($3);
   } 
   | array_access_expression '.' record_expession_access {
     $$ = new None_Terminal_Node("RECORD_ACCESS");
     $$->children.push_back($1);
     $$->children.push_back($3);
   } 
   | identifier '.'  record_expession_access {
     $$ = new None_Terminal_Node("RECORD_ACCESS");
     $$->children.push_back($1);
     $$->children.push_back($3);
   }
   /* | record_expession_access '.' array_access_expression {
     $$ = new None_Terminal_Node("RECORD_ACCESS");
     $$->children.push_back($1);
     $$->children.push_back($3);
   } */
;

summand
   : primary{
      $$ = new None_Terminal_Node("SUMMAND");
      $$->children.push_back($1);
   }
   | '(' expression ')'{
      $$ = new None_Terminal_Node("SUMMAND");
      $$->children.push_back($2);
   }
;


factor
   : summand{
      $$ = new None_Terminal_Node("FACTOR");
      $$->children.push_back($1);
   }
   | factor '*' summand{
      $$ = new None_Terminal_Node("FACTOR");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("*"));
      $$->children.push_back($3);
   }
   | factor '/' summand{
      $$ = new None_Terminal_Node("FACTOR");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("/"));
      $$->children.push_back($3);
   }
   | factor '%' summand{
      $$ = new None_Terminal_Node("FACTOR");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("%"));
      $$->children.push_back($3);
   }
;

simple
   : factor{
      $$ = new None_Terminal_Node("SIMPLE");
      $$->children.push_back($1);
   }
   | simple '+' factor{
      $$ = new None_Terminal_Node("SIMPLE");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("+"));
      $$->children.push_back($3);
   }
   | simple '-' factor{
      $$ = new None_Terminal_Node("SIMPLE");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("-"));
      $$->children.push_back($3);
   }
 ;

relation
   : simple{
      $$ = new None_Terminal_Node("RELATION");
      $$->children.push_back($1);
   }
   | simple '<' simple{
      $$ = new None_Terminal_Node("RELATION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("<"));
      $$->children.push_back($3);
   }
   | simple LE_OP simple{
      $$ = new None_Terminal_Node("RELATION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("<="));
      $$->children.push_back($3);
   }
   | simple '>' simple{
      $$ = new None_Terminal_Node("RELATION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator(">"));
      $$->children.push_back($3);
   }
   | simple GE_OP simple{
      $$ = new None_Terminal_Node("RELATION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator(">="));
      $$->children.push_back($3);
   }
   | simple '=' simple{
      $$ = new None_Terminal_Node("RELATION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("="));
      $$->children.push_back($3);
   }
   | simple SUB_ASSIGN simple{
      $$ = new None_Terminal_Node("RELATION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("-="));
      $$->children.push_back($3);
   }
   | simple ADD_ASSIGN simple{
      $$ = new None_Terminal_Node("RELATION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("+="));
      $$->children.push_back($3);
   }
   | simple MUL_ASSIGN simple{
      $$ = new None_Terminal_Node("RELATION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("*="));
      $$->children.push_back($3);
   }
   | simple DIV_ASSIGN simple{
      $$ = new None_Terminal_Node("RELATION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("/="));
      $$->children.push_back($3);
   }
   | simple MOD_ASSIGN simple{
      $$ = new None_Terminal_Node("RELATION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("%="));
      $$->children.push_back($3);
   }
;


 expression
   : relation {
      $$ = new None_Terminal_Node("EXPRESSION");
      $$->children.push_back($1);
   }
   | relation AND relation{
      $$ = new None_Terminal_Node("EXPRESSION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("and"));
      $$->children.push_back($3);
   }
   | relation OR relation{
      $$ = new None_Terminal_Node("EXPRESSION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("or"));
      $$->children.push_back($3);
   }
   | relation XOR relation{
      $$ = new None_Terminal_Node("EXPRESSION");
      $$->children.push_back($1);
      $$->children.push_back(new Operator("xor"));
      $$->children.push_back($3);
   }
 ;


typeDecleration 
   : TYPE identifier IS type ';' {
    $$ = new None_Terminal_Node("TYPE_DECLARATION");
    $$->children.push_back($2);
    $$->children.push_back($4);
   }
;

recordType
   : RECORD '{' variableDeclerations '}' END {
      $$ = new None_Terminal_Node("RECORD_TYPE");
      $$->children.push_back($3);
   }
;

variableDeclerations
  : variableDeclerations variableDeclaration {
      $$ = $1;
      $$->children.push_back($2);
    }
    | /* empty */ {
      $$ = new None_Terminal_Node("VARIABLE_DECLARATIONS");
    }
;

array_access_expression  
  : identifier dimensionList {
    $$ = new None_Terminal_Node("ARRAY_ACCESS");
    $$->children.push_back($1);
    $$->children.push_back($2);
  }
;

arrayType
    : ARRAY dimensionList type {
        $$ = new None_Terminal_Node("ARRAY_TYPE");
        $$->children.push_back($2); 
        $$->children.push_back($3); 
    }
;

dimensionList
    : '[' expression ']' {
        $$ = new None_Terminal_Node("DIMENSION_LIST");
        $$->children.push_back($2); 
    }
    | dimensionList '[' expression ']' {
        $$ = $1; 
        $$->children.push_back($3); 
    }
;


statement :
   iteration_statement{
    $$ = new None_Terminal_Node("STATEMENT");
    $$->children.push_back($1);
   }
   | assign_expression{
    $$ = new None_Terminal_Node("STATEMENT");
    $$->children.push_back($1);
   }
   | IfStatement{
    $$ = new None_Terminal_Node("STATEMENT");
    $$->children.push_back($1);
   }
   | jumpStatement{
    $$ = new None_Terminal_Node("STATEMENT");
    $$->children.push_back($1);
   }
   | routine_call ';' {
    $$ = new None_Terminal_Node("STATEMENT");
    $$->children.push_back($1);
   }
   | print_statement ';'{
    $$ = new None_Terminal_Node("STATEMENT");
    $$->children.push_back($1);
   }
;
print_statement 
  : PRINT '(' expression ')' {
     $$ =  new None_Terminal_Node("PRINT_STATMENT");
     $$->children.push_back($3);
  }
;
jumpStatement 
  : return_exp {
    $$ = new None_Terminal_Node("JUMP_STATEMENT");
    $$->children.push_back($1);
  }
  | continue_exp {
    $$ = new None_Terminal_Node("JUMP_STATEMENT");
    $$->children.push_back($1);
  }
  | break_exp {
    $$ = new None_Terminal_Node("JUMP_STATEMENT");
    $$->children.push_back($1);
  }
;
return_exp
 : RETURN ';'{
   $$ = new None_Terminal_Node("RETURN_EX");
 }
 | RETURN expression ';' {
     $$ = new None_Terminal_Node("RETURN_EX");
     $$->children.push_back($2);
 }
;
continue_exp 
 : CONTINUE ';'{
     $$ = new None_Terminal_Node("CONTINUE_EX");
 }
;
break_exp 
 : BREAK ';'{
     $$ = new None_Terminal_Node("BREAK_EX");
 }
;

IfStatement
  : IF expression THEN body END {
    $$ = new None_Terminal_Node("IF_STATEMENT");
    $$->children.push_back($2);
    $$->children.push_back($4);
  }
  | IF expression THEN body ELSE body END {
    $$ = new None_Terminal_Node("IF_STATEMENT_ELSE");
    $$->children.push_back($2);
    $$->children.push_back($4);
    $$->children.push_back($6);
  }
;
assign_expression 
   //fiix the += and its sisters 
  : primary ASSIGN_OP expression ';'{
    $$ = new None_Terminal_Node("ASSIGN_STATEMENT");
    $$->children.push_back($1);
    $$->children.push_back(new Operator(":="));
    $$->children.push_back($3);
  }
  | identifier SUB_ASSIGN expression ';'{
    $$->children.push_back($1);
    $$->children.push_back(new Operator("-="));
    $$->children.push_back($3);
  }
  | identifier ADD_ASSIGN expression ';'{
    $$->children.push_back($1);
    $$->children.push_back(new Operator("+="));
    $$->children.push_back($3);
  }
  | identifier MUL_ASSIGN expression ';'{
    $$->children.push_back($1);
    $$->children.push_back(new Operator("*="));
    $$->children.push_back($3);
  }
  | identifier DIV_ASSIGN expression ';'{
    $$->children.push_back($1);
    $$->children.push_back(new Operator("/="));
    $$->children.push_back($3);
  }
  | identifier MOD_ASSIGN expression ';'{
    $$->children.push_back($1);
    $$->children.push_back(new Operator("%="));
    $$->children.push_back($3);
  }
;

iteration_statement
 	: while_expression{
    $$ = new None_Terminal_Node("ITERATION_STATEMENT");
    $$->children.push_back($1);
  }
  | for_expression{
    $$ = new None_Terminal_Node("ITERATION_STATEMENT");
    $$->children.push_back($1);
  }
;
while_expression :
   WHILE expression LOOP body END{
    $$ = new None_Terminal_Node("WHILE_STATEMENT");
    $$->children.push_back($2);
    $$->children.push_back($4);
   }
;
body 
  : body simpleDeclaration {
      $$ = $1;
      $$->children.push_back($2);
    }
  | body statement {
       $$ = $1;
       $$->children.push_back($2);
    }
  | /* empty */ {
      $$ = new None_Terminal_Node("BODY"); 
    }
  ;

for_expression :
   FOR identifier range LOOP body END{
      $$ = new None_Terminal_Node("FOR_STATEMENT");
      $$->children.push_back($2);
      $$->children.push_back($3);
      $$->children.push_back($5);
   }  
;
range :
   IN expression RANGE expression {
     $$ = new None_Terminal_Node("RANGE_EX");
     $$->children.push_back($2);
     $$->children.push_back($4);
   } 
   | IN REVERSE expression RANGE expression{
     $$ = new None_Terminal_Node("RANGE_REVERSE");
     $$->children.push_back($3);
     $$->children.push_back($5);
   }
;

%%

void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}