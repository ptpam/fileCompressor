CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/compression.c src/decompression.c src/utils.c
OBJ = $(SRC:.c=.o)
TARGET = fileCompressor

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
