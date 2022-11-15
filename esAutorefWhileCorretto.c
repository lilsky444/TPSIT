/*crea  una  lista e la  stampa*/
#include  <stdio.h>
#include  <stdlib.h>
typedef struct  node 
{
    int  valore;
    struct  node* next;
}Node;

void visualizzaStruct(Node *l){
    while (l != NULL) //fosse NULL vuol dire che siamo arrivati alla fine
    {
        printf("%d - %p \n",l->valore, l->next);
        l = l->next;
    }
}

void visualizzaLungStruct(Node *l){
    int cont = 0;

    while (l != NULL) //fosse NULL vuol dire che siamo arrivati alla fine
    {
        l = l->next;
        cont ++;
    }
    printf("Lunghezza Struct: %d", cont);
}

void stampaRicorsiva(Node *l){
    printf("%d - %p \n",l->valore, l->next);
    if (l->next != NULL)
    {
        printlist(l->next);
    }
}

int stampaRicorsivaCont(Node *l){
    if(l != NULL){
        return stampaRicorsivaCont(l->next) + 1;
    }
    return 0;
}

int  main()
{
    int n;
    Node* lista;
    Node* l;
    lista=NULL;
    
    do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d",&n);
        if (n>=0) 
        {
            if (lista==NULL) /*  prima  iterazione  */ 
            {
                lista = (Node*)  malloc(sizeof(Node));
                l = lista;
            }
            else /*  iterazioni  successive  */
            {
                l->next = (Node*)  malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n>=0);

    visualizzaStruct(lista);
    visualizzaLungStruct(lista);

    printf("\n");
    free(lista);
    free(l);
    return  0;
    }