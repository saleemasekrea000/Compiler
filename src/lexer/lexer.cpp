#include <string>
#include <iostream>
#include <regex>
#include <unordered_set>
#include <fstream>
#include <unordered_map>

#include "lexer.hpp"
#include "../parser/grammar.tab.h"

static std::vector<Token> tokens;
static size_t token_index = 0;


int yylex()
{
  if (token_index >= tokens.size())
  {
    return 0;
  }

  const Token &token = tokens[token_index++];

  std::string tokenType, tokenValue;
  tokenType = token.type;
  tokenValue = token.content;
  
  if (tokenValue == "+=") return yytokentype::ADD_ASSIGN;
  else if (tokenValue == "-=") return SUB_ASSIGN;
  else if (tokenValue == "*=") return MUL_ASSIGN;
  else if (tokenValue == "/=") return DIV_ASSIGN;
  else if (tokenValue == "%=") return MOD_ASSIGN;
  else if (tokenValue == "&&") return AND_OP;
  else if (tokenValue == "||") return OR_OP;
  else if (tokenValue == "<=") return LE_OP;
  else if (tokenValue == ">=") return GE_OP;
  else if (tokenValue == "!=") return NE_OP;
  else if (tokenValue == ":=") return ASSIGN_OP;
  else if (tokenValue == ";") return ';';
  else if (tokenValue == "{") return '{';
  else if (tokenValue == "}") return '}';
  else if (tokenValue == ",") return ',';
  else if (tokenValue == ":") return ':';
  else if (tokenValue == "=") return '=';
  else if (tokenValue == "(") return '(';
  else if (tokenValue == ")") return ')';
  else if (tokenValue == "[") return '[';
  else if (tokenValue == "]") return ']';
  else if (tokenValue == ".") return '.';
  else if (tokenValue == "&") return '&';
  else if (tokenValue == "!") return '!';
  else if (tokenValue == "~") return '~';
  else if (tokenValue == "-") return '-';
  else if (tokenValue == "+") return '+';
  else if (tokenValue == "*") return '*';
  else if (tokenValue == "/") return '/';
  else if (tokenValue == "%") return '%';
  else if (tokenValue == "<") return '<';
  else if (tokenValue == ">") return '>';
  else if (tokenValue == "^") return '^';
  else if (tokenValue == "|") return '|';
  else if (tokenType == "IS") return IS;
  else if (tokenType == "REVERSE") return REVERSE;
  else if (tokenType == "WHILE") return WHILE;
  else if (tokenType == "ROUTINE")return ROUTINE;
  else if (tokenType == "END") return END;
  else if (tokenType == "BREAK") return BREAK;
  else if (tokenType == "RETURN") return RETURN;
  else if (tokenType == "NOT") return NOT;
  else if (tokenType== "XOR") return XOR;
  else if (tokenType== "OR") return OR;
  else if (tokenType=="AND") return AND;
  else if (tokenType == "ELSE") return ELSE;
  else if (tokenType=="THEN") return THEN;
  else if (tokenType=="IF") return IF;
  else if (tokenType=="IN") return IN;
  else if (tokenType=="THEN") return THEN;
  else if (tokenType=="FOR") return FOR;
  else if(tokenType=="LOOP") return LOOP;
  else if (tokenType == "ARRAY") return ARRAY;
  else if (tokenType=="FALSE") return FALSE;
  else if(tokenType=="TRUE") return TRUE;
  else if(tokenType=="RECORD") return RECORD;
  else if(tokenType=="TYPE") return TYPE;
  else if (tokenType=="VAR") return VAR;
  else if (tokenType=="INTEGER_LITERAL_KEYWORD") return INTEGER_LITERAL_KEYWORD;
  else if (tokenType=="REAL_LITERAL_KEYWORD") return REAL_LITERAL_KEYWORD;
  else if (tokenType=="BOOLEAN_LITERAL_KEYWORD") return BOOLEAN_LITERAL_KEYWORD;
  else if (tokenType=="RANGE")return RANGE;
  else if (tokenType=="CONTINUE")return CONTINUE;
  else if (tokenType == "IDENTIFIER")
  {
    yylval.id_val = strdup(tokenValue.c_str());
    return IDENTIFIER;
  }
  else if (tokenType == "INTEGER_LITERAL")
  {
    yylval.int_val = std::stoi(tokenValue);
    return INTEGER_LITERAL;
  }
  else if (tokenType == "REAL_LITERAL")
  {
    yylval.real_val = std::stoi(tokenValue);
    return REAL_LITERAL;
  }
  else if (tokenType == "BOOLEAN_LITERAL")
  {
    if (tokenValue == "true") 
        yylval.bool_val = true;
    else if (tokenValue == "false") 
        yylval.bool_val = false;
    return BOOLEAN_LITERAL;
  }
  return -1;
}


void set_tokens(std::vector<Token> &new_tokens)
{
    tokens = new_tokens;
    token_index = 0;
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
        if (ret != "" && ( is_operator(cur)))
        {
            return ret;
        }
        if (ret == "" && (is_operator(cur)))
        {
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
            else {
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
            if(ret==":" && code[ind]=='='){
             // std::cout<<ret<<'\n'<<endl;
              ret+=code[ind];
              ind++;
            }
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
    static const unordered_set<string> operators = {"+", "-", "*", "/", ">", "<", ">=", "<=", "/=", "=", "%", "+=", "-=", "*=", "%=", ":="};
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
        if (s == "is") return TokenType::IS;
        else if (s == "while") return TokenType::WHILE;
        else if (s == "routine")return TokenType::ROUTINE;
        else if (s == "end") return TokenType::END;
        else if (s == "break") return TokenType::BREAK;
        else if (s == "return") return TokenType::RETURN;
        else if (s == "not") return TokenType::NOT;
        else if (s== "xor") return TokenType::XOR;
        else if (s== "or") return TokenType::OR;
        else if (s=="and") return TokenType::AND;
        else if (s == "else") return TokenType::ELSE;
        else if (s=="then") return TokenType::THEN;
        else if (s=="if") return TokenType::IF;
        else if (s=="in") return TokenType::IN;
        else if (s=="then") return TokenType::THEN;
        else if (s=="for") return TokenType::FOR;
        else if(s=="loop") return TokenType::LOOP;
        else if (s == "array") return TokenType::ARRAY;
        else if (s=="false") return TokenType::BOOLEAN_LITERAL;
        else if(s=="true") return TokenType::BOOLEAN_LITERAL;
        else if(s=="record") return TokenType::RECORD;
        else if(s=="type") return TokenType::TYPE;
        else if (s=="var") return TokenType::VAR;
        else if (s=="integer") return TokenType::INTEGER_LITERAL_KEYWORD;
        else if (s=="real") return TokenType::REAL_LITERAL_KEYWORD;
        else if (s=="boolean") return TokenType::BOOLEAN_LITERAL_KEYWORD;
        else if (s=="continue") return TokenType::CONTINUE;
        else if (s=="var") return TokenType::VAR;
        else if (s=="reverse") return TokenType::REVERSE;
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
