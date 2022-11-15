#include <stdio.h>
#include <stdlib.h>

#define LUNG 20

typedef char String[LUNG];

typedef struct node{
    String nome;
    struct node *next;
}Node;

int main(){
    Node *lista = (Node*)malloc(sizeof(Node));
    char risp;

    do{
        printf("Inserire un nome: ");
        scanf("%s", lista->nome);
        printf("Nome1: %s", lista->nome);
        lista->next = NULL;
           
        printf("\nvuoi continuare?");
        scanf("%c", risp);
    }while(risp == 'n');
}