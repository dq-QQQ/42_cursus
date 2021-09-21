/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:21:57 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/11 18:12:04 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;
	size_t	len;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if ((ret = (char *)malloc(len + 1)) == 0)
		return (0);
	*(ret + len) = 0;
	i = 0;
	while (i < len)
	{
		*(ret + i) = f(i, *(s + i));
		i++;
	}
	return (ret);
}
