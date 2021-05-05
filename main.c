#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "sort.h"
#define DATA_CNT 1000000
int num[DATA_CNT+5], data1[DATA_CNT+5];
char *str[DATA_CNT+5], *data2[DATA_CNT+5];

int main(){  
    FILE *fp1, *fp2;
    struct timeval start;
    struct timeval end;
    unsigned long timer;
    testdata();
    fp1=fopen("dataset1.txt", "r");
    fp2=fopen("performance.txt", "w");
    for (int i=0; i<DATA_CNT; i++){
        fscanf(fp1, "%d", &data1[i]);
    }

    memcpy(&num, &data1, sizeof(data1));
    gettimeofday(&start, NULL);
    quicksort_num(num, 0, DATA_CNT-1);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    result_num(num, "quick_result1.txt");
    fprintf(fp2, "QuickSort integers performance %ld us (equal %f sec)\n", timer, timer / 1000000.0);

    memcpy(&num, &data1, sizeof(data1));
    gettimeofday(&start, NULL);
    mergesort_num(num, 0, DATA_CNT-1);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    result_num(num, "merge_result1.txt");
    fprintf(fp2, "MergeSort integers performance %ld us (equal %f sec)\n", timer, timer / 1000000.0);

    memcpy(&num, &data1, sizeof(data1));
    gettimeofday(&start, NULL);
    heapsort_num(num, DATA_CNT);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    result_num(num, "heap_result1.txt");
    fprintf(fp2, "HeapSort integers performance %ld us (equal %f sec)\n", timer, timer / 1000000.0); 

    memcpy(&num, &data1, sizeof(data1));
    gettimeofday(&start, NULL);
    radixsort_num(num, DATA_CNT);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    result_num(num, "radix_result1.txt");
    fprintf(fp2, "RadixSort integers performance %ld us (equal %f sec)\n", timer, timer / 1000000.0); 

    fclose(fp1);

    fp1=fopen("dataset2.txt", "r");
    for (int i=0; i<DATA_CNT; i++){
        *(data2+i)=(char*)malloc(sizeof(char)*105);         
        *(str+i)=(char*)malloc(sizeof(char)*105);
    }
    for (int i=0; i<DATA_CNT; i++){
        fscanf(fp1, "%s", data2[i]);
    }

    memcpy(str, data2, sizeof(data2));
    gettimeofday(&start, NULL);
    quicksort_str(str, 0, DATA_CNT-1);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    result_str(str, "quick_result2.txt");
    fprintf(fp2, "QuickSort strings performance %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    
    memcpy(str, data2, sizeof(data2));
    gettimeofday(&start, NULL);
    mergesort_str(str, 0, DATA_CNT-1);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    result_str(str, "merge_result2.txt");
    fprintf(fp2, "MergeSort strings performance %ld us (equal %f sec)\n", timer, timer / 1000000.0);

    memcpy(str, data2, sizeof(data2));
    gettimeofday(&start, NULL);
    heapsort_str(str, DATA_CNT);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    result_str(str, "heap_result2.txt");
    fprintf(fp2, "HeapSort strings performance %ld us (equal %f sec)\n", timer, timer / 1000000.0);

    memcpy(str, data2, sizeof(data2));
    gettimeofday(&start, NULL);
    radixsort_str(str, DATA_CNT);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    result_str(str, "radix_result2.txt");
    fprintf(fp2, "RadixSort strings performance %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}