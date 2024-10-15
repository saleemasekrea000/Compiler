%{
#include "ast.h"
%}

%union {
    Node* node;
    BlockNode* block;
    ExpressionNode* expr;
    std::string* string;
    int token;
}

%token <string> IDENTIFIER
%token <token> INTEGER_LITERAL
%token <token> KEY
%token <token> OPERATOR
%token <token> PUNCTUATOR

%%

program: routine { $$ = new ProgramNode($1); };

routine: KEYWORD IDENTIFIER '(' parameters ')' KEYWORD block KEYWORD { $$ = new RoutineNode($2, $4, $7); };

parameters: /* empty */ { $$ = new std::vector<VariableDeclarationNode*>(); }
          | parameters ',' parameter { $1->push_back($3); $$ = $1; }
          | parameter { $$ = new std::vector<VariableDeclarationNode*>(1, $1); };

parameter: IDENTIFIER ':' IDENTIFIER { $$ = new VariableDeclarationNode($1, $3); };

block: /* empty */ { $$ = new BlockNode(); }
     | block statement { $1->add_statement($2); $$ = $1; };

statement: assignment
         | while_loop
         | return_statement
         | function_call
         ;

assignment: IDENTIFIER OPERATOR expression ';' { $$ = new AssignmentNode($1, $3); };

while_loop: KEYWORD expression KEYWORD block KEYWORD { $$ = new WhileNode($2, $4); };

return_statement: KEYWORD expression ';' { $$ = new ReturnNode($2); };

function_call: IDENTIFIER '(' arguments ')' ';' { $$ = new FunctionCallNode($1, $3); };

arguments: /* empty */ { $$ = new std::vector<ExpressionNode*>(); }
         | arguments ',' expression { $1->push_back($3); $$ = $1; }
         | expression { $$ = new std::vector<ExpressionNode*>(1, $1); };

expression: IDENTIFIER { $$ = new IdentifierNode($1); }
          | INTEGER_LITERAL { $$ = new IntegerLiteralNode($1); }
          | expression OPERATOR expression { $$ = new BinaryOperationNode($1, $2, $3); }
          ;

%%