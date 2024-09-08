.PHONY: run
run:
	@g++ -o main src/lexer/lexer.cpp
	@./main
	@rm main