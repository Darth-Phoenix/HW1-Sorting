all: main.c quicksort.o mergesort.o heapsort.o testdata.o
	gcc main.c quicksort.o mergesort.o heapsort.o testdata.o -o main.out
quicksort.o: quicksort.c quicksort.h
	gcc -c quicksort.c -o quicksort.o
mergesort.o: mergesort.c mergesort.h
	gcc -c mergesort.c -o mergesort.o
heapsort.o: heapsort.c heapsort.h
	gcc -c heapsort.c -o heapsort.o
testdata.o: testdata.c testdata.h
	gcc -c testdata.c -o testdata.o
clean:
	rm -f quicksort.o mergesort.o heapsort.o testdata.o main.out