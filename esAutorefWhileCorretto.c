/*crea  una  lista e la  stampa*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valore;
    struct node *next;
} Node;

void insert_ordered_by_value(Node **head, Node *elemento)
{
    Node *curr = *head, *prev = NULL;

    while (curr != NULL)
    {
        if (elemento->valore <= curr->valore)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL)
    {
        *head = elemento;
    }
    else
    {
        prev->next = elemento;
    }

    elemento->next = curr;
}

void visualizzaStruct(Node *l)
{
    while (l != NULL) // fosse NULL vuol dire che siamo arrivati alla fine
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;
    }
}

void visualizzaLungStruct(Node *l)
{
    int cont = 0;

    while (l != NULL) // fosse NULL vuol dire che siamo arrivati alla fine
    {
        l = l->next;
        cont++;
    }
    printf("Lunghezza Struct: %d", cont);
}

/*void stampaRicorsiva(Node *l)
{
    printf("%d - %p \n", l->valore, l->next);
    if (l->next != NULL)
    {
        printlist(l->next);
    }
}*/

int stampaRicorsivaCont(Node *l)
{
    if (l != NULL)
    {
        return stampaRicorsivaCont(l->next) + 1;
    }
    return 0;
}

int main()
{
    int n;
    Node *lista;
    Node *l;
    lista = NULL;
    

    do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d", &n);
        
        if (n != -1){
            Node *newElement;
            newElement = (Node*)  malloc(sizeof(Node));

            newElement->valore = n;
            newElement->next = NULL;

            insert_ordered_by_value(&lista, &newElement);
        }
    } while (n >= 0);

    visualizzaStruct(lista);
    visualizzaLungStruct(lista);

    printf("\n");
    return 0;