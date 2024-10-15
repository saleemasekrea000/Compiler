#!/bin/bash
bison -d grammar.y
g++ main.cpp lexer.cpp grammar.tab.c -o main

dir="lexer_tests_inputs"

for file in "$dir"/*
do
  ./main "$file"
done