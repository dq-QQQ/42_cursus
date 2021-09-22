/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:46:19 by kyujlee           #+#    #+#             */
/*   Updated: 2021/09/22 18:18:52 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	ret;

	ret = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		write(1, s, 1);
		s++;
		ret++;
	}
	return (ret);
}

static int	cnt_digits(long long n)
{
	if (n < 0)
		n *= -1;
	if (n == 0)
		return (0);
	while (n != 0)
		return (1 + cnt_digits(n / 10));
	return (0);
}

static void	get_digit(int *sign, long long *i, int *digit)
{
	if (*i == 0)
		*digit = 1;
	else if (*i < 0)
	{
		*sign = -1;
		*i *= -1;
		*digit = cnt_digits(*i) + 1;
	}
	else
		*digit = cnt_digits(*i);
}

char	*ft_itoa(long long n)
{
	char		*ret;
	int			digit;
	int			sign;
	long long	i;

	i = n;
	sign = 1;
	get_digit(&sign, &i, &digit);
	ret = (char *)malloc(digit + 1);
	*(ret + digit) = 0;
	digit--;
	while (digit >= 0)
	{
		*(ret + digit) = '0' + i % 10;
		i /= 10;
		digit--;
	}
	if (sign == -1)
		*(ret + digit + 1) = '-';
	return (ret);
}
