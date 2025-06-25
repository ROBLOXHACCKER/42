#include "../include/utils.h"

int build_list(t_list **head, int n, int *i)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (0);
    new->data = n;
    new->next = *head;
    new->prev = NULL;
    if (*head)
        (*head)->prev = new;
    *head = new;
    (*i)++;
    return (1);
}

void free_list(t_list *head)
{
    t_list *tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void print_list(t_list *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
} 
