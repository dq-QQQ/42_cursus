/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:42:31 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/11 17:17:00 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*ret;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if ((ret = (char *)malloc(len_1 + len_2 + 1)) == 0)
		return (0);
	*(ret + len_1 + len_2) = 0;
	ft_memcpy(ret, s1, len_1);
	ft_memcpy(ret + len_1, s2, len_2);
	return (ret);
}
