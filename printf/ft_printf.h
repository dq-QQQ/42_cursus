/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:24:59 by kyujlee           #+#    #+#             */
/*   Updated: 2021/09/26 15:25:03 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/* printf main logic function*/
int		ft_printf(const char *str, ...);

/* print charater */
int		print_char(va_list ap);
int		print_str(va_list ap);
int		print_dec(va_list ap);
int		print_u_dec(va_list ap);
int		print_hex(va_list ap, char format);
int		print_addr(va_list ap);

/* the other function using from printf */
int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_itoa(long long n);
char	*ft_i_to_h_to_a(unsigned long long n, char format);
#endif
