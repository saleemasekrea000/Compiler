# Variables
CXX = g++
CXXFLAGS = -Wno-write-strings
LEXER_SRC = ./lexer/lexer.cpp
LEXER_OUT = main
PARSER_SRC = ./parser/lexer_2.cpp ./parser/grammar.tab.c ./parser/ast.cpp
SEMANTIC_SRC = ./semantic/semantic.hpp ./semantic/semantic.cpp
CODEGEN_SRC = ./codegen/codegen.hpp ./codegen/codegen.cpp
TEST_FILE = tests/test1.txt
OUTPUT_LL = output.ll
BC_FILE = ../factorial.bc

all: lexer_tests syntax_analysis codegen

lexer_tests:
	@echo "Running lexer tests..."
	$(CXX) main.cpp $(LEXER_SRC) -o $(LEXER_OUT)
	./$(LEXER_OUT) $(TEST_FILE)

syntax_analysis:
	@echo "Running syntax analysis..."
	bison -d -o ./parser/grammar.tab.c ./parser/grammar.y
	$(CXX) $(CXXFLAGS) -o parser_output $(PARSER_SRC) $(SEMANTIC_SRC) $(CODEGEN_SRC) -lfl `llvm-config --cxxflags --ldflags --system-libs --libs all`
	./parser_output lexer_tests__tokens.txt

codegen:
	@if [ -f "$(OUTPUT_LL)" ]; then \
		echo "Running code generation..."; \
		echo "$(OUTPUT_LL) generated successfully."; \
		llvm-as $(OUTPUT_LL) -o $(BC_FILE); \
		lli $(BC_FILE); \
	else \
		echo "Error: $(OUTPUT_LL) not found. Ensure the parser generates $(OUTPUT_LL)."; \
		exit 1; \
	fi

# Clean up generated files
clean:
	rm -f $(LEXER_OUT) parser_output $(OUTPUT_LL) $(BC_FILE)
