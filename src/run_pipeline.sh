echo "Compiling and running the pipeline..."

#!/bin/bash

bison -d -o ./parser/grammar.tab.c ./parser/grammar.y

g++ -Wno-write-strings -std=c++11 main.cpp lexer/lexer.cpp lexer/token.cpp parser/ast.cpp parser/parser.cpp parser/grammar.tab.c semantic/semantic.cpp codegen/codegen.cpp -o main -lfl `llvm-config --cxxflags --ldflags --system-libs --libs all`

file="tests/test1.txt"
./main "$file"

echo "Lexical analysis complete."
echo "Parsing complete."
echo "Semantic analysis complete."
echo "Code generation complete."


if [ -f "output.ll" ]; then
    echo "Validating output.ll..."
    llvm-as output.ll -o /dev/null 2>validation_errors.txt

    if [ $? -eq 0 ]; then
        echo "output.ll is valid."
        echo "running code generation..."
        echo ""
        echo "Code result:"
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
