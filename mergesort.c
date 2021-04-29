#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"
#define DATA_CNT 1000000
int *reg_str[DATA_CNT+5];
char reg_num[DATA_CNT+5];

void merge_num(int *arr, int left, int mid, int right){
    int i, j, k;
    int l_len=mid-left+1;
    int r_len=right-mid;
    i=j=0;
    k=left;
    while(i<l_len && j<r_len){
        if (arr[left+i]<=arr[mid+j+1]){
            reg_num[k]=arr[left+i];
            i++;
        }
        else {
            reg_num[k]=arr[mid+j+1];
            j++;
        }
        k++;
    }
    while(i<l_len){
        reg_num[k]=arr[left+i];
        i++;
        k++;
    }
    while(j<r_len){
        reg_num[k]=arr[mid+1+j];
        j++;
        k++;
    }
    for (i=left; i<=right; i++){
        arr[i]=reg_num[i];
    }
}

void merge_str(char **arr, int left, int mid, int right){
    int i, j, k;
    int l_len=mid-left+1;
    int r_len=right-mid;
    i=j=0;
    k=left;
    while(i<l_len && j<r_len){
        if (strcmp(arr[left+i],arr[mid+1+j])<=0){
            reg_str[k]=arr[left+i];
            i++;
        }
        else {
            reg_str[k]=arr[mid+1+j];
            j++;
        }
        k++;
    }
    while(i<l_len){
        reg_str[k]=arr[left+i];
        i++;
        k++;
    }
    while(j<r_len){
        reg_str[k]=arr[mid+1+j];
        j++;
        k++;
    }
    for (i=left; i<=right; i++){
                arr[i]=reg_str[i];
        }
}

void merge_sort_num(int *arr, int left, int right){
    if (left<right){
        int mid=(right+left)/2;
        merge_sort_num(arr, left, mid);
        merge_sort_num(arr, mid+1, right);
        merge_num(arr, left, mid, right);
    }
}

void merge_sort_str(char **arr, int left, int right){
    if (left<right){
        int mid=(right+left)/2;
        merge_sort_str(arr, left, mid);
        merge_sort_str(arr, mid+1, right);
        merge_str(arr, left, mid, right);
    }
}