/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:41:46 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/11 16:52:53 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(s1);
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
