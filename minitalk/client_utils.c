/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:26:20 by kyujlee           #+#    #+#             */
/*   Updated: 2021/12/14 19:11:56 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	ft_error(void)
{
	ft_putstr("------ERROR------");
	exit(1);
}

static void	skip(const char *str, int *i, int *sign)
{
	while ((9 <= str[*i] && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	skip(str, &i, &sign);
	while ('0' <= str[i] && str[i] <= '9' && str[i])
	{
		ret = ret * 10 + str[i++] - '0';
		if (ret > 2147483647)
		{
			if (ret == 2147483648)
				return (-2147483648);
			else
			{
				if (sign == -1)
					return (0);
				else
					return (-1);
			}
		}
	}
	return (sign * (int)ret);
}
