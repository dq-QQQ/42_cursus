/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:26:28 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/15 12:59:18 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Inc/pushswap.h"

char	*combine_argv(char **argv)
{
	char	*ret;
	char	*tmp;
	int		i;

	if (argv[2] == NULL)
		ret = ft_strdup(argv[1]);
	else
	{
		ret = (char *)malloc(1);
		ret[0] = '\0';
		i = 0;
		while (argv[++i])
		{
			tmp = ret;
			ret = ft_strjoin(ret, argv[i]);
			free(tmp);
		}
	}
	return (ret);
}

t_stack	*init_stack(char **argv)
{
	t_stack	*ret;
	char	**parse_num;
	char	*s;
	int		i;
	int		num;

	s = combine_argv(argv);
	parse_num = ft_split(s, ' ');
	if (parse_num == (void *)0)
		end_program(-1, NULL);
	ret = create_stack();
	i = -1;
	while (parse_num[++i])
	{
		num = ft_atoi(parse_num[i], ret);
		free(parse_num[i]);
		if (is_overlap(ret, num))
			end_program(-2, ret);
		insert_back(ret, num);
	}
	free(parse_num);
	free(s);
	return (ret);
}
