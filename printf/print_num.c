/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:20:14 by kyujlee           #+#    #+#             */
/*   Updated: 2021/09/22 16:49:42 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int print_dec(va_list ap){
	int tmp;

	tmp = va_arg(ap, int);
	return (ft_putstr(ft_itoa(tmp)));
}

int print_u_dec(va_list ap){
	unsigned int tmp;

	tmp = va_arg(ap, unsigned int);
	return (ft_putstr(ft_itoa(tmp)));
}

int print_hex(va_list ap, char format){
	unsigned int tmp;
	int ret;

	ret = 0;
	tmp = va_arg(ap, unsigned int);
	return (ft_putstr(ft_i_to_h_to_a(tmp, format)));
}

int print_addr(va_list ap){
	int ret;
	unsigned long long tmp;

	tmp = (unsigned long long)va_arg(ap, void *);
	ret = ft_putstr("0x") + ft_putstr(ft_i_to_h_to_a(tmp, 'p'));
	return (ret);
}
