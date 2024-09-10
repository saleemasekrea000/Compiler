#!/bin/bash

g++ main.cpp lexer.cpp -o main

dir="lexer_tests_inputs"

for file in "$dir"/*
do
  ./main "$file"
done