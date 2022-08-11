#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "lab-sheet-01/timing_of_loops.h"
#include "lab-sheet-02/openmp_intro.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: expected 1 command-line argument (an INT), but got %d\n", argc);
        exit(EXIT_FAILURE);
    }

    char *end;
    // clear errno so we can check whether strtol fails
    errno = 0;
    long n = strtol(argv[1], &end, 10);
    int res_errno = errno;

    if (end == argv[1]) {
        fprintf(stderr, "Error: couldn't interpret '%s' as a number.\n", argv[1]);
        exit(EXIT_FAILURE);
    } else if (res_errno == ERANGE) {
        fprintf(stderr, "Error: '%s' is outside the range of numbers we can handle.\n", argv[1]);
        exit(EXIT_FAILURE);
    } else if (n <= 0 || n >= 3) {
        fprintf(stderr, "Error: '%s' is not a number of a valid lab sheet (1 and 2 available).\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if(n == 1){
        main_timing();
    } else if (n == 2) {
        main_openmp_intro();
    }

    exit(EXIT_SUCCESS);
}