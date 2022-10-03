#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYDIM 1024

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

int main() {
    FILE *fp;
    int k = 0;
    valori giochi[ARRAYDIM];
    valori* p;

    p = giochi;

    char riga[ARRAYDIM];

    fp = fopen("vgsales.csv", "r");

    if(fp == NULL) {
        printf("WARNING: the file doesn't exist!");
        return 0;
    }

    printf("sono dentro");

    while(fgets(riga, ARRAYDIM, fp) != EOF) {//chiede un array di char, la lunghezza dell'array, il nome del file

        (p + k)->rank = atoi(strtok(riga,","));
        (p + k)->name = strtok(NULL, ",");
        (p + k)->platform = strtok(NULL, ",");
        (p + k)->year = atoi(strtok(NULL, ","));
        (p + k)->genre = strtok(NULL, ",");
        (p + k)->casaMadre = strtok(NULL, ",");
        (p + k)->NA_sales = atof(strtok(NULL, ","));
        (p + k)->EU_sales = atof(strtok(NULL, ","));
        (p + k)->JP_sales = atof(strtok(NULL, ","));
        (p + k)->other_sales = atof(strtok(NULL, ","));
        (p + k)->global_sales = atof(strtok(NULL, ","));

        printf("\n %d, %s, %s, %d, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f", (p + k)->rank, (p + k)->name, (p + k)->platform,
               (p + k)->year, (p + k)->genre, (p + k)->casaMadre, (p + k)->NA_sales, (p + k)->EU_sales, (p + k)->JP_sales,
               (p + k)->other_sales, (p + k)->global_sales);

        k++;
    }

    fclose(fp);

    return 1;
}
