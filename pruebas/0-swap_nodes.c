#include "lists.h"

size_t print_listint(const listint_t *h)
{
    size_t number_nodes;

    for (number_nodes = 0; h != NULL; number_nodes++)
    {
        printf("%d\n", h->n);
        h = h->next;
    }

    return (number_nodes);
}


listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new;

    if (head == NULL)
    {
        return (NULL);
    }
    new = malloc(sizeof(listint_t));

    if (new == NULL)
    {
        return (NULL);
    }
    new->n = n;
    new->next = *head;

    *head = new;
    return (new);
}


listint_t *swap_nodes(listint_t **head, unsigned int index)
{
    listint_t *prev, *current;
    unsigned int i = 0;

        
}

int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint(head);
    return (0);
}