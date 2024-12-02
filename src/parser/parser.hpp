#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include "../lexer/token.hpp"
#include "ast.hpp"

int yylex();
extern void set_tokens(vector<Token>* token_vector);
extern int yyparse();
extern AST_Node* root;


#endif // PARSER_HPP