#include <iostream>
#include <fstream>

#include "lexer.hpp"
#include "ast.hpp"

extern int yyparse();
extern Node *ast;

Lexer *lexer;
Token yylval;

int yylex()
{
    yylval = lexer->next_token(yylval);
    return yylval.type;
}

void yyerror(const char *s)
{
    std::cerr << "Parse error: " << s << std::endl;
    exit(1);
}

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

    string output_file_name = "lexer_tests_outputs" + file_name.substr(file_name.find_last_of("/"));

    output_file_name = output_file_name.substr(0, file_name.find_last_of(".") + 1) + "_tokens.txt";
    cout << "Generating: " << output_file_name << endl;
    // Redirect cout to the output file
    freopen(output_file_name.c_str(), "w", stdout);

    lexer = new Lexer(file_name);
    yyparse();

    vector<Token> *tokens = lexer->scan_code();
    if (tokens == NULL)
    {
        lexer->print_errors();
    }
    else
    {
        for (const Token &token : *tokens)
        {
            cout << token << endl;
        }
        delete tokens;
    }
    return 0;
}