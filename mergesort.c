#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#define DATA_CNT 1000000
char *reg_str[DATA_CNT+5];
int reg_num[DATA_CNT+5];

void merge_num(int *arr, int left, int mid, int right){
    int begin_1=left,end_1=mid;
    int begin_2=mid+1, end_2=right;
    int k=left;
    while(begin_1<=end_1 && begin_2<=end_2){
        if (arr[begin_1]<=arr[begin_2]) reg_num[k++]=arr[begin_1++];
        else reg_num[k++]=arr[begin_2++];
    }
    while(begin_1<=end_1) reg_num[k++]=arr[begin_1++];      
    while(begin_2<=end_2) reg_num[k++]=arr[begin_2++];
    for (int i=left; i<=right; i++) arr[i]=reg_num[i];  
}

void merge_str(char **arr, int left, int mid, int right){
    int begin_1=left,end_1=mid;
    int begin_2=mid+1, end_2=right;
    int k=left;
    while(begin_1<=end_1 && begin_2<=end_2){
        if (strcmp(arr[begin_1],arr[begin_2])<=0) reg_str[k++]=arr[begin_1++];
        else reg_str[k++]=arr[begin_2++];
    }
    while(begin_1<=end_1) reg_str[k++]=arr[begin_1++];      
    while(begin_2<=end_2) reg_str[k++]=arr[begin_2++];
    for (int i=left; i<=right; i++) arr[i]=reg_str[i];  
}

void mergesort_num(int *arr, int left, int right){
    if (left<right){
        int mid=(right+left)/2;
        mergesort_num(arr, left, mid);
        mergesort_num(arr, mid+1, right);
        merge_num(arr, left, mid, right);
    }
}

void mergesort_str(char **arr, int left, int right){
    if (left<right){
        int mid=(right+left)/2;
        mergesort_str(arr, left, mid);
        mergesort_str(arr, mid+1, right);
        merge_str(arr, left, mid, right);
    }
}