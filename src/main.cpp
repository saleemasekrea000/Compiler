#include <iostream>
#include <fstream>

#include "lexer/lexer.hpp"
#include "parser/ast.hpp"
#include "parser/grammar.tab.h"

using namespace std;

extern int yyparse();
extern void set_tokens(vector<Token> &tokens);

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

    // Run the lexer
    Lexer lexer(file_name);
    vector<Token> *tokens = lexer.scan_code();
    if (tokens == NULL)
    {
        lexer.print_errors();
        return 1;
    }

    // Set the tokens for the parser
    set_tokens(*tokens);

    // Run the parser
    if (yyparse() != 0)
    {
        cout << "Parsing failed\n";
        delete tokens;
        return 1;
    }

    delete tokens;
    return 0;
}
