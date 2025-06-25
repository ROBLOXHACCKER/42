#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern int g_moves;

typedef struct s_list
{
    int data;
    struct s_list *next;
    struct s_list *prev;
}t_list;


//TAKE ARGS_________________________________
int is_digit(char c);
int just_numbers(char *str);
int is_valid_number(char *str);

long int get_num(char **str);
int num_arg(char *argv);
void free_list(t_list *head);

void print_list(t_list *head);

int build_list(t_list **head, int n, int *i);
t_list *get_strlist(char *argv);
t_list *get_intlist(char **argv, int argc);
t_list *get_list(int argc, char **argv);
//____________________________________________

//MOVEMENT____________________________________
void	swap_a(t_list **a_head);
void	swap_b(t_list **b_head);
void	swap_ab(t_list **a_head, t_list **b_head);
void push_a(t_list **a_head, t_list **b_head);
void push_b(t_list **a_head, t_list **b_head);
void rotate_a(t_list **a_head);
void rotate_b(t_list **b_head);
void rotate_ab(t_list **a_head, t_list **b_head);
void reverse_rotate_a(t_list **a_head);
void reverse_rotate_b(t_list **b_head);
void reverse_rotate_ab(t_list **a_head, t_list **b_head);
//____________________________________________

//SORT________________________________________
void sort_stack(t_list **a_head, t_list **b_head);
//____________________________________________

#endif