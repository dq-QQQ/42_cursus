/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:20:14 by kyujlee           #+#    #+#             */
/*   Updated: 2021/09/22 18:11:13 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_dec(va_list ap)
{
	int		ret;
	int		tmp;
	char	*str;

	tmp = va_arg(ap, int);
	str = ft_itoa(tmp);
	ret = ft_putstr(str);
	free(str);
	return (ret);
}

int	print_u_dec(va_list ap)
{
	int				ret;
	unsigned int	tmp;
	char			*str;

	tmp = va_arg(ap, unsigned int);
	str = ft_itoa(tmp);
	ret = ft_putstr(str);
	free(str);
	return (ret);
}

int	print_hex(va_list ap, char format)
{
	unsigned int	tmp;
	int				ret;
	char			*str;

	tmp = va_arg(ap, unsigned int);
	str = ft_i_to_h_to_a(tmp, format);
	ret = ft_putstr(str);
	free(str);
	return (ret);
}

int	print_addr(va_list ap)
{
	int					ret;
	unsigned long long	tmp;
	char				*str;

	tmp = (unsigned long long)va_arg(ap, void *);
	str = ft_i_to_h_to_a(tmp, 'p');
	ret = ft_putstr("0x") + ft_putstr(str);
	free(str);
	return (ret);
}
