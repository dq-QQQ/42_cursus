/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:56:40 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/14 17:18:56 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/pushswap.h"


void	b_to_a(t_stack *a, t_stack *b, t_stack *inst, t_big_small bs)
{
	int i;

	i = 0;
	if (b->top->next == NULL)
	{
		operation_flags(a,b,inst,4);
		return ;
	}
	if (b->top->data < b->top->next->data)
		operation_flags(a,b,inst, 2);
	while (1)
	{
		init_big_small(&bs, b);
		if (bs.big == 0)
		{
			operation_flags(a, b, inst, 4);
			break ;
		}
		else
		{
			operation_flags(a, b, inst, 6);
			i++;
		}
	}
	while (i--)
		operation_flags(a, b, inst, 8);
}



void	push_swap(t_stack *a, t_stack *b, t_stack *inst, t_big_small bs)
{
	int flag;

	while (a->cnt > 3 && !is_sorted(a))
		until_three(a, b, inst, bs);
	while (!is_sorted(a))
	{
		if (a->top->data > a->top->next->data && a->top->data > a->top->next->next->data)
			flag = 5;
		else if (a->top->data > a->top->next->data && a->top->data < a->top->next->next->data)
			flag = 1;
		else
			flag = 7;
		operation_flags(a, b, inst, flag);
	}
	while (b->cnt)
	{
		b_to_a(a, b, inst, bs);
		if (!is_sorted(a))
			operation_flags(a,b,inst, 1);
	}
}


#include <stdio.h>

int				main(int argc, char **argv)
{
	t_big_small bs;
	t_stack *a;
	t_stack *b;
	t_stack *inst;

	bs.big = 0;
	bs.small = 0;
	if (argc < 2)
		end_program(0, NULL);
	a = init_stack(argv);
	if (is_sorted(a))
		end_program(1, a);
	if (a->cnt == 2)
	{
		write(1, "sa\n", 3);
		return (0);
	}
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