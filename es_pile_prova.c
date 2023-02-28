#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_node
{
    char parentesi;
    struct stack_node *next; // indirizzo del nodo successivo
} Node;

int is_empty(Node* head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(struct strack_node** head, struct stack_node* element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

Node* pop(Node** head){
    Node *ret = *head;

    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

    return ret;
}

void stampa(Node *p)
{

    int k = 0;
    while (p != NULL && k < 5)
    {
        printf("\n%c", p->parentesi);
        p = p->next;
        k++;
    }
}

main(){
    char* espressione;
    Node *pila;
    pila = NULL;

    espressione = (char*)malloc(sizeof(char));

    printf("Inserisci un'espressione: ");
    fflush(stdin);
    gets(espressione);

    int len = strlen(espressione);
    espressione[len - 1] = 0;

    for(int i = 0; i < len; i++){
        if(espressione[i] == '(' || espressione[i] == '[' || espressione[i] == '{'){
            push(pila, espressione[i]);
        }
    }
    stampa(pila);
    free(espressione);
}
