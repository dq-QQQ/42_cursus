/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:26:41 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/12 00:22:37 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_digits(int n)
{
	if (n == -2147483648)
		return (10);
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

char		*ft_itoa(int n)
{
	char		*ret;
	int			digit;
	int			sign;
	long long	i;

	i = n;
	sign = 1;
	get_digit(&sign, &i, &digit);
	if ((ret = (char *)malloc(digit + 1)) == 0)
		return (0);
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
