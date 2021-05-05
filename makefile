all: main.c quicksort.o mergesort.o heapsort.o radixsort.o operation.o
	gcc main.c quicksort.o mergesort.o heapsort.o radixsort.o operation.o -o main.out
quicksort.o: quicksort.c sort.h
	gcc -c quicksort.c -o quicksort.o
mergesort.o: mergesort.c sort.h
	gcc -c mergesort.c -o mergesort.o
heapsort.o: heapsort.c sort.h
	gcc -c heapsort.c -o heapsort.o
radixsort.o: radixsort.c sort.h
	gcc -c radixsort.c -o radixsort.o
operation.o: operation.c sort.h
	gcc -c operation.c -o operation.o
clean:
	rm -f quicksort.o mergesort.o heapsort.o radixsort.o operation.o main.out