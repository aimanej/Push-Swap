#include "pswap.h"

int ft_len(char *str)
{
    int t = 0;

    while(str[t])
        t++;
    return t;
}
void initstack(int ac, char **av, s_list **stack_a)
{
    int i;
    int t = 1;

    while(av[t])
    {
        i = 0;
        while(av[t][i])
        {
            ft_lstadback(&*stack_a, ft_lstnew(ft_atoi(av[t], &i)));
        }
        t++;
    }    
    // }
    
    
}
int main(int ac, char **av)
{
    s_list *stack_a;
    s_list *stack_b;

    stack_a = NULL;
    stack_b = NULL;

    if (ac == 1)
        return (0);
    initstack(ac, av, &stack_a);
    while (stack_a)
    {
        printf("   %d \n", stack_a->value);
        stack_a = stack_a->next;
    }
}