#include "../../Inc/pushswap.h"

void	init_big_small(t_big_small *bs, t_stack *stack)
{
	int				criteria;
	t_stack_node	*tmp;

	bs->small = 0;
	bs->big = 0;
	tmp = stack->top->next;
	criteria = stack->top->data;
	while (tmp)
	{
		if (tmp->data > criteria)
			bs->big += 1;
		else
			bs->small += 1;
		tmp = tmp->next;
	}
}

void	sort_b(t_stack *a, t_stack *b, t_stack *inst, t_big_small bs)
{
	init_big_small(&bs, b);
	if (b->cnt == 0)
		return ;
	if (bs.big != 0)
	{
		if (bs.big > bs.small)
			operation_flags(a, b, inst, 6);
		else
			operation_flags(a, b, inst, 2);
	}
}

void	until_three(t_stack *a, t_stack *b, t_stack *inst, t_big_small bs)
{
	int	first_con;
	int	second_con;

	init_big_small(&bs, a);
	if (bs.big >= 20)
	{
		first_con = bs.big / 20;
		second_con = bs.small - 2;
	}
	else
	{
		first_con = bs.big - bs.small;
		second_con = (a->cnt - 1) / 2;
	}
	if (first_con >= second_con)
	{
		operation_flags(a, b, inst, 3);
		sort_b(a, b, inst, bs);
	}
	else
		operation_flags(a, b, inst, 5);
}
