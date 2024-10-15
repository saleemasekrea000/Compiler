%{
  #include <iostream>
  #include <cctype>
  #include <cstring>
  #include <vector>
  #include <stack>

  #include "ast.hpp"

  using namespace std;

  void yyerror (const char *error);
  int  yylex ();
  void clear_stack ();
  
    int vars ['Z'- 'A' + 1];

  stack <Expression *> nodes;
%}

%token IDENT NUMBER

%union {
  Expression *exp;  /* For the expressions. Since it is a pointer, no problem. */
  int       value;  /* For the lexical analyser. NUMBER tokens */
  char      ident;  /* For the lexical analyser. IDENT tokens */
}

/* Lets inform Bison about the type of each terminal and non-terminal */
%type <exp>   exp
%type <value> NUMBER
%type <ident> IDENT

/* Precedence information to resolve ambiguity */
%left '+'
%left '*'
%%

prompt : exp  '\n'             { 
                                 if ($1) {
                                   cout << $1->value () << endl;
                                   clear_stack ();
                                 }
                               }
       |  prompt  exp  '\n'    {
                                 if ($2) {
                                   cout << $2->value () << endl;
                                   clear_stack ();
                                 }
                               }
       | error '\n'            { clear_stack (); }
       ;

exp : exp '+' exp              {
                                 $$ = new Plus ($1, $3);
                                 nodes.pop ();  //  The childreen are handled by Plus so we
                                 nodes.pop ();  // take them of the allocated nodes stack.
                                 nodes.push ($$);
                               }
    | exp '*' exp              {
                                 $$ = new Times ($1, $3);
                                 nodes.pop ();  // The same as above.
                                 nodes.pop ();
                                 nodes.push ($$);
                               } 
    | IDENT                    { $$ = new Ident (&vars [$1 - 'A']); nodes.push ($$); } 
    | NUMBER                   { $$ = new Number ($1); nodes.push ($$); } 
    | IDENT '=' exp            { vars [$1 - 'A'] = $3->value (); $$ = $3; nodes.push ($$); } 
    ;
%%