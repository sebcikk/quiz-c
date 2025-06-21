SHELL = /bin/sh

CC = gcc

CFLAGS = -Iinclude -Wall -Wextra -g

LD = gcc

SRC = src
INCLUDE = include

OBJ = main.o files.o questions.o

quiz: $(OBJ)
	$(LD) -o quiz $(OBJ)

main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) -c $(SRC)/main.c

files.o: $(SRC)/files.c
	$(CC) $(CFLAGS) -c $(SRC)/files.c

questions.o: $(SRC)/questions.c
	$(CC) $(CFLAGS) -c $(SRC)/questions.c

clean:
	rm -f *.o quiz
