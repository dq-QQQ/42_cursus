/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:48:58 by kyujlee           #+#    #+#             */
/*   Updated: 2021/09/22 18:08:49 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	return (ft_putchar(c));
}

int	print_str(va_list ap)
{
	int		idx;
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
		return (ft_putstr("(null)"));
	idx = 0;
	return (ft_putstr(s));
}	
