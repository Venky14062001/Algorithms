#Makefile for C++ project

.PHONY = all run clean 

CXX := g++
CXX_FLAGS := -std=c++17 -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion 

BIN := bin
SRC := src
INCLUDE := include

LIBRARIES :=
EXECUTABLE := main

SRC_FILES = src/main.cpp 

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): 
	@$(CXX) $(CXX_FLAGS) -o $@ $(SRC_FILES) -I$(INCLUDE)
	
run: $(BIN)/$(EXECUTABLE)
	@./$(BIN)/$(EXECUTABLE)
	
clean:
	@rm $(BIN)/*


