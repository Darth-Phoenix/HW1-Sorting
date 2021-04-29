#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "quicksort.h"
#include "mergesort.h"
#include "heapsort.h"
#include "testdata.h"
#define DATA_CNT 1000000
int num[DATA_CNT+5], data1[DATA_CNT+5];
char *str[DATA_CNT+5], *data2[DATA_CNT+5];

// void display_num(int *arr){
//     FILE *fp;
//     fp=fopen("result_num.txt", "w");
//     for (int i=0; i<DATA_CNT; i++){
//         fprintf(fp, "%d\n", arr[i]);
//     }
//     fclose(fp);
// }

// void display_str(char **arr){
//     FILE *fp;
//     fp=fopen("result_str.txt", "w");
//     for (int i=0; i<DATA_CNT; i++){
//         fprintf(fp, "%s\n", arr[i]);
//     }
//     fclose(fp);
// }

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
    quick_sort_num(num, 0, DATA_CNT-1);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    fprintf(fp2, "QuickSort integers performance %ld us (equal %f sec)\n", timer, timer / 1000000.0);

    memcpy(&num, &data1, sizeof(data1));
    gettimeofday(&start, NULL);
    merge_sort_num(num, 0, DATA_CNT-1);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    fprintf(fp2, "MergeSort integers performance %ld us (equal %f sec)\n", timer, timer / 1000000.0);

    memcpy(&num, &data1, sizeof(data1));
    gettimeofday(&start, NULL);
    heap_sort_num(num, DATA_CNT);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    fprintf(fp2, "HeapSort integers performance %ld us (equal %f sec)\n", timer, timer / 1000000.0); 
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
    quick_sort_str(str, 0, DATA_CNT-1);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    fprintf(fp2, "QuickSort strings performance %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    
    memcpy(str, data2, sizeof(data2));
    gettimeofday(&start, NULL);
    merge_sort_str(str, 0, DATA_CNT-1);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    fprintf(fp2, "MergeSort strings performance %ld us (equal %f sec)\n", timer, timer / 1000000.0);

    memcpy(str, data2, sizeof(data2));
    gettimeofday(&start, NULL);
    heap_sort_str(str, DATA_CNT);
    gettimeofday(&end, NULL);
    timer = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec - start.tv_usec;
    fprintf(fp2, "HeapSort strings performance %ld us (equal %f sec)\n", timer, timer / 1000000.0);
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}