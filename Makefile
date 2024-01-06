CC = gcc
CFLAGS = -Wall -Werror -Wpedantic -g
OBJ = main.o
EXE = calc

$(EXE): $(OBJ)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(EXE) $(OBJ)
