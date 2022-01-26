/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:56:40 by kyujlee           #+#    #+#             */
/*   Updated: 2022/01/26 13:27:34 by kyujlee          ###   ########.fr       */
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
		if (overlap_check(*stack, num))
			return (-2);
		buff->data = num;
		if (*(parse_num) == NULL)
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

void deletestack(t_stack *stack, int i)
{
	if (stack->next){
		deletestack(stack->next, ++i);
		free(stack);
		stack = NULL;
	}
	if (i == 0){
		free(stack);
		stack = NULL;
	}
	
}



int				main(int argc, char **argv)
{
	t_mos ms;
	t_stack *stack;
	int flag;

	if (argc != 2)
		error(0);
	flag = init_stack(argv[1], &stack);
	if (flag)
		error(flag);
	deletestack(stack, 0);
	//free(stack);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked");
	return (0);
}