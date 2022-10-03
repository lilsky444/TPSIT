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
    char riga[ARRAYDIM];

    fp = fopen("vgsales.csv", "r");

    if(fp == NULL) {
        printf("WARNING: the file doesn't exist!");
        return 0;
    }

    printf("sono dentro");

    while(fgets(riga, ARRAYDIM, fp) != EOF) {//chiede un array di char, la lunghezza dell'array, il nome del file

        giochi[k].rank = atoi(strtok(riga,","));
        giochi[k].name = strtok(NULL, ",");
        giochi[k].platform = strtok(NULL, ",");
        giochi[k].year = atoi(strtok(NULL, ","));
        giochi[k].genre = strtok(NULL, ",");
        giochi[k].casaMadre = strtok(NULL, ",");
        giochi[k].NA_sales = atof(strtok(NULL, ","));
        giochi[k].EU_sales = atof(strtok(NULL, ","));
        giochi[k].JP_sales = atof(strtok(NULL, ","));
        giochi[k].other_sales = atof(strtok(NULL, ","));
        giochi[k].global_sales = atof(strtok(NULL, ","));


        printf("\n %d, %s, %s, %d, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f", giochi[k].rank, giochi[k].name, giochi[k].platform, giochi[k].year,
               giochi[k].genre, giochi[k].casaMadre, giochi[k].NA_sales, giochi[k].EU_sales, giochi[k].JP_sales, giochi[k].other_sales,
               giochi[k].global_sales);

        k++;
    }

    fclose(fp);

    return 1;
}
