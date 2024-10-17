bison -d grammar.y

g++ -o parser lexer_2.cpp grammar.tab.c

./parser