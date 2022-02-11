CC=gcc
DEPS=src/matrix.h src/init.h src/helpers.h src/operations.h src/inner.h \
    src/echelon.h tests/run_all.c tests/test_matrix.h tests/test_operations.h \
    tests/test_helpers.h tests/test_inner.o tests/test_echelon.o
OBJ=src/matrix.o src/init.o src/helpers.o src/operations.o src/inner.o \
    src/echelon.o tests/run_all.o tests/test_matrix.o tests/test_init.o \
    tests/test_operations.o tests/test_helpers.o tests/test_inner.o \
    tests/test_echelon.o

%.o: %.cc
	$(CC) -c -o $@ $<

test: $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ)
