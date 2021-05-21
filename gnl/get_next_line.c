/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:17:13 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/21 17:04:05 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_restdata(char *str)
{
	char	*ret;
	size_t	total_len;
	size_t	real_len;
	size_t	i;

	if (!str)
		return (0);
	real_len = 0;
	while (str[real_len] && str[real_len] != '\n')
		real_len++;
	if (!*(str + real_len))
	{
		free(str);
		return (0);
	}
	total_len = ft_strlen(str);
	if ((ret = (char *)malloc(total_len - real_len + 1)) == 0)
		return (0);
	i = 0;
	real_len++;
	while (real_len < total_len)
		*(ret + i++) = *(str + real_len++);
	ret[i] = '\0';
	free(str);
	return (ret);
}

char	*get_line_until_newline(char *str)
{
	char	*ret;
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	ret = my_strndup(str, len);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*data[OPEN_MAX];
	char		*buff;
	int			read_byte;

	read_byte = 1;
	if (fd >= OPEN_MAX || fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((buff = (char *)malloc(BUFFER_SIZE + 1)) == 0)
		return (-1);
	while (!my_strnewline(data[fd]) && read_byte)
	{
		if ((read_byte = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[read_byte] = '\0';
		data[fd] = my_strjoin(data[fd], buff);
	}
	free(buff);
	*line = get_line_until_newline(data[fd]);
	data[fd] = get_restdata(data[fd]);
	if (read_byte == 0)
		return (0);
	return (1);
}
