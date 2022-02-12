CC=gcc
DEPS=tests/run_all.c src/matrix.h tests/test_matrix.h src/init.h \
    tests/test_init.h src/helpers.h tests/test_helpers.h src/operations.h \
    tests/test_operations.h src/inner.h tests/test_inner.h src/echelon.h \
    tests/test_echelon.h src/solve.h tests/test_solve.h
OBJ=tests/run_all.o src/matrix.o tests/test_matrix.o src/init.o \
    tests/test_init.o src/helpers.o tests/test_helpers.o src/operations.o \
    tests/test_operations.o src/inner.o tests/test_inner.o src/echelon.o \
    tests/test_echelon.o src/solve.o tests/test_solve.o

%.o: %.cc
	$(CC) -c -o $@ $<

test: $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ)
