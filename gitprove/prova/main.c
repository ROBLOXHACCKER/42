#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_node
{
    int data;
    struct s_node *next;
}t_node;

void add_front(t_node **head, int value)
{


}

void print_list(t_node *head)
{
    if(!head)
        return;
    while(head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
}

void add_back(t_node **head, int value)
{
    
    t_node *current = *head;
    t_node *temp = malloc(sizeof(t_node));
    if(!temp)
        return;
    temp->data = value;
    temp->next = NULL;
    if (!*head)
    {
        *head = temp;
        return;
    }
    while(current->next)
    {
        current = current->next;
    }
    current->next = temp;
}

void add_front(t_node **head, int value)
{
    t_node *temp = malloc(sizeof(t_node));
    if(!temp)
        return;
    temp->data = value;
    temp->next = NULL;
    if(!*head)
    {
        *head = temp;
        return;
    }
    temp->next = *head;
    *head = temp;
}

int count_nodes(t_node *head)
{
    int count_nodes = 0;
    if(!head)
        return 0;
    while(head)
    {
        head = head->next;
        count_nodes++;
    }
    return count_nodes;
}

int is_sorted(t_node *head)
{
    if (!head || !head->next)
        return 1;
    while (head->next)
    {
        if (head->data > head->next->data)
            return 0;
        head = head->next;
    }
    return 1;
}
void sort_list(t_node **head)
{
    if (!head || !*head)
        return;
    while (!is_sorted(*head))
    {
        t_node *n1 = *head;
        t_node *n2 = n1->next;
        while (n2)
        {
            if (n1->data > n2->data)
            {
                int tmp = n1->data;
                n1->data = n2->data;
                n2->data = tmp;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
    }
}

void remove_front(t_node **head)
{
    if(!head || !*head)
        return;
    t_node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
void remove_back(t_node **head)
{
    if (!head || !*head)
        return;
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    t_node *current = *head;
    while (current->next->next != NULL)
        current = current->next;
    free(current->next);
    current->next = NULL;
}
int main(void)
{
    t_node *head = NULL;
    head = malloc(sizeof(t_node));
    head->data = 42;
    head->next= NULL;
    printf("\nval node: %d\n", head->data);
    return (0);
}