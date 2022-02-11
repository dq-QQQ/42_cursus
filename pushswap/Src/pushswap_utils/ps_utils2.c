#include "../../Inc/pushswap.h"

void		init_big_small(t_big_small *bs, t_stack *stack)
{
	bs->small = 0;
	bs->big = 0;
	t_stack_node *tmp;
	int criteria;

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

void until_three(t_stack *a, t_stack *b, t_stack *inst, t_big_small bs)
{
	init_big_small(&bs, a);
	if (bs.big > bs.small)
		operation_flags(a, b, inst, 3);//pb
	else
		operation_flags(a, b, inst, 5);//ra
}
