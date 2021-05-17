/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:17:24 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/17 19:40:24 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return ((void *)0);
	while (n-- > 0)
		*((unsigned char *)dst + n) = *((unsigned char *)src + n);
	return (dst);
}


char	*my_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*ret;

	if (!s1 && !s2)
		return (0);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if ((ret = (char *)malloc(len_1 + len_2 + 1)) == 0)
		return (0);
	*(ret + len_1 + len_2) = 0;
	ft_memcpy(ret, s1, len_1);
	ft_memcpy(ret + len_1, s2, len_2);
	return (ret);
}
char	*my_strndup(const char *s1, int idx)
{
	char	*ret;
	int		len;
	int		i;

	len = idx;
	i = 0;
	if ((ret = (char *)malloc(len + 1)) == 0)
		return (0);
	*(ret + len) = 0;
	while (i < len)
	{
		*(ret + i) = *(s1 + i);
		i++;
	}
	return (ret);
}

int	my_strnewline(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
