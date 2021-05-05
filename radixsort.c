#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#define DATA_CNT 1000000
int output1[DATA_CNT+5];
char *output2[DATA_CNT+5];

void radixsort_num(int *arr, int n){
    int exp=1;
    for (int i=1; i<=10; i++){
        int count[10]={0};
        for (int j=0; j<n; j++){
            count[(arr[j]/exp)%10]++;
        }
        for (int j=1; j<10; j++){
            count[j]+=count[j-1];
        }
        for (int j=n-1; j>=0; j--){
            output1[count[(arr[j]/exp)%10]-1]=arr[j];
            count[(arr[j]/exp)%10]--;
        }
        exp*=10;
        for (int j=0; j<n; j++){
            arr[j]=output1[j];
        }
    }
}

void radixsort_str(char **arr, int n){
    for (int i=0; i<n; i++){
        output2[i]=(char*)malloc(sizeof(char)*100);
    }
    for (int i=0; i<100; i++){
        int count[58]={0};
        for (int j=0; j<n; j++){
            count[arr[j][99-i]%65]++;
        }
        for (int j=1; j<58; j++){
            count[j]+=count[j-1];
        }
        for (int j=n-1; j>=0; j--){
            output2[count[arr[j][99-i]%65]-1]=arr[j];
            count[arr[j][99-i]%65]--;
        }
        for (int j=0; j<n; j++){
            arr[j]=output2[j];
        }
    }
}
