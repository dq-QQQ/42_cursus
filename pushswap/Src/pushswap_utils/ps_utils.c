/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:26:49 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/14 18:45:55 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Inc/pushswap.h"

int	is_sorted(t_stack *stack)
{
	int				curr_data;
	t_stack_node	*tmp_node;

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
	t_stack_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->data == data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	end_program(int flag, t_stack *stack)
{
	if (flag == -1)
		ft_putstr("Error\n");
	else if (flag == -2)
		ft_putstr("Error\n");
	else if (flag == 0)
		ft_putstr("Error\n");
	else if (flag == 1)
		;
	else if (flag == -3)
		ft_putstr("Error\n");
	else if (flag == 2)
		write(1, "sa\n", 3);
	if (stack)
		delete_stack(stack);
	exit(0);
}

void	display(int flag)
{
	if (flag == 1)
		ft_putstr("sa\n");
	else if (flag == 2)
		ft_putstr("sb\n");
	else if (flag == 3)
		ft_putstr("pb\n");
	else if (flag == 4)
		ft_putstr("pa\n");
	else if (flag == 5)
		ft_putstr("ra\n");
	else if (flag == 6)
		ft_putstr("rb\n");
	else if (flag == 7)
		ft_putstr("rra\n");
	else if (flag == 8)
		ft_putstr("rrb\n");
	else if (flag == 9)
		ft_putstr("ss\n");
	else if (flag == 10)
		ft_putstr("rr\n");
	else if (flag == 11)
		ft_putstr("rrr\n");
}

void	display_instruction(t_stack *stack)
{
	t_stack_node	*tmp;
	int				i;

	i = stack->cnt;
	tmp = stack->top;
	while (i-- > 0)
	{
		if (tmp->data)
			display(tmp->data);
		tmp = tmp->next;
	}
}
