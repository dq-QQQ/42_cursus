/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:21:20 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/14 16:38:08 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*ret;

	if (!*haystack && !*needle)
		return ((char *)"");
	if (!haystack || !*haystack)
		return ((void *)0);
	ret = (char *)haystack;
	i = ft_strlen(needle);
	if (!needle)
		return (ret);
	while (i <= len)
	{
		if (!ft_memcmp((const char *)ret, needle, i))
			return (ret);
		ret++;
		len--;
	}
	return ((void *)0);
}
