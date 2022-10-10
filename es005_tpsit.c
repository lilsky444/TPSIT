#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYDIM 16600
#define NRIGA 1024

typedef struct valori {
    int rank;
    char* name;
    char* platform;
    int year;
    char* genre;
    char* casaMadre;
    float NA_sales;
    float EU_sales;
    float JP_sales;
    float other_sales;
    float global_sales;
} valori;

int dimFile(FILE *fp, char riga[]){
    int cont = 1;

    while(fgets(riga, NRIGA, fp) != EOF){
        cont ++;
    }

    return cont + 1;
}

int main() {
    FILE *fp;
    valori* p;
    int n = 0;

    char riga[NRIGA];

    fp = fopen("vgsales.csv", "r");

    n = dimFile(fp, riga);

    if(fp == NULL) {
        printf("WARNING: the file doesn't exist!");
        return 0;
    }

    printf("sono dentro");

    p = (valori*)malloc(n * sizeof(valori));

    while(fgets(riga, NRIGA, fp) != EOF) {//chiede un array di char, la lunghezza dell'array, il nome del file

        (*p).rank = atoi(strtok(riga,","));
        (*p).name = strtok(NULL, ",");
        (*p).platform = strtok(NULL, ",");
        (*p).year = atoi(strtok(NULL, ","));
        (*p).genre = strtok(NULL, ",");
        (*p).casaMadre = strtok(NULL, ",");
        (*p).NA_sales = atof(strtok(NULL, ","));
        (*p).EU_sales = atof(strtok(NULL, ","));
        (*p).JP_sales = atof(strtok(NULL, ","));
        (*p).other_sales = atof(strtok(NULL, ","));
        (*p).global_sales = atof(strtok(NULL, ","));

        printf("\n %d, %s, %s, %d, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f", (*p).rank, (*p).name, (*p).platform,
               (*p).year, (*p).genre, (*p).casaMadre, (*p).NA_sales, (*p).EU_sales, (*p).JP_sales,
               (*p).other_sales, (*p).global_sales);

        p++;
    }

    fclose(fp);

    return 1;
}