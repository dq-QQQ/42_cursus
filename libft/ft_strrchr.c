/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:34:43 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/14 13:36:21 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = (char *)s;
	while (*ret)
		ret++;
	while (*ret != (char)c)
	{
		if (ret == s)
			return ((void *)0);
		ret--;
	}
	return (ret);
}
