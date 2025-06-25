#include "../include/utils.h"

// Funzione per trovare il numero di bit necessari per rappresentare il numero più grande
static int get_max_bits(t_list *head)
{
    t_list *current;
    int max_num;
    int max_bits;

    current = head;
    max_num = current->data;
    while (current)
    {
        if (current->data > max_num)
            max_num = current->data;
        current = current->next;
    }
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

// Funzione per verificare se un numero ha un bit specifico impostato
static int get_bit(int num, int bit)
{
    return ((num >> bit) & 1);
}

// Funzione principale di ordinamento
void sort_stack(t_list **a_head, t_list **b_head)
{
    t_list *current;
    int i;
    int j;
    int size;
    int max_bits;

    size = 0;
    current = *a_head;
    while (current)
    {
        size++;
        current = current->next;
    }
    max_bits = get_max_bits(*a_head);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            current = *a_head;
            if (get_bit(current->data, i) == 0)
                push_b(a_head, b_head);
            else
                rotate_a(a_head);
            j++;
        }
        while (*b_head)
            push_a(a_head, b_head);
        i++;
    }
} 