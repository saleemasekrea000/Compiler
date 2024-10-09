#include <string>

using namespace std;

enum TokenType
{
    KEYWORD,
    IDENTIFIER,
    INTEGER_LITERAL,
    REAL_LITERAL,
    BOOL_LITERAL,
    VAR_LITERAL,
    OPERATOR,
    ERROR,
    LPAR,
    RPAR,
    LBRAC,
    RBRAC,
    PUNCTUATOR

};

class Token
{

public:
    TokenType type;
    string content;
    Token() {}
    Token(TokenType t, const string &v)
        : type(t), content(v)
    {
    }
    string typeToString() const
    {
        static unordered_map<TokenType, string> typeMap{
            {KEYWORD, "KEYWORD"},
            {IDENTIFIER, "IDENTIFIER"},
            {INTEGER_LITERAL, "INTEGER_LITERAL"},
            {REAL_LITERAL, "REAL_LITERAL"},
            {BOOL_LITERAL, "BOOL_LITERAL"},
            {VAR_LITERAL, "VAR_LITERAL"},
            {OPERATOR, "OPERATOR"},
            {ERROR, "ERROR"},
            {LPAR, "LPAR"},
            {RPAR, "RPAR"},
            {LBRAC, "LBRAC"},
            {RBRAC, "RBRAC"},
            {PUNCTUATOR, "PUNCTUATOR"}};
        return typeMap.at(type);
    }

    operator string() const
    {
        return typeToString() + " " + content + "\n";
    }
    friend ostream &operator<<(ostream &os, const Token &token)
    {
        return os << token.typeToString() << " " << token.content;
    }
};
