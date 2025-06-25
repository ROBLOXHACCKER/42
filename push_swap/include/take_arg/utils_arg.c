#include "../utils.h"

long int get_num(char **str)
{
    long int num = 0;
    int sign = 1;

    while (**str == ' ')
        (*str)++;
    if (**str == '-' || **str == '+')
    {
        if (**str == '-')
            sign = -1;
        (*str)++;
    }
    while (is_digit(**str))
    {
        num = num * 10 + (**str - '0');
        (*str)++;
    }
    return (num * sign);
}

int num_arg(char *str)
{
    int count = 0;
    int in_number = 0;

    while (*str)
    {
        if (*str != ' ' && !in_number)
        {
            in_number = 1;
            count++;
        }
        else if (*str == ' ')
            in_number = 0;
        str++;
    }
    return count;
}

void free_list(t_list *head)
{
    t_list *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}