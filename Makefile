lab-sheet-01/timing_of_loops.o: lab-sheet-01/timing_of_loops.c lab-sheet-01/timing_of_loops.h
	gcc -c lab-sheet-01/timing_of_loops.c -o lab-sheet-01/timing_of_loops.o


lab_02: lab-sheet-02/openmp_intro.c lab-sheet-02/openmp_intro.h
	gcc -fopenmp -c lab-sheet-02/openmp_intro.c -o lab-sheet-02/openmp_intro.o


main.o: main.c lab-sheet-01/timing_of_loops.h lab-sheet-02/openmp_intro.h
	gcc -c main.c


main: main.o lab-sheet-01/timing_of_loops.o lab-sheet-02/openmp_intro.o
	gcc -fopenmp lab-sheet-01/timing_of_loops.o lab-sheet-02/openmp_intro.o main.o -o main