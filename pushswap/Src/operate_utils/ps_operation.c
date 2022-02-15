/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:58:48 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/15 12:58:49 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Inc/pushswap.h"

void	switch_data(t_stack *stack)
{
	t_stack_node	*third;
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack->top && stack->top->next)
	{
		first = stack->top;
		second = stack->top->next;
		third = second->next;
		second->prev = NULL;
		first->next = third;
		if (third)
			third->prev = first;
		second->next = first;
		first->prev = second;
		stack->top = second;
	}
}

void	rotate_data(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*last;

	if (stack->top && stack->bottom)
	{
		first = stack->top;
		second = stack->top->next;
		last = stack->bottom;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		second->prev = NULL;
		stack->top = second;
		stack->bottom = first;
	}
}

void	reverse_rotate_data(t_stack *stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*last;

	if (stack->top && stack->bottom)
	{
		first = stack->top;
		second = stack->bottom->prev;
		last = stack->bottom;
		first->prev = last;
		last->next = first;
		last->prev = NULL;
		second->next = NULL;
		stack->top = last;
		stack->bottom = second;
	}
}

void	move_data(t_stack *from, t_stack *to)
{
	int	tmp;

	if (from->top)
	{
		tmp = from->top->data;
		delete_front(from);
		insert_front(to, tmp);
	}
}

void	operation_flags(t_stack *a, t_stack *b, t_stack *inst, int flag)
{
	if (flag == 1)
		switch_data(a);
	else if (flag == 2)
		switch_data(b);
	else if (flag == 3)
		move_data(a, b);
	else if (flag == 4)
		move_data(b, a);
	else if (flag == 5)
		rotate_data(a);
	else if (flag == 6)
		rotate_data(b);
	else if (flag == 7)
		reverse_rotate_data(a);
	else if (flag == 8)
		reverse_rotate_data(b);
	insert_back(inst, flag);
}
