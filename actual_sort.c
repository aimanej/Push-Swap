#include <unistd.h>
#include "pswap.h"

int bitlen(int p)
{
    int length = 0;
    int t = abs(p);

    if (p == 0)
        return 0;
    while(t > 0)
    {
        t /= 2;
        length++;
    }
    return length;
}

void sort(int **arr, int size)
{
    int t = 0;
    int i = t  + 1;
    int temp;
    // printf("heeeeeeeeeeere  sort\n");
    // while(t < size)
    // {
    //     printf("%d ---->>\n", (*arr)[t]);
    //     t++;

    // }
    while(t + 1 < size)
    {
        int i = t  + 1;
        while(i < size)
        {
            printf("heeeeeeeeeeere sort 2\n");
            if((*arr)[i] < (*arr)[t])
                {
                    temp = (*arr)[t];
                    (*arr)[t] = (*arr)[i];
                    (*arr)[i] = temp;
                }
            else
                i++;
        }
        t++;
    }
    t = 0;
    printf("heeeeeeeeeeere  sort\n");
    while(t < size)
    {
        printf("%d ---->>\n", (*arr)[t]);
        t++;

    }
}
int lstsize(s_list *lst)
{
    int t = 0;

    if(!lst)
        return 0;
    while (lst)
    {
        lst = lst->next;
        t++;
    }
    return t;
}

void index_sorted_stack(s_list **stack_a)
{
    int t = lstsize(*stack_a);
    s_list *a;
    int i = 0;
    int *arr;

    arr = malloc(sizeof(int) * t);
    if(!arr)
        return ;
    a = *stack_a;
    while(a)
    {
        arr[i] = a->value;
        a = a->next;
        i++;
    }
    a = *stack_a;
    i = 0;
    sort(&arr, t);
    int *b = arr;
    while(a)
    {
        i = 0;
        while(i < t)
        {
            if(a->value != arr[i])
                i++;
            else
            {
                a->index = i;
                break;
            }
        }
        a = a->next;
    }
    a = *stack_a;
}
void push_swap(s_list **stack_a, s_list **stack_b)
{
    int bit_count = 0;
    s_list *a = *stack_a;
    int t = 0;
    int p = 0;

    while(a)
    {
        if(bit_count < bitlen(a->index))
        {
            printf("     ->> bit count is %d \n", bitlen((a->index)));
            bit_count = bitlen((a->index));
        }
        a = a->next;
    }
    printf("     ->> bit count is %d \n", bit_count);
    while(t <= bit_count)
    {
        p = lstsize(*stack_a);
        while(p)
        {
            if((((*stack_a)->index >> t) & 1) == 0)
                {
                    push(stack_a, stack_b);
                    write(1, "pb\n", 3);
                }
            else
                {
                    rotate(stack_a);
                    write(1, "ra\n" , 3);
                }
            p--;
        }
        while(*stack_b != NULL)
        {
            push(stack_b, stack_a);
            write(1,"pa\n",3);
        }
        t++;
        // while()
        // {}
    }
}