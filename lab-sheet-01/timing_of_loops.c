#include <time.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

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


double* sum_random(const int *iterations, int size) {
    double *times;
    times = (double *) malloc(size * sizeof (double));
    for (int i = 0; i < size; ++i) {

        srand(time(NULL));
        double *random;
        random = (double *) malloc (iterations[i] * sizeof (double));
        for (int j = 0; j < *(iterations + i); j++) {
            random[j] = (double)(rand() % 100)/100;
        }

        clock_t start = clock();
        double res = 0.0;
        for (int j = 0; j < *(iterations + i); j++) {
            res += random[j];
        }
        clock_t end = clock();
        *(times + i) = (double)(end - start) / CLOCKS_PER_SEC;
        free(random);
    }
    return times;
}


int write_into_file(char* filename, int n, int* iterations, double *simple_loop, double *sum_loop){
    FILE *fpt;
    fpt = fopen(filename, "w+");
    if(fpt == NULL){
        printf("Error while creating or opening file %s.\n", filename);
        return 1;
    }
    fprintf(fpt,"Iterations, Simple_Loop [seconds], SUm_Loop [seconds]\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(fpt,"%d, %f, %f\n", iterations[i], simple_loop[i], sum_loop[i]);
    }
    fclose(fpt);
    return 0;
}


int main_timing() {
    int n = 5;
    int iterations[5] = {1000, 10000, 100000, 1000000, 10000000};

    double *simple_times = simple_loop(iterations, n);
    double *sum_times = sum_random(iterations, n);
    write_into_file("./lab-sheet-01/Timing.csv", n, iterations, simple_times, sum_times);

    free(simple_times);
    free(sum_times);
    return 0;
}