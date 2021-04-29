#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "testdata.h"
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