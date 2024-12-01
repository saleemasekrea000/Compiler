#!/bin/bash


bison -d grammar.y

g++ -Wno-write-strings -o parser lexer_2.cpp grammar.tab.c ast.cpp ../semantic/semantic.hpp ../semantic/semantic.cpp -lfl \
    `llvm-config --cxxflags --ldflags --system-libs --libs all`

./parser ../lexer/lexer_tests_outputs/test1_tokens.txt

if [ -f "output.ll" ]; then
    echo "running code generation..."
    echo "output.ll generated successfully."

    llvm-as output.ll -o ../factorial.bc

    lli ../factorial.bc
else
    echo "Error: output.ll not found. Ensure the parser generates output.ll."
    exit 1
fi
