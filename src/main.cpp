#include <iostream>
#include <fstream>

#include "lexer/lexer.hpp"
#include "parser/parser.hpp"
#include "parser/grammar.tab.h"
#include "parser/ast.hpp"

using namespace std;

extern void set_tokens(vector<Token>* tokens);
extern AST_Node* root;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "ERROR \n";
        return 0;
    }

    string file_name = argv[1];
    ifstream file(file_name);
    if (!file.good())
    {
        cout << "Error: file " << argv[1] << " doesn't exists\n";
        exit(1);
    }

    // Lexing
    Lexer lexer(file_name);
    vector<Token> *tokens = lexer.scan_code();
    if (tokens == nullptr)
    {
        lexer.print_errors();
        return 1;
    }

    // Parsing
    set_tokens(tokens); // Set the tokens for the parser
    if (yyparse() != 0)
    {
        cout << "Error: Parsing failed.\n";
        delete tokens;
        return 1;
    }

    // Access the root node of the AST
    if (root != nullptr)
    {
        // Saleem, this means the root is successfully assigned to program.
    }

    delete tokens;
    
    return 0;
}