# Variables
CXX = g++
CXXFLAGS = -Iinclude
SOURCES = main.cpp src/lexer/lexer.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: all
	./$(EXECUTABLE) test.txt

.PHONY: all clean run
