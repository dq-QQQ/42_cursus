/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:58:36 by kyujlee           #+#    #+#             */
/*   Updated: 2022/02/15 12:58:39 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Inc/pushswap.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	ret = (char *)malloc(len + 1);
	*(ret + len) = 0;
	while (i < len)
	{
		*(ret + i) = *(s1 + i);
		i++;
	}
	return (ret);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}
