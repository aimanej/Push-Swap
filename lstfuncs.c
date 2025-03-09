#include "pswap.h"

void sa(s_list **stack)
{
    if(!*stack || !(*stack)->next)
        return;
    s_list *temp_first;
    s_list *temp_second;

    temp_first = *stack;
    temp_second = (*stack)->next;

    temp_first->next = temp_second->next;
    temp_second->next = temp_first;
    *stack = temp_second;
}
void	ft_lstadd_front(s_list **lst, s_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void push(s_list **from, s_list **to)
{
    if(!*from)
        return;
    s_list *temp;

    temp = *from;
    *from = (*from)->next;
    temp->next = NULL;
    ft_lstadd_front(to, temp);
    
}

void rotate(s_list **stack)
{
    s_list *temp_first;
    s_list *temp_last;
    s_list *temp_third;

    temp_first = *stack;
    temp_last = ft_lstlast(stack);

    temp_last->next = (*stack)->next;
    temp_third = *stack;
    while(temp_third->next->next)
        temp_third = temp_third->next;
    temp_third->next = temp_first;
    temp_first->next = NULL;
    *stack = temp_last;
}