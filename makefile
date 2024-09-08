.PHONY: run
run:
	@g++ -o main src/main.cpp 
	@./main terminal
	@rm main

.PHONY: runTerminal
runTerminal:
	@g++ -o main src/main.cpp
	@./main terminal
	@rm main

.PHONY: runFile
runFile:
	@g++ -o main src/main.cpp
	@./main file ${name}
	@rm main