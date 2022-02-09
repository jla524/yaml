CC=gcc
DEPS=matrix.h init.h helpers.h operations.h
OBJ=main.o matrix.o init.o helpers.o operations.o

%.o: %.cc
	$(CC) -c -o $@ $<

main: $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ)
