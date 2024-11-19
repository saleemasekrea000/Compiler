#include <vector>
#include <string>
#include <cstring>
#include "lexer.hpp"
#include "ast.hpp"
#include "grammar.tab.h"

std::vector<Token> tokens;
size_t current_token_index = 0;

int yylex()
{
  if (current_token_index >= tokens.size())
  {
    return 0; // End of input
  }

  Token token = tokens[current_token_index++];
  if (token.content == "+=")
    return ADD_ASSIGN;
  else if (token.content == "-=")
    return SUB_ASSIGN;
  else if (token.content == "*=")
    return MUL_ASSIGN;
  else if (token.content == "/=")
    return DIV_ASSIGN;
  else if (token.content == "%=")
    return MOD_ASSIGN;
  else if (token.content == "&&")
    return AND_OP;
  else if (token.content == "||")
    return OR_OP;
  else if (token.content == "<=")
    return LE_OP;
  else if (token.content == ">=")
    return GE_OP;
  else if (token.content == "!=")
    return NE_OP;
  else if (token.content == ":=")
    return ASSIGN_OP;
  else if (token.content == ";")
    return ';';
  else if (token.content == "{")
    return '{';
  else if (token.content == "}")
    return '}';
  else if (token.content == ",")
    return ',';
  else if (token.content == ":")
    return ':';
  else if (token.content == "=")
    return '=';
  else if (token.content == "(")
    return '(';
  else if (token.content == ")")
    return ')';
  else if (token.content == "[")
    return '[';
  else if (token.content == "]")
    return ']';
  else if (token.content == ".")
    return '.';
  else if (token.content == "&")
    return '&';
  else if (token.content == "!")
    return '!';
  else if (token.content == "~")
    return '~';
  else if (token.content == "-")
    return '-';
  else if (token.content == "+")
    return '+';
  else if (token.content == "*")
    return '*';
  else if (token.content == "/")
    return '/';
  else if (token.content == "%")
    return '%';
  else if (token.content == "<")
    return '<';
  else if (token.content == ">")
    return '>';
  else if (token.content == "^")
    return '^';
  else if (token.content == "|")
    return '|';
  else if (token.typeToString() == "IS")
    return IS;
  else if (token.typeToString() == "REVERSE")
    return REVERSE;
  else if (token.typeToString() == "WHILE")
    return WHILE;
  else if (token.typeToString() == "ROUTINE")
    return ROUTINE;
  else if (token.typeToString() == "END")
    return END;
  else if (token.typeToString() == "BREAK")
    return BREAK;
  else if (token.typeToString() == "RETURN")
    return RETURN;
  else if (token.typeToString() == "NOT")
    return NOT;
  else if (token.typeToString() == "XOR")
    return XOR;
  else if (token.typeToString() == "OR")
    return OR;
  else if (token.typeToString() == "AND")
    return AND;
  else if (token.typeToString() == "ELSE")
    return ELSE;
  else if (token.typeToString() == "THEN")
    return THEN;
  else if (token.typeToString() == "IF")
    return IF;
  else if (token.typeToString() == "IN")
    return IN;
  else if (token.typeToString() == "THEN")
    return THEN;
  else if (token.typeToString() == "FOR")
    return FOR;
  else if (token.typeToString() == "LOOP")
    return LOOP;
  else if (token.typeToString() == "ARRAY")
    return ARRAY;
  else if (token.typeToString() == "FALSE")
    return FALSE;
  else if (token.typeToString() == "TRUE")
    return TRUE;
  else if (token.typeToString() == "RECORD")
    return RECORD;
  else if (token.typeToString() == "TYPE")
    return TYPE;
  else if (token.typeToString() == "VAR")
    return VAR;
  else if (token.typeToString() == "INTEGER_LITERAL_KEYWORD")
    return INTEGER_LITERAL_KEYWORD;
  else if (token.typeToString() == "REAL_LITERAL_KEYWORD")
    return REAL_LITERAL_KEYWORD;
  else if (token.typeToString() == "BOOLEAN_LITERAL_KEYWORD")
    return BOOLEAN_LITERAL_KEYWORD;
  else if (token.typeToString() == "RANGE")
    return RANGE;
  else if (token.typeToString() == "CONTINUE")
    return CONTINUE;
  else if (token.typeToString() == "IDENTIFIER")
  {
    yylval.id_val = strdup(token.content.c_str());
    return IDENTIFIER;
  }
  else if (token.typeToString() == "INTEGER_LITERAL")
  {
    yylval.int_val = std::stoi(token.content);
    return INTEGER_LITERAL;
  }
  else if (token.typeToString() == "REAL_LITERAL")
  {
    yylval.real_val = std::stoi(token.content);
    return REAL_LITERAL;
  }
  else if (token.typeToString() == "BOOLEAN_LITERAL")
  {
    if (token.content == "true")
      yylval.bool_val = true;
    else if (token.content == "false")
      yylval.bool_val = false;
    return BOOLEAN_LITERAL;
  }
  return -1;
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
    return 1;
  }

  Lexer lexer(argv[1]);
  tokens = *lexer.scan_code();
  if (tokens.empty())
  {
    lexer.print_errors();
    return 1;
  }

  yyparse();
  return 0;
}