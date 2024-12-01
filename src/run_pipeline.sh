echo "Running lexer tests..."

#!/bin/bash

g++ main.cpp ./lexer/lexer.cpp -o main

# dir="lexer_tests_inputs"
file="tests/test1.txt"
# for file in "$dir"/*
#do
  ./main "$file"
#done


echo "Running syntax analysis..."

bison -d -o ./parser/grammar.tab.c ./parser/grammar.y


g++ -Wno-write-strings -o parser_output ./parser/lexer_2.cpp ./parser/grammar.tab.c ./parser/ast.cpp ./semantic/semantic.hpp ./semantic/semantic.cpp ./codegen/codegen.hpp ./codegen/codegen.cpp -lfl \
    `llvm-config --cxxflags --ldflags --system-libs --libs all`

./parser_output lexer_tests__tokens.txt

if [ -f "output.ll" ]; then
    echo "Validating output.ll..."
    llvm-as output.ll -o /dev/null 2>validation_errors.txt

    if [ $? -eq 0 ]; then
        echo "output.ll is valid."
        echo "running code generation..."
        lli output.ll
    else
        echo "Error: output.ll contains errors."
        echo "Validation errors:"
        cat validation_errors.txt
        exit 1
    fi
else
    echo "Error: output.ll not found. Ensure the parser generates output.ll."
    exit 1

fi
