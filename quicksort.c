#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
 
void quick_swap_num(int *a, int *b){
    int c=*a;
    *a=*b;
    *b=c;
}

void quick_swap_str(char** a, char** b){
    char *c=*a;
    *a=*b;
    *b=c;
}

int partition_num(int *arr, int left, int right){
    int i = left;
    int j;
    for(j = left; j < right; j++){
        if(arr[j] <= arr[right]){
            quick_swap_num(&arr[i], &arr[j]);
            i++;
        }
    }
    quick_swap_num(&arr[i], &arr[right]);
    return i;
}

int partition_str(char **arr, int left, int right){
    int i = left;
    int j;
    for(j = left; j < right; j++){
        if(strcmp(arr[j],arr[right]) <= 0){
            quick_swap_str(&arr[i], &arr[j]);
            i++;
        }
    }
    quick_swap_str(&arr[i], &arr[right]);
    return i;
}
 
void quicksort_num(int *arr, int left, int right){
    if(left < right){
        int pivot = partition_num(arr, left, right);
        quicksort_num(arr, left, pivot-1);
        quicksort_num(arr, pivot+1, right);
    }
}

void quicksort_str(char **arr, int left, int right){
    if(left < right){
        int pivot = partition_str(arr, left, right);
        quicksort_str(arr, left, pivot-1);
        quicksort_str(arr, pivot+1, right);
    }
}