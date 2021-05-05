#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sort.h"
#define DATA_CNT 1000000

void testdata(){  
    char c;
    FILE *fp;
    srand(time(NULL));
    fp=fopen("dataset2.txt", "w");
    for (int i=0; i<DATA_CNT; i++){
        for (int j=0; j<100; j++){
            c=rand()%52;
            if (c<=25) c+='A';
            else c+='a'-26;
            fprintf(fp, "%c", c);
        }
        fprintf(fp, "\n"); 
    }
    fclose(fp);
    fp=fopen("dataset1.txt", "w");
    for (int i=0; i<DATA_CNT; i++){
        fprintf(fp, "%d\n", rand());
    }
    fclose(fp);
    return;
}

void result_num(int *arr, char *file){
    FILE *fp;
    fp=fopen(file, "w");
    for (int i=0; i<DATA_CNT; i++){
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
}

void result_str(char **arr, char *file){
    FILE *fp;
    fp=fopen(file, "w");
    for (int i=0; i<DATA_CNT; i++){
        fprintf(fp, "%s\n", arr[i]);
    }
    fclose(fp);
}

