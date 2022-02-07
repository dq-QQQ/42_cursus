/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:26:28 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/07 12:31:26 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/pushswap.h"


char *combine_argv(char **argv)
{
	char *ret;
	int i;
	
	ret = NULL;
	i = 0;
	while (argv[++i])
	{
		ret = ft_strjoin(ret, argv[i]);

	}
	return ret;
}

t_stack* init_stack(char **argv)
{
	t_stack* ret;
	char	**parse_num;
	char	*s;
	int		i;
	int		num;

	if (argv[2] != NULL)
		s = combine_argv(argv);
	else
		s = argv[1];
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
	return (ret);
}
