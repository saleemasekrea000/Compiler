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
        typeMap[KEYWORD] = "KEYWORD";
        typeMap[IS] = "IS";
        typeMap[WHILE] = "WHILE";
        typeMap[ROUTINE] = "ROUTINE";
        typeMap[END] = "END";
        typeMap[BREAK] = "BREAK";
        typeMap[REVERSE] = "REVERSE";
        typeMap[RETURN] = "RETURN";
        typeMap[NOT] = "NOT";
        typeMap[XOR] = "XOR";
        typeMap[OR] = "OR";
        typeMap[AND] = "AND";
        typeMap[ELSE] = "ELSE";
        typeMap[THEN] = "THEN";
        typeMap[IF] = "IF";
        typeMap[IN] = "IN";
        typeMap[FOR] = "FOR";
        typeMap[LOOP] = "LOOP";
        typeMap[ARRAY] = "ARRAY";
        typeMap[FALSE] = "FALSE";
        typeMap[TRUE] = "TRUE";
        typeMap[RECORD] = "RECORD";
        typeMap[TYPE] = "TYPE";
        typeMap[VAR] = "VAR";
        typeMap[INTEGER_LITERAL_KEYWORD] = "INTEGER_LITERAL_KEYWORD";
        typeMap[REAL_LITERAL_KEYWORD] = "REAL_LITERAL_KEYWORD";
        typeMap[BOOLEAN_LITERAL_KEYWORD] = "BOOLEAN_LITERAL_KEYWORD";
        typeMap[CONTINUE] = "CONTINUE";
        typeMap[IDENTIFIER] = "IDENTIFIER";
        typeMap[INTEGER_LITERAL] = "INTEGER_LITERAL";
        typeMap[REAL_LITERAL] = "REAL_LITERAL";
        typeMap[BOOLEAN_LITERAL] = "BOOLEAN_LITERAL";
        typeMap[VAR_LITERAL] = "VAR_LITERAL";
        typeMap[OPERATOR] = "OPERATOR";
        typeMap[ERROR] = "ERROR";
        typeMap[LPAR] = "LPAR";
        typeMap[RPAR] = "RPAR";
        typeMap[LBRAC] = "LBRAC";
        typeMap[RBRAC] = "RBRAC";
        typeMap[RELPAR] = "RELPAR";
        typeMap[RERLPR] = "RERLPR";
        typeMap[RANGE] = "RANGE";
        typeMap[PUNCTUATOR] = "PUNCTUATOR";
        typeMap[PRINT] = "PRINT";
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