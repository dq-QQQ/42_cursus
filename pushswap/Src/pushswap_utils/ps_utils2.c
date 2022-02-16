/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:59:26 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/16 12:42:21 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	init_con(int *first_con, int *second_con, t_big_small bs, t_stack *a)
{
	int	criteria;

	if (bs.big >= 10)
	{
		if (a->cnt > 100)
			criteria = 20;
		else
			criteria = 10;
		*first_con = bs.big / criteria;
		*second_con = bs.small - 2;
	}
	else
	{
		*first_con = bs.big - bs.small;
		*second_con = (a->cnt - 1) / 2;
	}
}

int	pa_or_rb(t_stack *a, t_stack *b, t_stack *inst, t_big_small bs)
{
	if (bs.big == 0)
	{
		operation_flags(a, b, inst, 4);
		return (4);
	}
	else
	{
		operation_flags(a, b, inst, 6);
		return (6);
	}
}
