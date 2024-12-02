#include "token.hpp"

Token::Token(TokenType t, const std::string &v)
    : type(t), content(v)
{
}

std::string Token::typeToString() const
{
    static std::unordered_map<TokenType, std::string> typeMap;
    static bool initialized = false;
    if (!initialized)
    {
        typeMap[TokenType::KEYWORD] = "KEYWORD";
        typeMap[TokenType::IS] = "IS";
        typeMap[TokenType::WHILE] = "WHILE";
        typeMap[TokenType::ROUTINE] = "ROUTINE";
        typeMap[TokenType::END] = "END";
        typeMap[TokenType::BREAK] = "BREAK";
        typeMap[TokenType::REVERSE] = "REVERSE";
        typeMap[TokenType::RETURN] = "RETURN";
        typeMap[TokenType::NOT] = "NOT";
        typeMap[TokenType::XOR] = "XOR";
        typeMap[TokenType::OR] = "OR";
        typeMap[TokenType::AND] = "AND";
        typeMap[TokenType::ELSE] = "ELSE";
        typeMap[TokenType::THEN] = "THEN";
        typeMap[TokenType::IF] = "IF";
        typeMap[TokenType::IN] = "IN";
        typeMap[TokenType::FOR] = "FOR";
        typeMap[TokenType::LOOP] = "LOOP";
        typeMap[TokenType::ARRAY] = "ARRAY";
        typeMap[TokenType::FALSE] = "FALSE";
        typeMap[TokenType::TRUE] = "TRUE";
        typeMap[TokenType::RECORD] = "RECORD";
        typeMap[TokenType::TYPE] = "TYPE";
        typeMap[TokenType::VAR] = "VAR";
        typeMap[TokenType::INTEGER_LITERAL_KEYWORD] = "INTEGER_LITERAL_KEYWORD";
        typeMap[TokenType::REAL_LITERAL_KEYWORD] = "REAL_LITERAL_KEYWORD";
        typeMap[TokenType::BOOLEAN_LITERAL_KEYWORD] = "BOOLEAN_LITERAL_KEYWORD";
        typeMap[TokenType::CONTINUE] = "CONTINUE";
        typeMap[TokenType::IDENTIFIER] = "IDENTIFIER";
        typeMap[TokenType::INTEGER_LITERAL] = "INTEGER_LITERAL";
        typeMap[TokenType::REAL_LITERAL] = "REAL_LITERAL";
        typeMap[TokenType::BOOLEAN_LITERAL] = "BOOLEAN_LITERAL";
        typeMap[TokenType::VAR_LITERAL] = "VAR_LITERAL";
        typeMap[TokenType::OPERATOR] = "OPERATOR";
        typeMap[TokenType::ERROR] = "ERROR";
        typeMap[TokenType::LPAR] = "LPAR";
        typeMap[TokenType::RPAR] = "RPAR";
        typeMap[TokenType::LBRAC] = "LBRAC";
        typeMap[TokenType::RBRAC] = "RBRAC";
        typeMap[TokenType::RELPAR] = "RELPAR";
        typeMap[TokenType::RERLPR] = "RERLPR";
        typeMap[TokenType::RANGE] = "RANGE";
        typeMap[TokenType::PUNCTUATOR] = "PUNCTUATOR";
        typeMap[TokenType::PRINT] = "PRINT";
        initialized = true;
    }
    return typeMap.at(type);
}

Token::operator std::string() const
{
    return typeToString() + " " + content + "\n";
}

std::ostream &operator<<(std::ostream &os, const Token &token)
{
    os << token.typeToString();
    os << " ";
    return os << token.content;
}