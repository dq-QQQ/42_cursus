/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:56:40 by kyujlee           #+#    #+#             */
/*   Updated: 2022/01/28 14:34:26 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/pushswap.h"
int	overlap_check(t_stack *stack, int data)
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
#include <stdio.h>

int	init_stack(char *s, t_stack **stack)
{
	t_stack *buff;
	int num;
	int i;
	char **parse_num;

	parse_num = ft_split(s, ' ');
	if (parse_num == (void *)0)
		return (-1);
	*stack = (t_stack *)malloc(sizeof(t_stack));
	buff = *stack;
	i = -1;
	while (parse_num[++i])
	{
		num = ft_atoi(parse_num[i]);
		free(parse_num[i]);
		if (overlap_check(*stack, num))
			return (-2);
		buff->data = num;
		if (parse_num[i + 1] == NULL)
			break;
		buff->next = (t_stack *)malloc(sizeof(t_stack));
		buff = buff->next;
	}

	free(parse_num);
	return (0);
}


void error(int flag){
	if (flag == -1)
		write(1, "non numeric value", 18);
	else if (flag == -2)
		write(1, "overlap numeric value", 22);
	else if (flag == 0)
		write(1, "different number of argument", 29);
	exit(0);
}

static void		free_stack(t_stack *stack)
{
	t_stack		*track_next;
	t_stack		*delete;

	if (stack)
	{
		track_next = stack->next;
		while (track_next)
		{
			delete = track_next;
			track_next = track_next->next;
			free(delete);
		}
		free(track_next);
	}
}


int				main(int argc, char **argv)
{
	t_mos ms;
	t_stack *stack;
	int flag;

	// if (argc != 2)
	// 	error(0);
	flag = init_stack(argv[1], &stack);
	if (flag)
		error(flag);
	// free_stack(stack);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked");
	return (0);
}