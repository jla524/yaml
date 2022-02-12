#include <stdio.h>
#include "test_matrix.h"
#include "test_init.h"
#include "test_operations.h"
#include "test_helpers.h"
#include "test_inner.h"
#include "test_echelon.h"
#include "test_solve.h"

int main() {
    printf("Starting unit tests\n");
    test_all_matrix();
    test_all_init();
    test_all_operations();
    test_all_helpers();
    test_all_inner();
    test_all_echelon();
    test_all_solve();
    printf("Completed\n");
    return 0;
}
