#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int openmp_helloworld(){
    printf("OpenMP is running with %d threads.\n", omp_get_max_threads());

    omp_set_num_threads(4);
    #pragma omp parallel
    {
        //if(omp_get_thread_num() == 0) sleep(1);
        printf("Hello World from thread %d.\n", omp_get_thread_num());
    }

    return(EXIT_SUCCESS);
}

int main_openmp_intro(){
    openmp_helloworld();
    return(EXIT_SUCCESS);
}

/*
int main() {
    openmp_helloworld();
    return(EXIT_SUCCESS);
}*/