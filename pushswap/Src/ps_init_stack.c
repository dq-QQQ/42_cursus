/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:26:28 by kyujlee           #+#    #+#             */
/*   Updated: 2022/01/28 16:43:49 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/pushswap.h"

static int	cnt_word(char const *s, char c)
{
	size_t	i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (*(s + i))
	{
		if (!ft_isdigit(*(s + i)))
			if (*(s + i) != c && *(s + i) != '-')
				return (-1);
		if (*(s + i) == c)
			i++;
		else
		{
			cnt++;
			while (*(s + i) != c && *(s + i))
				i++;
		}
	}
	return (cnt);
}

static void	free_malloc(char **ret, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word)
	{
		free(*(ret + i));
		i++;
	}
	free(ret);
}

static int	cut_str(char const *s, char c, char **ret, size_t word)
{
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	while (*(s + idx1))
	{
		if (*(s + idx1) == c)
			idx1++;
		else
		{
			idx2 = 0;
			while (*(s + idx1 + idx2) != c && *(s + idx1 + idx2))
				idx2++;
			*(ret + word) = (char *)malloc(idx2 + 1);
			ft_memcpy(*(ret + word), s + idx1, idx2);
			*(*(ret + word) + idx2) = 0;
			idx1 += idx2;
			word++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**ret;

	if (!s)
		return ((void *)0);
	cnt = cnt_word(s, c);
	if (cnt == -1)
		return ((void *)0);
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	*(ret + cnt) = 0;
	if (!cut_str(s, c, ret, 0))
		return (0);
	return (ret);
}

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
	free(parse_num);
	return (0);
}
