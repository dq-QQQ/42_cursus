/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:51:19 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/11 17:58:48 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ret;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		start++;
	end = ft_strlen(s1);
	while (*(s1 + end - 1) && (end - 1) && ft_strchr(set, *(s1 + end - 1)))
		end--;
	if (start > end)
		return (ft_strdup(""));
	if ((ret = (char *)malloc(end - start + 1)) == 0)
		return (0);
	ft_strlcpy(ret, s1 + start, end - start + 1);
	return (ret);
}
