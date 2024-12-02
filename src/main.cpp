#include <iostream>
#include <fstream>

#include "lexer/lexer.hpp"
#include "parser/parser.hpp"
#include "parser/grammar.tab.h"
#include "parser/ast.hpp"
#include "semantic/semantic.hpp"
#include "codegen/codegen.hpp"

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

    // Print tokens to tokens.txt
    ofstream tokens_file("tokens.txt");
    for (auto token : *tokens)
    {
        tokens_file << token.typeToString() << " " << token.content << endl;
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
        Semantic_Analysis semantic_analysis(root);
        semantic_analysis.Semantic_Analysis_Checks(root);
        semantic_analysis.optimize(root);
        print_ast(root, 0, "optimize.txt");
    }

    delete tokens;
    
    return 0;
}