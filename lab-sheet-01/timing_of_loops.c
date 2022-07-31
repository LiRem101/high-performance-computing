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


int bubbleSort(int* toSort, int size){
    int swapped = 1;
    while(swapped){
        swapped = 0;
        for (int i = 1; i < size; ++i) {
            if(toSort[i-1] > toSort[i]){
                int swapCache = toSort[i-1];
                toSort[i-1] = toSort[i];
                toSort[i] = swapCache;
                swapped = 1;
            }
        }
    }
    return 0;
}


double* bubbleSort_loop(const int *iterations, int size) {
    double *times;
    times = (double *) malloc(size * sizeof (double));
    for (int i = 0; i < size; ++i) {
        srand(time(NULL));
        int *toSort;
        toSort = (int *) malloc (iterations[i] * sizeof (int));
        for (int j = 0; j < *(iterations + i); j++) {
            toSort[j] = rand();
        }

        clock_t start = clock();
        bubbleSort(toSort, iterations[i]);
        clock_t end = clock();
        *(times + i) = (double)(end - start) / CLOCKS_PER_SEC;
        free(toSort);
        printf("Bubble sort for %d done.\n", iterations[i]);
    }
    return times;
}


int write_into_file_loops(char* filename, int n, int* iterations, double *simple_loop, double *sum_loop){
    FILE *fpt;
    fpt = fopen(filename, "w+");
    if(fpt == NULL){
        printf("Error while creating or opening file %s.\n", filename);
        return 1;
    }
    fprintf(fpt,"Iterations, Simple_Loop [seconds], Sum_Loop [seconds]\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(fpt,"%d, %f, %f\n", iterations[i], simple_loop[i], sum_loop[i]);
    }
    fclose(fpt);
    return 0;
}


int write_into_file_sorts(char* filename, int n, int* num_elements, double *bubbleSort){
    FILE *fpt;
    fpt = fopen(filename, "w+");
    if(fpt == NULL){
        printf("Error while creating or opening file %s.\n", filename);
        return 1;
    }
    fprintf(fpt,"Number_Elements, BubbleSort [seconds]\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(fpt, "%d, %f\n", num_elements[i], bubbleSort[i]);
    }
    fclose(fpt);
    return 0;
}


int main_timing() {
    int n = 5;
    int iterations[5] = {1000, 10000, 100000, 1000000, 10000000};
    int sort_loops[5] = {10, 100, 1000, 10000, 100000};

    double *simple_times = simple_loop(iterations, n);
    double *sum_times = sum_random(iterations, n);
    double *bubbleSort_times = bubbleSort_loop(sort_loops, n);
    write_into_file_loops("./lab-sheet-01/Timing.csv", n, iterations, simple_times, sum_times);
    write_into_file_sorts("./lab-sheet-01/Sorts.csv", n, sort_loops, bubbleSort_times);

    free(simple_times);
    free(sum_times);
    free(bubbleSort_times);
    return 0;
}