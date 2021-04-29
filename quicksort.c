#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
 
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
    int i = left - 1;
    int j;
    for(j = left; j < right; j++){
        if(arr[j] <= arr[right]){
            i++;
            quick_swap_num(&arr[i], &arr[j]);
        }
    }
    quick_swap_num(&arr[i+1], &arr[right]);
    return i+1;
}

int partition_str(char **arr, int left, int right){
    int i = left - 1;
    int j;
    for(j = left; j < right; j++){
        if(strcmp(arr[j],arr[right]) <= 0){
            i++;
            quick_swap_str(&arr[i], &arr[j]);
        }
    }
    quick_swap_str(&arr[i+1], &arr[right]);
    return i+1;
}
 
void quick_sort_num(int *arr, int left, int right){
    if(left < right){
        int q = partition_num(arr, left, right);
        quick_sort_num(arr, left, q-1);
        quick_sort_num(arr, q+1, right);
    }
}

void quick_sort_str(char **arr, int left, int right){
    if(left < right){
        int q = partition_str(arr, left, right);
        quick_sort_str(arr, left, q-1);
        quick_sort_str(arr, q+1, right);
    }
}