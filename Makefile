# Learning to make a make file with make for making my c program executable.
# i did that on purpose :) ===^
# i know i can use bash
# Only give 1 tab , NOT 2
# I gave option for run and clean but when i want to run , i dont want to do 3

CC = gcc
CFLAGS = -Wall -Wextra
SRC = nix-script.c
OBJ = output

all: $(OBJ)
	./$(OBJ)

output: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)  

run: $(OBJ)
	./$(OBJ)

clean: 
	rm -f $(OBJ)

.PHONY: clean all run
