FILE = main.cpp game.cpp
OUTPUT_FILE = game
COMPILER = g++
COMPILER_FLAGS = -std=c++11
LINKER_FLAGS = -lSDL2
CC = g++

all : $(FILE)
	$(CC) $(FILE) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUTPUT_FILE)
