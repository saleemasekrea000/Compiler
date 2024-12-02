#ifndef LEXER_HPP
#define LEXER_HPP

#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>

#include "token.hpp"

using namespace std;

class Lexer
{
private:
    vector<Token> *tokenized_code;
    vector<string> *error_messages;
    const int keywords_number = 9;
    ifstream fin;
    string code = "";
    int ind = 0;
    unordered_map<string, TokenType> keywords;

    void initKeywords();
    bool is_identifier(const string &s);
    bool is_bracket(char c);
    bool is_boolean(const string &s);
    bool is_integer(const string &s);
    bool is_real(const string &s);
    bool is_literal(const string &s);
    bool is_keyword(const string &s);
    bool is_pancutator(char c);
    bool is_operator(const std::string &s);
    TokenType token_type(const string &s);
    string next_token_content(Token last_token);
    Token next_token(Token last_token);

public:
    Lexer(string filename);
    ~Lexer();
    vector<Token> *scan_code();
    void print_errors();
};

#endif // LEXER_HPP