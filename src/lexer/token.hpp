#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <string>
#include <unordered_map>

enum TokenType
{
    KEYWORD,
    IS,
    WHILE,
    ROUTINE,
    END,
    BREAK,
    RETURN,
    NOT,
    XOR,
    OR,
    AND,
    ELSE,
    THEN,
    IF,
    IN,
    FOR,
    LOOP,
    ARRAY,
    FALSE,
    TRUE,
    RECORD,
    TYPE,
    VAR,
    INTEGER_LITERAL_KEYWORD,
    REAL_LITERAL_KEYWORD,
    BOOLEAN_LITERAL_KEYWORD,
    CONTINUE,
    IDENTIFIER,
    INTEGER_LITERAL,
    REAL_LITERAL,
    BOOLEAN_LITERAL,
    VAR_LITERAL,
    OPERATOR,
    ERROR,
    LPAR,
    RPAR,
    LBRAC,
    RBRAC,
    RELPAR,
    RERLPR,
    RANGE,
    PUNCTUATOR,
    REVERSE,
    PRINT,
};

class Token
{
public:
    TokenType type;
    std::string content;
    Token() {}
    Token(TokenType t, const std::string &v);

    std::string typeToString() const;

    operator std::string() const;

    friend std::ostream &operator<<(std::ostream &os, const Token &token);
};

#endif // TOKEN_HPP