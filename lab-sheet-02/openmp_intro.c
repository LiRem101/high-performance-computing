#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int openmp_helloworld(){
    printf("OpenMP is running with %d threads.\n", omp_get_max_threads());

    clock_t start = clock();
    #pragma omp parallel
    {
        //if(omp_get_thread_num() == 3) sleep(1);
        printf("Hello World from thread %d.\n", omp_get_thread_num());
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("time spent=%10.6f\n",time_spent);

    return(EXIT_SUCCESS);
}

int openmp_helloworld_more_threads(){
    printf("OpenMP is running with %d threads.\n", omp_get_max_threads());

    clock_t start = clock();
    omp_set_num_threads(32);
    #pragma omp parallel
    {
        //if(omp_get_thread_num() == 3) sleep(1);
        if(omp_get_thread_num() % 10 == 0) {
            printf("Hello World from thread %d.\n", omp_get_thread_num());
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("time spent=%10.6f\n",time_spent);

    return(EXIT_SUCCESS);
}

int add_floating_numbers(){
    int size = 1024;
    double *random;
    random = (double *) malloc(size * sizeof (double));
    if (random == NULL) {
        printf("Cannot allocate %lu bytes of memory.\n", size * sizeof (double));
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i) {
        srand(time(NULL));
        random[i] = (double)(rand() % 100)/100;
    }

    int thread_nums = 4;
    omp_set_num_threads(thread_nums);
    double *localSums;
    localSums = (double *) malloc(thread_nums * sizeof (double));
    if (random == NULL) {
        printf("Cannot allocate %lu bytes of memory.\n", thread_nums * sizeof (double));
        exit(EXIT_FAILURE);
    }

    double localSum = 0;
    #pragma omp parallel private(localSum)
    {
        #pragma omp for
        for (int i = 0; i < size; i++){
            localSum = localSum + random[i];
        }
        printf("localSum of thread %d is %f.\n", omp_get_thread_num(), localSum);
        localSums[omp_get_thread_num()] = localSum;
    }

    localSum = 0;
    for(int i = 0; i < thread_nums; i++){
        localSum += localSums[i];
    }


    double localSumSeq = 0;
    for (int i = 0; i < size; i++){
        localSumSeq = localSumSeq + random[i];
    }
    printf("localSum of sequential summation is %f.\n", localSumSeq);

    if(fabs(localSumSeq - localSum) < 0.000001) {
        printf("Success! Sum of local sums of the treads and sequentially calculated sum is equal!\n");
    } else {
        printf("Error. LocalSums of threads is %f and sequentially calculated sum is %f.\n", localSum, localSumSeq);
    }

    return(EXIT_SUCCESS);
}

int main_openmp_intro(){
    openmp_helloworld();
    return(EXIT_SUCCESS);
}

/*int main() {
    openmp_helloworld();
    openmp_helloworld_more_threads();
    add_floating_numbers();
    return(EXIT_SUCCESS);
}*/