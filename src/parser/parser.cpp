#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "parser.hpp"
#include "grammar.tab.h"


using namespace std;

static vector<Token>* tokens;
static size_t current_token_index = 0;


void set_tokens(vector<Token>* token_vector)
{
    tokens = token_vector;
    current_token_index = 0;
}

int yylex()
{
  if (tokens == nullptr || current_token_index >= tokens->size())
  {
      return 0; // No more tokens
  }

  std::string tokenType, tokenValue;
  Token& token = tokens->at(current_token_index++);
  tokenType = token.typeToString();
  tokenValue = token.content;

  // Return the appropriate token based on the token type
  
  if (tokenValue == "+=") return ADD_ASSIGN;
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
  else if (tokenType=="PRINT")return PRINT;
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
    yylval.real_val = std::stod(tokenValue);
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

