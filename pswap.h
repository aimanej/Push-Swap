#ifndef PSWAP_H
# define PSWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct t_list{
    int value;
    int index;
    struct t_list *next;

} s_list;

int	ft_atoi(const char *nptr, int *i);
int initstack(int ac, char **av, s_list **stack_a);
int ft_lstadback(s_list **lst, s_list *new);
void	ft_lstadd_front(s_list **lst, s_list *new);
s_list *ft_lstnew(int val);
s_list *ft_lstlast(s_list **lst);
int lmerda(int ac, char **av);
void lstclear(s_list **stack);
void swap(s_list **stack);
void push(s_list **stack_a, s_list **stack_b);
void rotate(s_list **stack);
void reverse_rotate(s_list **stack);
int lstsize(s_list *lst);
void push_swap(s_list **stack_a, s_list **stack_b);
int bitlen(int t);

void index_sorted_stack(s_list **stack_a);
void sort(int **arr, int size);

# endif