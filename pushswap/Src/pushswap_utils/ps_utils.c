/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:26:49 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/07 09:53:08 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Inc/pushswap.h"

int is_sorted(t_stack *stack)
{
	int curr_data;
	t_stack *tmp_stack;

	if (!stack->next)
		return (1);
	curr_data = stack->data;
	tmp_stack = stack->next;
	while (tmp_stack)
	{
		if (tmp_stack->data > curr_data)
			curr_data = tmp_stack->data;
		else
			return (0);
		tmp_stack = tmp_stack->next;
	}
	return (1);
}

int	is_overlap(t_stack *stack, int data)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data == data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void end_program(int flag)
{
	if (flag == -1)
		write(1, "non numeric value", 18);
	else if (flag == -2)
		write(1, "overlap numeric value", 22);
	else if (flag == 0)
		write(1, "different number of argument", 29);
	else if (flag == 1)
		write(1, "Already sorted", 15);
	else if (flag == -3)
		write (1, "Input number is over than MAXINT", 33);
	exit(0);
}

void deletestack(t_stack *stack)
{
	if (stack->next){
		deletestack(stack->next);
	}
	free(stack);
	stack = NULL;
}

int			cnt_element(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}