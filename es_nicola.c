#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct node {
    int n;
    struct node *next;
} Node;

Node *createNode(int x) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->next = NULL;
    n->n = x;
}

bool isEmpty(Node *list) {
    return list == NULL;
}

void push(Node **head, Node *el) {
    if (!isEmpty(*head))
        el->next = *head;
    else
        el->next = NULL;
    *head = el;
}

Node *pop(Node **head) {
    if (isEmpty(*head))
        return NULL;
    Node *ret = *head;
    *head = ret->next;
    return ret;
}

//funzione che stampa
void stampaCoda(Node *queue) {
    if (isEmpty(queue))
        return;
    printf("\nnumero coda: %d", queue->n);
    if (queue->next != NULL)
        stampaCoda(queue->next);
}

//stampa pila
void stampaPila(Node *l) {
    //printf("STAMPA CON PROC: \n");
    while (l != NULL)                                  //puntatore alla lista diversa da NULL
    {
        printf("\nstampa pila: %d", l->n);
        l = l->next;                                          //assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
    }
}

//funzione enqueu inserisce elementi
void enqueu(Node **head, Node **tail, Node *element) {
    if (isEmpty(*head)) {
        *head = element;
    } else {
        (*tail)->next = element;
    }
    *tail = element;
    element->next = NULL;
}

//funzione dequeu per l'estrazione del dato
Node *dequeu(Node **head, Node **tail) {
    Node *ret = *head;
    if (isEmpty(*head))
        return NULL;
    *head = ret->next;

    if (isEmpty(*head)) {
        *tail = NULL;
    }
    return ret;
}

void freeQueue(Node *queue) {
    if (queue->next != NULL)
        freeQueue(queue->next);
    free(queue);
}

void freePila(Node *l) {
    if (l->next != NULL)
        freePila(l->next);
    free(l);
}

int main() {
    //head e tail del nuovo processo
    Node *h = NULL;
    Node *t = NULL;
    int n, cont = 0, k = 0, cont2 = 0, k1 = 0;
    bool g = true, g1 = true;

    Node *coda = NULL;

    do {
        printf("inserisci un numero: ");
        scanf("%d", &n);
        if (n != -1) {
            coda = (Node *) malloc(sizeof(Node));
            coda->n = n;
            coda->next = NULL;
            enqueu(&h, &t, coda);
            cont++;
        }
    } while (n != -1);
    stampaCoda(h);
    printf("\n");

    Node *pila = NULL;

    while (k < cont && g == true) {
        //printf("ecco\n");
        if (isEmpty(h))
            g = false;
        else {
            //printf("%d\n", h->n);
            if (h->n > 5) {
                //printf("sono qua\n");
                Node *exit = dequeu(&h, &t);
                push(&pila, exit);
                cont2++;
            } else {
                Node *exit1 = dequeu(&h, &t);
                enqueu(&h, &t, exit1);
            }
        }
        k++;
    }
    stampaCoda(h);
    printf("\n");
    stampaPila(pila);
    printf("\n\n");

    while (k1 < cont2 && g1 == true) {
        //printf("eccomi\n");
        if (isEmpty(pila))
            g1 = false;
        else {
            if (pila->n > 10) {
                Node *exit2 = pop(&pila);
                enqueu(&h, &t, exit2);
            } else {
                Node *exit2 = pop(&pila);
                push(&pila, exit2);
            }
        }
        k1++;
    }

    stampaCoda(h);
    printf("\n");
    stampaPila(pila);


    //free della coda e della pila
    freeQueue(t);
    freePila(pila);
    return 0;
}