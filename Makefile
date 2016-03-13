FILE = main.cpp game.cpp image.cpp link_texture.cpp
OUTPUT_FILE = game
COMPILER = g++
COMPILER_FLAGS = -std=c++11
LINKER_FLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
CC = g++

all : $(FILE)
	$(CC) $(FILE) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUTPUT_FILE)
