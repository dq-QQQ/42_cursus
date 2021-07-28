/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:05:07 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/14 13:34:55 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = (char *)s;
	while (*ret != (char)c)
	{
		if (!*ret)
			return ((void *)0);
		ret++;
	}
	return (ret);
}
