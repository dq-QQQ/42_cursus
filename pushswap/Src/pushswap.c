/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:56:40 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/07 15:48:52 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/pushswap.h"

// void	push_swap(t_stack *a, t_stack *b, t_mos ms)
// {
// 	int flag;

// 	while (cnt_element(a) > 3 && !is_sorted(a))
// 		//until_three(&a, &b, ms);
// 	while (!is_sorted(a))
// 	{
// 		if (a->data > a->next->data && a->data > a->next->next->data)
// 			flag = 6;
// 		else if (a->data > a->next->data && a->data < a->next->next->data)
// 			flag = 1;
// 		else
// 			flag = 9;
// 		//연산
// 		//연산한거 출력
// 	}
// 	while (b)
// 	{
// 		//플래그 정하고
// 		//연산
// 		//연산한거 출력
// 	}
// }
//
//

int				main(int argc, char **argv)
{
	t_mos ms;
	t_stack *stack;
	t_stack *ex;
	t_stack *instructions;

	ex = create_stack();
	instructions = create_stack();
	if (argc < 2)
		end_program(0, NULL);
	stack = init_stack(argv);
	if (is_sorted(stack))
		end_program(1, stack);
	if (stack->cnt == 2)
		write(1, "sa\n", 3);
	// push_swap(stack, 0, ms);
	operation_flags(stack, ex, instructions, 1);
	operation_flags(stack, ex, instructions, 2);
	operation_flags(stack, ex, instructions, 3);
	operation_flags(stack, ex, instructions, 4);
	operation_flags(stack, ex, instructions, 5);
	operation_flags(stack, ex, instructions, 6);
	operation_flags(stack, ex, instructions, 7);
	operation_flags(stack, ex, instructions, 8);
	operation_flags(stack, ex, instructions, 9);
	operation_flags(stack, ex, instructions, 10);
	operation_flags(stack, ex, instructions, 11);
	operation_flags(stack, ex, instructions, 12);
	display_instruction(instructions);
	delete_stack(stack);
	stack = NULL;
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked; rm leaks_result_temp");
	return (0);
}