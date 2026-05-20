CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c \
      src/input.c \
      src/calculation.c \
      src/classification.c \
      src/output.c \
      src/simulation.c

OUT = dengue

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f $(OUT)