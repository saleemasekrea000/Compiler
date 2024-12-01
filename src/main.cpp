#include <iostream>
#include <fstream>

#include "./lexer/lexer.hpp"

using namespace std;

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

    Lexer lexer(file_name);
    vector<Token> *tokens = lexer.scan_code();
    if (tokens == NULL)
    {
        lexer.print_errors();
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