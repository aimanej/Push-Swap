#include "pswap.h"

int initstack(int ac, char **av, s_list **stack_a)
{
    int i;
    int t = 1;

    while(ac > t)
    {
        i = 0;
        while(av[t][i])
        {
            if(!ft_lstadback(&*stack_a, ft_lstnew(ft_atoi(av[t], &i))))
                {
                    lstclear(&*stack_a);
                    return 0;
                }
        }
        t++;
    }    
    return 1;
    // }
    
    
}
int lmerda(int ac, char **av)
{
    int t;
    int p;

    t = 1;
    if(ac == 1)
        return 0;
    while(t < ac)
    {
        p = 0;
        if(!av[t] || !*av[t])
            return 0;
        while(av[t][p])
        {
            if(av[t][p] != ' ' && av[t][p] != '+' && av[t][p] != '-' && (!(av[t][p] >= '0' && av[t][p] <= '9')))
                return 0;
            if((av[t][p] == '+' || av[t][p] == '-') && !(av[t][p + 1] >= '0' && av[t][p + 1] <= '9'))
                return 0;
            p++;
        }
        t++;
    }
    return 1;
}
int main(int ac, char **av)
{
    s_list *stack_a;
    s_list *stack_b;

    stack_a = NULL;
    stack_b = NULL;

    if (!lmerda(ac, av))
        return 0;
    if(!initstack(ac, av, &stack_a))
        return 0;
    // while (stack_a)
    // {
    //     printf("%d\n", stack_a->value);
    //     stack_a = stack_a->next;
    // }
    // sa(&stack_a);
    reverse_rotate(&stack_a);
    // printf("%d\n", ft_lstlast(&stack_a)->value);
    while(stack_a)
    {
        printf("%d\n", stack_a->value);
        stack_a = stack_a->next;
    }
    // push(&stack_a, &stack_b);
    // while(stack_b)
    // {
    //     printf("   %d\n", stack_b->value);
    //     stack_b = stack_b->next;
    // }
    return 0;
}