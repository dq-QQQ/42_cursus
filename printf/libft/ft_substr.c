/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:02:15 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/12 00:20:11 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
		tmp = (char *)malloc(len - start + 1);
	}
	else
		tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (0);
	*(tmp + len) = 0;
	i = 0;
	while (i < len && *(s + start + i))
	{
		*(tmp + i) = *(s + start + i);
		i++;
	}
	return (tmp);
}
