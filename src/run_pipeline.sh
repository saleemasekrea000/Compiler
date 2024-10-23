#!/bin/bash

# Step 1: Run the lexer
# Get the file name from command arguments
file=$1
g++ lexer/main.cpp lexer/lexer.cpp -o lexer/main
./lexer/main "$file"

# Step 2: Run the parser
bison -d parser/grammar.y
g++ -Wno-write-strings -o parser/parser parser/lexer_2.cpp parser/grammar.tab.c parser/ast.c -lfl
./parser/parser parser/tokens.txt