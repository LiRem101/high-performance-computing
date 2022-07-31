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


int write_into_file(char* filename, int n, int* iterations, double *simple_loop){
    FILE *fpt;
    fpt = fopen(filename, "w+");
    if(fpt == NULL){
        printf("Error while creating or opening file %s.\n", filename);
        return 1;
    }
    fprintf(fpt,"Iterations, Simple_Loop [seconds]\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(fpt,"%d, %f\n", iterations[i], simple_loop[i]);
    }
    fclose(fpt);
    return 0;
}


int main_timing() {
    int n = 5;
    int iterations[5] = {1000, 10000, 100000, 1000000, 10000000};

    double *times = simple_loop(iterations, n);
    write_into_file("./lab-sheet-01/Timing.csv", n, iterations, times);

    free(times);
    return 0;
}