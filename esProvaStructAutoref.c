#include <stdio.h>
#include <stdlib.h>

#define LUNG 20

typedef char String[LUNG];

typedef struct node{
    String nome;
    struct node *next;
}Node;

int main(){
    Node *lista;
    lista = (Node*)malloc(sizeof(Node));
    Node *temp = (Node*)malloc(sizeof(Node));
    Node *temp2 = (Node*)malloc(sizeof(Node));
    
    printf("Inserire un nome: ");
    scanf("%s", lista->nome);
    printf("Nome1: %s", lista->nome);
    lista->next = NULL;

    printf("\nInserire un nome: ");
    scanf("%s", temp->nome);
    printf("Nome2: %s", temp->nome);
    temp->next = NULL;

    lista->next = temp;
    printf("\nInserire un nome: ");
    scanf("%s", temp2->nome);
    printf("Nome3: %s", temp2->nome);
    temp2->next = NULL;

    lista->next->next = temp2;
    printf("\nNome1: %s\nNome2: %s\nNome3: %s", lista->nome, lista->next->nome, lista->next->next->nome);

    //printf("Funziona: %s", lista->nome);
    free(lista);
    free(temp);
    free(temp2);

    return 0;
}