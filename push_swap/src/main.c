#include "../include/utils.h"

int main(int argc, char **argv)
{
    t_list *a_head;
    t_list *b_head;

    if (argc < 2)
        return (1);

    a_head = get_list(argc, argv);
    if (!a_head)
        return (1);

    b_head = NULL;
    sort_stack(&a_head, &b_head);
    free_list(a_head);
    free_list(b_head);
    return (0);
}