/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:26:49 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/07 12:28:01 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Inc/pushswap.h"

int is_sorted(t_stack *stack)
{
	int curr_data;
	t_stack_node *tmp_node;

	if (!stack->top->next)
		return (1);
	curr_data = stack->top->data;
	tmp_node = stack->top->next;
	while (tmp_node)
	{
		if (tmp_node->data > curr_data)
			curr_data = tmp_node->data;
		else
			return (0);
		tmp_node = tmp_node->next;
	}
	return (1);
}

int	is_overlap(t_stack *stack, int data)
{
	t_stack_node *tmp;

	tmp = stack->top;
	while (tmp && tmp->next)
	{
		if (tmp->data == data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void end_program(int flag, t_stack *stack)
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
	if (stack)
		delete_stack(stack);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked; rm leaks_result_temp");
	exit(0);
}