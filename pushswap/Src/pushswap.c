/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:56:40 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/07 10:14:37 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/pushswap.h"

void	push_swap(t_stack *a, t_stack *b, t_mos ms)
{
	int flag;

	while (cnt_element(a) > 3 && !is_sorted(a))
		//until_three(&a, &b, ms);
	while (!is_sorted(a))
	{
		if (a->data > a->next->data && a->data > a->next->next->data)
			flag = 6;
		else if (a->data > a->next->data && a->data < a->next->next->data)
			flag = 1;
		else
			flag = 9;
		//연산
		//연산한거 출력
	}
	while (b)
	{
		//플래그 정하고
		//연산
		//연산한거 출력
	}
}


void		print_oper(int i, int j)
{
	if (i == 1)
		write(1, "sa", 2);
	else if (i == 2)
		write(1, "sb", 2);
	else if (i == 3)
		write(1, "ss", 2);
	else if (i == 4)
		write(1, "pa", 2);
	else if (i == 5)
		write(1, "pb", 2);
	else if (i == 6)
		write(1, "ra", 2);
	else if (i == 7)
		write(1, "rb", 2);
	else if (i == 8)
		write(1, "rr", 2);
	else if (i == 9)
		write(1, "rra", 3);
	else if (i == 10)
		write(1, "rrb", 3);
	else if (i == 11)
		write(1, "rrr", 3);
	if (j)
		write(1, "\n", 1);
}

int				main(int argc, char **argv)
{
	t_mos ms;
	t_stack *stack;

	if (argc != 2)
		end_program(0);
	init_stack(argv[1], &stack);
	if (is_sorted(stack))
		end_program(1);
	if (cnt_element(stack) == 2)
		write(1, "sa\n", 3);
	// push_swap(stack, 0, ms);
	deletestack(stack);
	stack = NULL;
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked; rm leaks_result_temp");
	return (0);
}