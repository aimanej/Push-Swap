#include "pswap.h"

int	ft_atoi(const char *nptr, int *t)
{
	char	*str;
	int		result;
	int		sign;

	str = (char *)nptr;
	sign = 1;
	result = 0;
	while ((str[*t] >= 9 && str[*t] <= 13) || str[*t] == 32)
		(*t)++;
	if (str[*t] == '-' || str[*t] == '+')
	{
		if (str[*t] == '-')
			sign *= -1;
		(*t)++;
	}
	while (str[*t] >= 48 && str[*t] <= 57)
	{
		result = result * 10 + (str[*t] - 48);
		(*t)++;
	}
	return (result * sign);
}

s_list *ft_lstnew(int val)
{
	s_list *new;

	new = malloc(sizeof(s_list));
	if (!new)
		return NULL;
	new->value = val;
	new->next = NULL;
	return new;
}

void ft_lstadback(s_list **lst, s_list *new)
{
	s_list *ind;

	if(!*lst)
		*lst = new;
	else
		{
			ind = ft_lstlast(*lst);
			ind->next = new;
		}
}

s_list *ft_lstlast(s_list *lst)
{
	s_list *t;

	if(!lst)
		return lst;
	while(lst->next)
		lst = lst->next;
	t = lst;
	return t;
}