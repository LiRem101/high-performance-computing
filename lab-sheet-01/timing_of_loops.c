#include <time.h>
#include <stdio.h>
#include <malloc.h>

double* simple_loop(const int *iterations, int size) {
    double *times;
    times = (double *) malloc (size * sizeof (double));
    for (int i = 0; i < size; ++i) {
        clock_t start = clock();
        for (int j = 0; j < *(iterations + i); j++) {
        }
        clock_t end = clock();
        *(times + i) = (double)(end - start) / CLOCKS_PER_SEC;
    }
    return times;
}


int main_timing() {
    int n = 5;
    int iterations[5] = {1000, 10000, 100000, 1000000, 10000000};

    double *times = simple_loop(iterations, n);

    FILE *fpt;
    fpt = fopen("./lab-sheet-01/Timing.csv", "w+");
    fprintf(fpt,"Iterations, Simple_Loop\n");

    for (int i = 0; i < n; i++)
    {
        printf ("Elapsed: %f seconds\n", times[i]);
    }

    fclose(fpt);
    free(times);
    return 0;
}