#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define DATA_CNT 1000000
 
 
int num[DATA_CNT+5];
void swap(int *a, int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
 
int partition(int number[], int left, int right) {
    int i = left - 1;
    int j;
    for(j = left; j < right; j++) {
        if(number[j] <= number[right]) {
            i++;
            swap(&number[i], &number[j]);
        }
    }
 
    swap(&number[i+1], &number[right]);
    return i+1;
}
 
void quick_sort(int number[], int left, int right) {
    if(left < right) {
        int q = partition(number, left, right);
        quick_sort(number, left, q-1);
        quick_sort(number, q+1, right);
    }
}
 
int main(){
    struct timeval start;
    struct timeval end;
    unsigned long timer;
    srand(1);
    for (int i=0; i<DATA_CNT; i++){
        num[i]=rand();
    }
    gettimeofday(&start, NULL);
    quick_sort(num,0,DATA_CNT);
    gettimeofday(&end, NULL);
    for (int i=0; i<DATA_CNT; i++){
        printf("%d ", num[i]);
    }
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("Sorting performance %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    return 0;
}