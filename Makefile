CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Source files
SRC = src/main.c src/compression.c src/decompression.c src/utils.c

# Object files (in the build directory)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))

# Target executable (outside the build directory)
TARGET = fileCompressor

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile each .c file into a .o file in the build directory
build/%.o: src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf build/* $(TARGET)

# Mark targets as phony
.PHONY: all clean
