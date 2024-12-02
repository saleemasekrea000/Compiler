#include <string>
#include <iostream>
#include <regex>
#include <unordered_set>
#include <fstream>
#include <unordered_map>

#include "lexer.hpp"

Lexer::Lexer(string filename)
{
    fin.open(filename);
    initKeywords();
    tokenized_code = new vector<Token>;
    error_messages = new vector<string>;
}

Lexer::~Lexer()
{
    if (fin.is_open())
    {
        fin.close();
    }
}

void Lexer::initKeywords()
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

string Lexer::next_token_content(Token last_token)
{
    while (ind < code.size() && (code[ind] == ' ' || code[ind] == '\n' || code[ind] == '\t'))
        ind++;
    if (ind >= code.size())
    {
        return "";
    }
    string ret = "";
    while (code[ind] != ' ' && code[ind] != '\n' && code[ind] != '\t')
    {
        if (code[ind] == '/' && code[ind + 1] == '/')
        {
            while (code[ind] != '\n' && code[ind] != EOF)
                ind++;
            if (ret == "")
                return next_token_content(last_token);
            break;
        }
        if (is_bracket(code[ind]))
        {
            if (ret != "")
                return ret;
            ret = code[ind];
            ind++;
            return ret;
        }

        if (code[ind] == '.')
        {
            if (ret == "" && code[ind + 1] == '.' && code[ind + 2] == ' ')
            {
                ind += 2;
                return "..";
            }
            if (is_identifier(ret) && isalpha(code[ind + 1]))
            {
                return ret;
            }
            if (ret == "" && last_token.type == IDENTIFIER && isalpha(code[ind + 1]))
            {
                ret += code[ind];
                ind++;
                return ret;
            }
            if (ret == "" && last_token.type == RBRAC && isalpha(code[ind + 1]))
            {
                ret += code[ind];
                ind++;
                return ret;
            }
        }
        string cur = "";
        cur += code[ind];
        if (ret != "" && (is_operator(cur)))
        {
            return ret;
        }
        if (ret == "" && (is_operator(cur)))
        {
            if (code[ind] == '-' || code[ind] == '+') 
    {
        if (last_token.type == IDENTIFIER || last_token.type == REAL_LITERAL || last_token.type == INTEGER_LITERAL || last_token.type == BOOLEAN_LITERAL) 
        {
            ret += code[ind];
            ind++;
            return ret;
        } 
        else if (isdigit(code[ind + 1])) 
        {
            ret += code[ind];  
            ind++;
            while (ind < code.size() && isdigit(code[ind])) 
            {
                ret += code[ind];  
                ind++;
            }
            return ret; 
        }
    }
            if (code[ind] == '=')
            {
                ret += code[ind];
                ind++;
                return ret;
            }
            if (code[ind + 1] == '=')
            {
                ret += code[ind];
                ind++;
                ret += code[ind];
                ind++;
                return ret;
            }
            else
            {
                ret += code[ind];
                ind++;
                return ret;
            }
        }
        if (is_pancutator(code[ind]))
        {
            if (ret != "")
                return ret;
            ret = code[ind];
            ind++;
            if (ret == ":" && code[ind] == '=')
            {
                // std::cout<<ret<<'\n'<<endl;
                ret += code[ind];
                ind++;
            }
            return ret;
        }
        ret += code[ind];
        ind++;
    }
    ind++;
    return ret;
}
bool Lexer::is_bracket(char c)
{
    return (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}');
}

bool Lexer::is_boolean(const string &s)
{
    return (s == "true" || s == "false");
}

bool Lexer::is_integer(const string &s)
{
    bool _signed = false;
    if ((s[0] == '-' || s[0] == '+') && ((s.size())) > 1)
        _signed = true;
    for (int i = _signed; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool Lexer::is_real(const string &s)
{
    bool has_dot = false;
    bool _signed = false;
    if ((s[0] == '-' || s[0] == '+') && ((s.size())) > 1)
        _signed = true;
    for (int i = _signed; i < s.size(); i++)
    {
        if (has_dot == false && s[i] == '.')
        {
            has_dot = true;
        }
        else if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return has_dot;
}

bool Lexer::is_literal(const string &s)
{
    return (is_boolean(s) || is_integer(s) || is_real(s));
}

bool Lexer::is_keyword(const string &s)
{
    return keywords.find(s) != keywords.end();
}

bool Lexer::is_identifier(const string &s)
{
    const regex identifier_regex("^[A-Za-z_][A-Za-z0-9_]*$");
    return regex_match(s, identifier_regex);
}

bool Lexer::is_pancutator(char c)
{
    bool _signed = false;
    if (c == ':' || c == ';' || c == ',')
    {
        _signed = true;
    }
    return _signed;
}
bool Lexer::is_operator(const string &s)
{
    static unordered_set<string> operators;
    static bool initialized = false;
    if (!initialized)
    {
        operators.insert("+");
        operators.insert("-");
        operators.insert("*");
        operators.insert("/");
        operators.insert(">");
        operators.insert("<");
        operators.insert(">=");
        operators.insert("<=");
        operators.insert("/=");
        operators.insert("=");
        operators.insert("%");
        operators.insert("+=");
        operators.insert("-=");
        operators.insert("*=");
        operators.insert("%=");
        operators.insert(":=");
        initialized = true;
    }
    return operators.find(s) != operators.end();
}

string bracket_name(char c)
{
    if (c == '(')
        return "LPAR";
    if (c == ')')
        return "RPAR";
    if (c == '[')
        return "LBRAC";
    if (c == ']')
        return "RBRAC";
    if (c == '{')
        return "RELPAR";
    if (c == '}')
        return "RERLPR";
    return "ERROR";
}
TokenType Lexer::token_type(const string &s)
{
    if (is_keyword(s))
    {
        if (s == "is")
            return IS;
        else if (s == "while")
            return WHILE;
        else if (s == "routine")
            return ROUTINE;
        else if (s == "end")
            return END;
        else if (s == "break")
            return BREAK;
        else if (s == "return")
            return RETURN;
        else if (s == "not")
            return NOT;
        else if (s == "xor")
            return XOR;
        else if (s == "or")
            return OR;
        else if (s == "and")
            return AND;
        else if (s == "else")
            return ELSE;
        else if (s == "then")
            return THEN;
        else if (s == "if")
            return IF;
        else if (s == "in")
            return IN;
        else if (s == "then")
            return THEN;
        else if (s == "for")
            return FOR;
        else if (s == "loop")
            return LOOP;
        else if (s == "array")
            return ARRAY;
        else if (s == "false")
            return BOOLEAN_LITERAL;
        else if (s == "true")
            return BOOLEAN_LITERAL;
        else if (s == "record")
            return RECORD;
        else if (s == "type")
            return TYPE;
        else if (s == "var")
            return VAR;
        else if (s == "integer")
            return INTEGER_LITERAL_KEYWORD;
        else if (s == "real")
            return REAL_LITERAL_KEYWORD;
        else if (s == "boolean")
            return BOOLEAN_LITERAL_KEYWORD;
        else if (s == "continue")
            return CONTINUE;
        else if (s == "var")
            return VAR;
        else if (s == "reverse")
            return REVERSE;
        else if (s == "print")
            return PRINT;
    }
    if (s == "..")
        return TokenType::RANGE;
    if (s.size() == 1 && is_pancutator(s[0]))
        return TokenType::PUNCTUATOR;
    if (s.size() == 1 && s[0] == '.')
    {
        return TokenType::PUNCTUATOR;
    }
    if (is_boolean(s))
        return TokenType::BOOLEAN_LITERAL;
    if (is_integer(s))
        return TokenType::INTEGER_LITERAL;
    if (is_real(s))
        return TokenType::REAL_LITERAL;
    if (s.size() == 1 && is_bracket(s[0]))
    {
        if (s == "(")
            return TokenType::LPAR;
        if (s == ")")
            return TokenType::RPAR;
        if (s == "[")
            return TokenType::LBRAC;
        if (s == "]")
            return TokenType::RBRAC;
        if (s == "{")
            return TokenType::RELPAR;
        if (s == "}")
            return TokenType::RERLPR;
    }
    if (is_operator(s))
        return TokenType::OPERATOR;
    if (is_identifier(s))
        return TokenType::IDENTIFIER;
    return TokenType::ERROR;
}

Token Lexer::next_token(Token last_token)
{
    string content = next_token_content(last_token);
    Token tok(token_type(content), content);
    return tok;
}

vector<Token> *Lexer::scan_code()
{
    string input;
    while (getline(fin, input))
    {
        code += input + '\n';
    }
    if (code.size() == 0)
    {
        error_messages->push_back("Lexer Error:Input cannot be empty\n");
        return NULL;
    }

    Token token;
    Token last_Token;
    token = next_token(last_Token);
    last_Token = token;
    while (token.content != "")
    {
        if (token.type == TokenType::ERROR)
        {
            error_messages->push_back(token);
        }
        tokenized_code->push_back(token);
        token = next_token(last_Token);
        last_Token = token;
    }
    if (error_messages->size() != 0)
    {
        tokenized_code->clear();
        return NULL;
    }
    return tokenized_code;
}

void Lexer::print_errors()
{
    if (error_messages && error_messages->size() == 0)
        return;
    cout << "Lexical error(s):\n";
    for (auto err : *error_messages)
    {
        cout << err;
    }
}