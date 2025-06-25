#include "../utils.h"

void print_list(t_list *head)
{
    t_list *tmp = head;
    while (tmp)
    {
        write(1, &tmp->data, 1);
        write(1, " ", 1);
        tmp = tmp->next;
    }
    write(1, "\n", 1);
}