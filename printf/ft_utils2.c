/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:43:46 by kyujlee           #+#    #+#             */
/*   Updated: 2021/09/21 16:32:37 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int		get_hexdigit(unsigned long long	n){
	int	ret;

	ret = 1;
	while (n > 16)
	{
		n /= 16;
		ret++;
	}
	return (ret);
}


char	*ft_i_to_h_to_a(unsigned long long n, char format){
	char *ret;
	int cnt;

	cnt = get_hexdigit(n);
	ret = (char *)malloc(cnt + 1);
	ret[cnt] = '\0';
	while (--cnt >= 0)
	{
		if ((n % 16) < 10)
			ret[cnt] = n % 16 + 48;
		else
		{
			if (format == 'x' || format == 'p')
				ret[cnt] = n % 16 + 87;
			if (format == 'X')
				ret[cnt] = n % 16 + 55;
		}
		n /= 16;
	}
	return (ret);
}
