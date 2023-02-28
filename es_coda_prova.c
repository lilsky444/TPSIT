typedef struct node
{
    int valore;
    struct node *next;
} Node;

void enqueue(Node** head, Node** tail, Node *element){
    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next = element;
    }

    *tail = element;
    element->next = NULL;
}

main(){
    Node *coda;
    int num;

    do
    {
        printf("Inserisci il valore del viodeogioco o -1 per  terminare\n");
        scanf("%d", &num);

        if (num != -1)
        {
            Node *elem;
            elem = (Node *)malloc(sizeof(Node));

            elem->valore = num;
            elem->next = NULL;
        }
    } while (num >= 0);
}