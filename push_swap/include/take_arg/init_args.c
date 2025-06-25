#include "../utils.h"

int build_list(t_list **head, int n, int *i)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return 0;
    new_node->data = n;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*i == 0)
        *head = new_node;
    else
    {
        t_list *current = *head;
        while (current->next)
            current = current->next;
        current->next = new_node;
        new_node->prev = current;
    }
    (*i)++;
    return 1; 
}

t_list *get_strlist(char *argv)
{
    if (!just_numbers(argv))
        return NULL;
    int argc = num_arg(argv);
    if (argc <= 0)
        return NULL;
    int i = 0;
    t_list *head = NULL;
    while (i != argc)
    {
        long int value = get_num(&argv);
        if (value < -2147483648L || value > 2147483647L)
        {
            free_list(head);
            return NULL;
        }
        int res = build_list(&head, (int)value, &i);
        if (!res)
        {
            free_list(head);
            return NULL;
        }
    }
    return head;
}

t_list *get_intlist(char **argv, int argc)
{ 
    t_list *head = NULL;
    int i = 0;
    while (i < argc)
    {
        char *temp = argv[i];
        long int num = get_num(&temp);
        if (is_valid_number(argv[i]) && num >= -2147483648L && num <= 2147483647L)
        {
            int res = build_list(&head, (int)num, &i);
            if (!res)
            {
                free_list(head);
                return NULL;
            }
        }
        else
        {
            free_list(head);
            return NULL;
        }
    }
    return head;
}

t_list *get_list(int argc, char **argv)
{
    t_list *head = NULL;

    if (argc < 2 || !argv || !*argv)
        return NULL;
    if (argc == 2)
        head = get_strlist(argv[1]);
    else
        head = get_intlist(argv + 1, argc - 1);
    return head;
}


