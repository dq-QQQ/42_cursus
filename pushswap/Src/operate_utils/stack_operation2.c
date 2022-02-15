/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:58:57 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/15 12:58:58 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Inc/pushswap.h"

t_stack	*create_stack(void)
{
	t_stack	*ret;

	ret = (t_stack *)malloc(sizeof(t_stack));
	ret->cnt = 0;
	ret->top = NULL;
	ret->bottom = NULL;
	return (ret);
}

void	clear_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	while (stack->cnt > 0)
		delete_front(stack);
}

void	delete_stack(t_stack *stack)
{
	clear_stack(stack);
	free(stack);
	stack = NULL;
}
