/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:56:40 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/07 16:48:31 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/pushswap.h"

void		init_less(t_mos *ms, t_stack *st, int i)
{
	ms->less = 0;
	ms->more = 0;
	ms->cn = count_val_st(st);
	while (st)
	{
		if (st->nb > i)
			ms->more += 1;
		else
			ms->less += 1;
		st = st->next;
	}
}

void	until_three(t_stack **a, t_stack **b, t_stack *instructions, t_mos ms)
{
	int			res;
	t_stack		*s;

	s = *b;
	res = 0;
	src_more_less(&ms, *a, a[0]->nb);
	if (ms.less - 2 < (ms.more / 4))
		res = 5; // ra
	else if (src_updw_sp(*a, 0, ms, 5))
		res = 9; //  rra
	else
	{
		if (s)
			res = s->nb;
		while (s && s->next) 
			s = s->next;
		if (s && res < s->nb)
			res = 8; // rr
		else
			res = 6; //ra
	}
	operation_flags(a, b, instructions, flag);
}


void	push_swap(t_stack *a, t_stack *b, t_stack *instructions, t_mos ms)
{
	int flag;

	while (cnt_element(a) > 3 && !is_sorted(a))
		until_three(&a, &b, ms);
	while (!is_sorted(a))
	{
		if (a->data > a->next->data && a->data > a->next->next->data)
			flag = 5;
		else if (a->data > a->next->data && a->data < a->next->next->data)
			flag = 1;
		else
			flag = 7;
		operation_flags(a, b, instructions, flag);
	}
	while (b)
	{
		//플래그 정하고
		//연산
		//연산한거 출력
	}
}



int				main(int argc, char **argv)
{
	t_mos ms;
	t_stack *a;
	t_stack *b;
	t_stack *instructions;

	if (argc < 2)
		end_program(0, NULL);
	a = init_stack(argv);
	if (is_sorted(a))
		end_program(1, a);
	if (stack->cnt == 2)
		write(1, "sa\n", 3);
	b = create_stack();
	instructions = create_stack();
	push_swap(a, b, instructions, ms);
	display_instruction(instructions);
	delete_stack(a);
	delete_stack(b);
	delete_stack(instructions);
	a = NULL;
	b = NULL;
	instructions = NULL;
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked; rm leaks_result_temp");
	return (0);
}