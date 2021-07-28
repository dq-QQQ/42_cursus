/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:25:31 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/11 12:14:50 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return ((void *)0);
	while (n-- > 0)
		*((unsigned char *)dst + n) = *((unsigned char *)src + n);
	return (dst);
}
