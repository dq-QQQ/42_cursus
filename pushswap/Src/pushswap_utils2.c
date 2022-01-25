#include "../Inc/pushswap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return ((void *)0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *stack)
{

	if (!*lst)
	{
		*lst = stack;
		return ;
	}
	(ft_lstlast(*lst))->next = stack;
}
