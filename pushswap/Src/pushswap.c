/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:56:40 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/16 12:41:29 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/pushswap.h"

void	b_to_a(t_stack *a, t_stack *b, t_stack *inst, t_big_small bs)
{
	int	i;
	int	pa_cnt;

	pa_cnt = 0;
	i = 0;
	while (1)
	{
		if (b->top->next && b->top->data < b->top->next->data)
			operation_flags(a, b, inst, 2);
		init_big_small(&bs, b);
		if (bs.big == 1 && pa_cnt++ == 0)
		{
			operation_flags(a, b, inst, 4);
			continue ;
		}
		if (pa_or_rb(a, b, inst, bs) == 4)
			break ;
		i++;
	}
	while (i--)
		operation_flags(a, b, inst, 8);
}

void	until_three(t_stack *a, t_stack *b, t_stack *inst, t_big_small bs)
{
	int	first_con;
	int	second_con;

	init_big_small(&bs, a);
	init_con(&first_con, &second_con, bs, a);
	if (first_con >= second_con)
	{
		operation_flags(a, b, inst, 3);
		sort_b(a, b, inst, bs);
	}
	else
		operation_flags(a, b, inst, 5);
}

void	push_swap(t_stack *a, t_stack *b, t_stack *inst, t_big_small bs)
{
	int	flag;
	int	second;
	int	third;

	while (a->cnt > 3 && !is_sorted(a))
		until_three(a, b, inst, bs);
	while (!is_sorted(a))
	{
		second = a->top->next->data;
		third = a->top->next->next->data;
		if (a->top->data > second && a->top->data > third)
			flag = 5;
		else if (a->top->data > second && a->top->data < third)
			flag = 1;
		else
			flag = 7;
		operation_flags(a, b, inst, flag);
	}
	while (b->cnt)
	{
		b_to_a(a, b, inst, bs);
		if (!is_sorted(a))
			operation_flags(a, b, inst, 1);
	}
}

int	main(int argc, char **argv)
{
	t_big_small	bs;
	t_stack		*a;
	t_stack		*b;
	t_stack		*inst;

	bs.big = 0;
	bs.small = 0;
	if (argc < 2)
		end_program(0, NULL);
	a = init_stack(argv);
	if (a->cnt == 0)
		end_program(1, a);
	if (is_sorted(a))
		end_program(1, a);
	if (a->cnt == 2)
		end_program(2, a);
	b = create_stack();
	inst = create_stack();
	push_swap(a, b, inst, bs);
	check_inst(inst);
	display_instruction(inst);
	delete_stack(a);
	delete_stack(b);
	delete_stack(inst);
	return (0);
}
