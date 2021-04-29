#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heapsort.h"

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

void heapify_num(int *tree, int n, int i){ 
    int c1=2*i+1;
    int c2=2*i+2;
    int max=i;
    if (c1<n && tree[c1]>tree[max]){
        max=c1;
    }
    if (c2<n && tree[c2]>tree[max]){
        max=c2;
    }
    if (max!=i){
        heap_swap_num(tree, max, i);
        heapify_num(tree, n, max);
    }
}

void heapify_str(char **tree, int n, int i){ 
    int c1=2*i+1;
    int c2=2*i+2;
    int max=i;
    if (c1<n && strcmp(tree[c1], tree[max]) > 0){
        max=c1;
    }
    if (c2<n && strcmp(tree[c2], tree[max]) > 0){
        max=c2;
    }
    if (max!=i){
        heap_swap_str(tree, max, i);
        heapify_str(tree, n, max);
    }
}

void heap_sort_num(int *tree, int n){
    for (int i=n/2-1; i>=0; i--){
        heapify_num(tree, n, i);
    }
    for (int i=n-1; i>=0; i--){
        heap_swap_num(tree, i, 0);
        heapify_num(tree, i, 0);
    }
}

void heap_sort_str(char **tree, int n){
    for (int i=n/2-1; i>=0; i--){
        heapify_str(tree, n, i);
    }
    for (int i=n-1; i>=0; i--){
        heap_swap_str(tree, i, 0);
        heapify_str(tree, i, 0);
    }
}

