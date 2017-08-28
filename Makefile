CC = gcc
CFLAGS = -c -Wall

EXE = main
OBJ = $(SRC:.c=.o)
HEAD = linkedList.h
SRC = linkedList.c main.c

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC)

clean:
	rm -f $(OBJ) $(EXE)