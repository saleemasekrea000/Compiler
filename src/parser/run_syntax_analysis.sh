bison -d grammar.y

g++ -Wno-write-strings -o parser lexer_2.cpp grammar.tab.c ast.cpp -lfl

./parser ../lexer/lexer_tests_outputs/test1_tokens.txt
