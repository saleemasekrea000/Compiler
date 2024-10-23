bison -d grammar.y

g++ -Wno-write-strings -o parser lexer_2.cpp grammar.tab.c ast.c -lfl

./parser tokens_1.txt