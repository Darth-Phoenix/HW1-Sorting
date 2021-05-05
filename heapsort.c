#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

void heap_swap_num(int *arr, int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void heap_swap_str(char **arr, int a, int b){
    char *temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void heapify_num(int *arr, int n, int i){ 
    int c1=2*i+1;
    int c2=2*i+2;
    int max=i;
    if (c1<n && arr[c1]>arr[max]){
        max=c1;
    }
    if (c2<n && arr[c2]>arr[max]){
        max=c2;
    }
    if (max!=i){
        heap_swap_num(arr, max, i);
        heapify_num(arr, n, max);
    }
}

void heapify_str(char **arr, int n, int i){ 
    int c1=2*i+1;
    int c2=2*i+2;
    int max=i;
    if (c1<n && strcmp(arr[c1], arr[max]) > 0){
        max=c1;
    }
    if (c2<n && strcmp(arr[c2], arr[max]) > 0){
        max=c2;
    }
    if (max!=i){
        heap_swap_str(arr, max, i);
        heapify_str(arr, n, max);
    }
}

void heapsort_num(int *arr, int n){
    for (int i=n/2-1; i>=0; i--){
        heapify_num(arr, n, i);
    }
    for (int i=n-1; i>=0; i--){
        heap_swap_num(arr, i, 0);
        heapify_num(arr, i, 0);
    }
}

void heapsort_str(char **arr, int n){
    for (int i=n/2-1; i>=0; i--){
        heapify_str(arr, n, i);
    }
    for (int i=n-1; i>=0; i--){
        heap_swap_str(arr, i, 0);
        heapify_str(arr, i, 0);
    }
}

