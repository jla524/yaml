CC=gcc
DEPS=matrix.h init.h
OBJ=main.o matrix.o init.o

%.o: %.cc
	$(CC) -c -o $@ $<

main: $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ)
