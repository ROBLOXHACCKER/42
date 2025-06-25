#include "../utils.h"

void rotate_a(t_list **a_head)
{
    if (!a_head || !*a_head || !(*a_head)->next)
        return;

    t_list *first = *a_head;
    t_list *last = *a_head;

    while (last->next)
        last = last->next;

    *a_head = first->next;
    (*a_head)->prev = NULL;

    last->next = first;
    first->prev = last;
    first->next = NULL;
}

void rotate_b(t_list **b_head)
{
    if (!b_head || !*b_head || !(*b_head)->next)
        return;

    t_list *first = *b_head;
    t_list *last = *b_head;

    while (last->next)
        last = last->next;

    *b_head = first->next;
    (*b_head)->prev = NULL;

    last->next = first;
    first->prev = last;
    first->next = NULL;

    //ft_putstr("rb\n");
}

void rotate_ab(t_list **a_head, t_list **b_head)
{
    rotate_a(a_head);
    rotate_b(b_head);
    //ft_putstr("rr\n");
}