#include "../utils.h"

void push_a(t_list **a_head, t_list **b_head)
{
    t_list *tmp;

    if (!b_head || !*b_head)
        return;

    tmp = *b_head;            
    *b_head = tmp->next;      
    if (*b_head)
        (*b_head)->prev = NULL;
    if (*a_head)
        (*a_head)->prev = tmp;
    tmp->prev = NULL;
    tmp->next = *a_head;      
    *a_head = tmp;            
    write(1, "pa\n", 3);
}

void push_b(t_list **a_head, t_list **b_head)
{
    t_list *tmp;

    if(!*a_head || !a_head)
        return;
    
    tmp = *a_head;
    *a_head = tmp->next;
    if (*a_head)
        (*a_head)->prev = NULL;
    if (*b_head)
        (*b_head)->prev = tmp;
    tmp->prev = NULL;
    tmp->next = *b_head;
    *b_head = tmp;
    write(1, "pb\n", 3);
}