#include "../utils.h"

void reverse_rotate_a(t_list **a_head)
{
    if (!a_head || !*a_head || !(*a_head)->next)
        return;

    t_list *last = *a_head;
    t_list *second_last = NULL;

    while (last->next)
    {
        second_last = last;
        last = last->next;
    }

    if (second_last)
        second_last->next = NULL;

    last->next = *a_head;
    last->prev = NULL;
    (*a_head)->prev = last;
    *a_head = last;     
}

void reverse_rotate_b(t_list **b_head)
{
    if (!b_head || !*b_head || !(*b_head)->next)
        return;

    t_list *last = *b_head;
    t_list *second_last = NULL;

    while (last->next)
    {
        second_last = last;
        last = last->next;
    }

    if (second_last)
        second_last->next = NULL;

    last->next = *b_head;
    last->prev = NULL;
    (*b_head)->prev = last;
    *b_head = last;
}

void reverse_rotate_ab(t_list **a_head, t_list **b_head)
{
    reverse_rotate_a(a_head);
    reverse_rotate_b(b_head);
}