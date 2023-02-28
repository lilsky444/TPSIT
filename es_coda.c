#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int valore;
    struct node *next; // indirizzo del nodo successivo
} Node;

void cancellaNodo(Node **head, int element)
{
    Node *temp = *head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (element > 5)
        {
            prev = temp;
            temp->next = NULL;
        }
    }

    free(temp);
}

void inserimento(Node **head, Node *element)
{
    Node *curr = *head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (element->valore <= curr->valore)
            break;
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL)
    {
        *head = element;
    }
    else
    {
        prev->next = element;
    }

    element->next = curr;
}

void stampa(Node *l)
{

    int k = 0;
    // printf("STAMPA CON PROC: \n");
    while (l != NULL && k < 5) // puntatore alla lista diversa da NULL
    {
        printf("\n%d \n",l->valore);
        l = l->next; // assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
        k++;
    }
}

int main()
{
    int n;
    Node *lista; // tipo a puntatore a node
    lista = NULL;
    int k = 0;

    do
    {
        printf("Inserisci un valore\n");
        scanf("%d", &n);

        if (n != -1)
        {
            Node *elem;
            elem = (Node*)malloc(sizeof(Node));

            elem->valore = n;
            elem->next = NULL;

            inserimento(&lista, elem);
        }

    } while (n >= 0);

    // l = lista;
    stampa(lista);

    return 0;
}