#include "../utils.h"

static void	swap(t_list **head)
{
	t_list	*first;
	t_list	*second;
	int		temp;
	
	if (!head || !*head || !(*head)->next)
		return;

	first = *head;
	second = first->next;
	temp = first->data;
	first->data = second->data;
	second->data = temp;
}

void	swap_a(t_list **a_head)
{
	swap(a_head);
}

void	swap_b(t_list **b_head)
{
	swap(b_head);
}

void	swap_ab(t_list **a_head, t_list **b_head)
{
	swap(a_head);
	swap(b_head);
}
