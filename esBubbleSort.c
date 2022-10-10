#include <stdlib.h>
#include <stdio.h>

void caricaArray(int *p, int n){
    for(int k = 0; k < n; k++){
        printf("Inseire il %d numero: ", k+1);
        scanf("%d", p + k);
    }
}
 
//funzione per lo scambio
void scambio(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int *p, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (*p > *(p + 1))
                scambio(p, p + 1);
}

//visualizzo il vettore in ordine
void visArray(int *p, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", *(p + i));
    printf("\n");
}
 
int main()
{
    int n; //dimensione del vettore

    //do-while per far inserire una dimensione del vettore (che non sia minore di 0)
    do{
        printf("inserire la dimensione del vettore: ");
        scanf("%d", &n);
    }while(n < 0);

    int array[n];
    int *p;

    p = array;

    caricaArray(p, n);
    bubbleSort(p, n);
    visArray(p, n);

    return 0;
}