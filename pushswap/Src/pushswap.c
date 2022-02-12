/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:56:40 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/12 16:25:43 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/pushswap.h"

int	order(t_stack *b, t_stack_node *curr)
{
	t_stack_node *tmp;
	int ret;

	tmp = b->top;
	ret = 1;
	while (tmp)
	{
		if (tmp->data == curr->data)
			break;
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}

void	move_node_to_a(t_stack *a, t_stack *b, t_stack *inst, t_stack_node *curr)
{
	t_stack_node *tmp;
	int idx;

	idx = order(b, curr);
	if (idx < (float)(b->cnt) / 2)
	{
		tmp = b->top;
		while (tmp->data != curr->data)
		{
			operation_flags(a,b, inst, 6);
			tmp = tmp->next;
		}
	}
	else
	{
		tmp = b->bottom;
		while (tmp->data != curr->data)
		{
			operation_flags(a,b, inst, 8);
			tmp = tmp->prev;
		}
	}
	operation_flags(a,b, inst, 4);
}

void sort_a(t_stack *a, t_stack *b, t_stack *inst)
{
	int sort_data;
	int cnt;

	if (is_sorted(a))
		return ;
	cnt = 0;
	sort_data = a->top->data;
	operation_flags(a,b, inst, 3);
	while (a->top->data <= sort_data)
	{
		operation_flags(a,b, inst, 5);
		cnt++;
	}
	operation_flags(a,b, inst, 4);
	while (cnt)
	{
		operation_flags(a,b, inst, 7);
		cnt--;
	}
}

t_stack *copy_stack(t_stack *stack)
{
	t_stack *ret;
	t_stack_node *tmp;
	t_stack_node *last;

	if (stack->cnt == 0)
		return (NULL);
	ret = create_stack();
	ret->cnt = stack->cnt;
	tmp = stack->top;
	insert_back(ret, stack->top->data);
	while (stack)
	{
		
	}
}

int cnt_inst(t_stack *a, t_stack *b, t_stack_node *curr)
{
	t_stack *tmp_inst;
	t_stack *tmp_a;
	t_stack *tmp_b;
	t_stack_node *tmp_curr;

	int ret;

	tmp_inst = create_stack();
	move_node_to_a(tmp_a, tmp_b, tmp_inst, tmp_curr);
	sort_a(tmp_a, tmp_b, tmp_inst);
	ret = tmp_inst->cnt;
	free(tmp_inst);
	return (ret);
}


void	b_to_a(t_stack *a, t_stack *b, t_stack *inst)
{
	t_stack_node *tmp;
	t_stack_node *min_node;
	int i;
	int min;
	int cnt;

	min = 2147483647;
	i = 1;
	tmp = b->top;
	while (tmp)
	{
		cnt = cnt_inst(a, b, tmp);
		if (min > cnt)
		{
			min = cnt;
			min_node = tmp;
		}
		tmp = tmp->next;
		i++;
	}
	move_node_to_a(a, b, inst, min_node);
	sort_a(a, b, inst);
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
	while (b)
		b_to_a(a, b, inst);
}



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
		write(1, "sa\n", 3);
	b = create_stack();
	inst = create_stack();
	push_swap(a, b, inst, bs);
	check_inst(inst);
	display_instruction(inst);
	delete_stack(a);
	delete_stack(b);
	delete_stack(inst);
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked; rm leaks_result_temp");
	return (0);
}