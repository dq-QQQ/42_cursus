/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:26:28 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/03 12:29:22 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/pushswap.h"


int	init_stack(char *s, t_stack **stack)
{
	t_stack	*buff;
	int		num;
	int		i;
	char	**parse_num;

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
		if (is_overlap(*stack, num))
			return (-2);
		buff->data = num;
		if (parse_num[i + 1] == NULL)
			break ;
		buff->next = (t_stack *)malloc(sizeof(t_stack));
		buff = buff->next;
	}
	buff->next = *stack;
	free(parse_num);
	return (0);
}

t_stack	*create_stack(void)
{
	t_stack *ret;

	*ret = (t_stack *)malloc(sizeof(t_stack));
	ret->cnt = 0;
	ret->header = (t_stack_node *)malloc(sizeof(t_stack_node));
	ret->header->data = 0;
	ret->header->prev = NULL;
	ret->header->next = NULL;
	return (ret);
}

void	fill_stack(t_stack **stack, char **parse_num)
{
	t_stack_node	*buff;

	buff = (*stack)->header;
}

void	init_stack(char *s, t_stack **stack)
{
	char	**parse_num;

	parse_num = ft_split(s, ' ');
	if (parse_num == (void *)0)
		end_program(-1);
	*stack = create_stack();
	fill_stack(stack, parse_num);
}