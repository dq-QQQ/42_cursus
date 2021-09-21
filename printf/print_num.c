/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:20:14 by kyujlee           #+#    #+#             */
/*   Updated: 2021/09/21 16:42:45 by kyujlee          ###   ########.fr       */
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
	unsigned long long tmp;

	printf ("%p\n", va_arg(ap, unsigned long long));
	tmp = (unsigned long long)va_arg(ap, unsigned long long);
	printf ("%llu\n", tmp);
	printf("0x%s",ft_i_to_h_to_a(tmp, 'x'));
}
