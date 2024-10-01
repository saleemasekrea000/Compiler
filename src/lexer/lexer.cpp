#include <string>
#include <iostream>
#include <regex>
#include <unordered_set>
#include <fstream>
#include <unordered_map>

#include "lexer.hpp"

string Lexer::next_token_content(Token last_token)
{
    while (ind < code.size() && (code[ind] == ' ' || code[ind] == '\n' || code[ind] == '\t'))
        ind++;
    if (ind >= code.size()){
        return "";
    }
    string ret = "";
    while (code[ind] != ' ' && code[ind] != '\n' && code[ind] != '\t')
    {
        if(code[ind]=='.'){
          //  cout<<"KKKKKKKKKKKKKKk"<<" "<<ret<<" "<<last_token.content<<endl;
            if(is_identifier(ret)&&isalpha(code[ind+1])){
                return ret;
            }
            if(ret==""&&last_token.type=="IDENTIFIER"&&isalpha(code[ind+1])){
                ret+=code[ind];
                ind++;
                return ret;
            }
        }
        string cur="";
        cur+=code[ind];
        if(ret!="" && is_operator(cur)){
            return ret;
        }
        if(ret=="" && is_operator(cur)){
            if(code[ind]=='='){
                ret+=code[ind];
                ind++;
                return ret;
            }
            if(code[ind+1]=='='){
                ret+=code[ind];
                ind++;
                ret+=code[ind];
                ind++;
                return ret;
            }
        }
        if (is_bracket(code[ind]) || is_pancutator(code[ind]))
        {
            if (ret != "")
                return ret;
            ret = code[ind];
            ind++;
            return ret;
        }
        if (code[ind] == '/' && code[ind + 1] == '/')
        {
            while (code[ind] != '\n' && code[ind] != EOF)
                ind++;
            if (ret == "")
                return next_token_content(last_token);
            break;
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
    static const unordered_set<string> operators = {"+", "-", "*", "/", ">", "<", ">=", "<=", "/=", "=", "%", "+=", "-=", "*=" ,"%="};
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
    return "ERR";
}
string Lexer::token_type(const string &s)
{
    if (s.size()==1&&is_pancutator(s[0]))
        return "PUNCTUATOR";
    if(s.size()==1&&s[0]=='.'){
        return "PUNCTUATOR";
    }
    if (is_boolean(s))
        return "BOOL";
    if (is_integer(s))
        return "INT";
    if (is_real(s))
        return "REAL";
    if (is_keyword(s))
        return "KEYWORD";
    if (is_bracket(s[0]))
        return bracket_name(s[0]);
    if (is_operator(s))
        return "OPERATOR";
    if (is_identifier(s))
        return "IDENTIFIER";

    if (s=="..") 
        return "RANGE";
    return "ERROR";
}

Token Lexer::next_token(Token last_token)
{
    string content = next_token_content(last_token);
    Token tok(token_type(content), content);
    return tok;
}

string Lexer::scan_code()
{
    string input;
    while (getline(fin, input))
    {
        code += input + '\n';
    }

    string tokenized_code;
    Token token;
    Token last_Token;
    token = next_token(last_Token);
    last_Token=token;
    while (token.content != "")
    {
        tokenized_code += token;
        token = next_token(last_Token);
        last_Token=token;
    }
    return tokenized_code;
}
