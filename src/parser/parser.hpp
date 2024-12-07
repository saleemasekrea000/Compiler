#ifndef PARSER_HPP
#define PARSER_HPP

#include "../lexer/token.hpp"
#include "ast.hpp"

int yylex();
extern void set_tokens(std::vector<Token>* token_vector);
extern AST_Node* root;


#endif // PARSER_HPP