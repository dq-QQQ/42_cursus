/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:14:02 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/06 20:20:54 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_tmp;
	const char	*src_tmp;

	if (!dst && !src)
		return ((void *)0);
	dst_tmp = dst;
	src_tmp = src;
	if (dst <= src)
		while (len--)
			*dst_tmp++ = *src_tmp++;
	else
	{
		dst_tmp += len;
		src_tmp += len;
		while (len--)
			*--dst_tmp = *--src_tmp;
	}
	return (dst);
}
