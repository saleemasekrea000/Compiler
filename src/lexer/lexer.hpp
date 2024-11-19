
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

    void initKeywords()
    {
        keywords["is"] = TokenType::KEYWORD;
        keywords["type"] = TokenType::KEYWORD;
        keywords["record"] = TokenType::KEYWORD;
        keywords["end"] = TokenType::KEYWORD;
        keywords["true"] = TokenType::KEYWORD;
        keywords["false"] = TokenType::KEYWORD;
        keywords["array"] = TokenType::KEYWORD;
        keywords["while"] = TokenType::KEYWORD;
        keywords["loop"] = TokenType::KEYWORD;
        keywords["for"] = TokenType::KEYWORD;
        keywords["in"] = TokenType::KEYWORD;
        keywords["reverse"] = TokenType::KEYWORD;
        keywords["if"] = TokenType::KEYWORD;
        keywords["then"] = TokenType::KEYWORD;
        keywords["else"] = TokenType::KEYWORD;
        keywords["routine"] = TokenType::KEYWORD;
        keywords["and"] = TokenType::KEYWORD;
        keywords["xor"] = TokenType::KEYWORD;
        keywords["or"] = TokenType::KEYWORD;
        keywords["not"] = TokenType::KEYWORD;
        keywords["foreach"] = TokenType::KEYWORD;
        keywords["from"] = TokenType::KEYWORD;
        keywords["return"] = TokenType::KEYWORD;
        keywords["reverse"] = TokenType::KEYWORD;
        keywords["continue"] = TokenType::KEYWORD;
        keywords["integer"] = TokenType::KEYWORD;
        keywords["real"] = TokenType::KEYWORD;
        keywords["boolean"] = TokenType::KEYWORD;
        keywords["var"] = TokenType::KEYWORD;
        keywords["break"] = TokenType::KEYWORD;
        keywords["print"] = TokenType::KEYWORD;
        
    }
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
    Lexer(string filename)
    {
        fin.open(filename);
        initKeywords();
        tokenized_code = new vector<Token>;
        error_messages = new vector<string>;
    }

    ~Lexer()
    {
        if (fin.is_open())
        {
            fin.close();
        }
    }
    vector<Token> *scan_code();
    void print_errors();
};