#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "lexer_2.hpp"
#include "ast.h"
#include "grammar.tab.h"

std::ifstream tokenFile;

int yylex()
{
  std::string line;
  if (!std::getline(tokenFile, line))
  {
    // End of file, return 0 to indicate end of input
    return 0;
  }

  // Parse the line to get the token type and value
  std::string tokenType, tokenValue;
  std::istringstream lineStream(line);
  lineStream >> tokenType >> tokenValue;
  // Return the appropriate token based on the token type
  if (tokenType == "KEYWORD")
  {
    yylval.keyword_val = strdup(tokenValue.c_str());
    return KEYWORD;
  }
  else if (tokenType == "IS")
  {
    return IS;
  }
  else if (tokenType == "WHILE")
  {
    return WHILE;
  }
  else if (tokenType == "ROUTINE")
  {
    return ROUTINE;
  }
  else if (tokenType == "END")
  {
    return END;
  }
  else if (tokenType == "BREAK")
  {
    return BREAK;
  }
  else if (tokenType == "RETURN"){
     return RETURN;
  }
  else if (tokenType == "NOT"){
    return NOT;
  }
  else if (tokenType== "XOR"){
    return XOR;
  }
  else if (tokenType== "OR"){
   return OR;
  }
  else if (tokenType=="AND"){
    return AND;
  }
  else if (tokenType == "ELSE"){
    return ELSE;
  }
  else if (tokenType=="THEN"){
    return THEN;
  }
  else if (tokenType=="IF"){
    return IF;
  }
  else if (tokenType=="IN"){
    return IN;
  }
  else if (tokenType=="THEN"){
    return THEN;
  }
  else if (tokenType=="FOR"){
    return FOR;
  }
  else if(tokenType=="LOOP"){
    return LOOP;
  }
  else if (tokenType == "ARRAY"){
    return ARRAY;
  }
  else if (tokenType=="FALSE"){
    return FALSE;
  }
  else if(tokenType=="TRUE"){
    return TRUE;
  }
  else if(tokenType=="RECORD"){
    return RECORD;
  }
  else if(tokenType=="TYPE"){
    return TYPE;
  }
  else if (tokenType=="VAR"){
    return VAR;
  }
  else if (tokenType=="INTEGER_LITERAL_KEYWORD"){
    return INTEGER_LITERAL_KEYWORD;
  }
  else if (tokenType=="REAL_LITERAL_KEYWORD"){
    return REAL_LITERAL_KEYWORD;
  }
  else if (tokenType=="BOOL_LITERAL_KEYWORD"){
    return BOOL_LITERAL_KEYWORD;
  }
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
  else if (tokenType == "OPERATOR")
  {
    yylval.op_val = strdup(tokenValue.c_str());
    return OPERATOR;
  }
  else if (tokenType == "LPAR")
  {
    return LPAR;
  }
  else if (tokenType == "RPAR")
  {
    return RPAR;
  }
  else if (tokenType == "LBRAC")
  {
    return LBRAC;
  }
  else if (tokenType == "RBRAC")
  {
    return RBRAC;
  }
  else if (tokenType == "RELPAR")
  {
    return RELPAR;
  }
  else if (tokenType == "RERLPR")
  {
    return RERLPR;
  }
  else if (tokenType == "PUNCTUATOR")
  {
    return PUNCTUATOR;
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

  FILE *input_file = fopen(argv[1], "r");
  if (!input_file)
  {
    perror("Error opening input file");
    return 1;
  }

  tokenFile.open(argv[1]);
  yyparse();
  fclose(input_file);
  return 0;
}