/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:17:13 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/23 20:04:52 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_index(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) && *(str + i) != '\n')
		i++;
	return (i);
}

char	*get_restdata(char *str, int *flag)
{
	char	*ret;
	size_t	real_len;
	size_t	i;

	if (!str)
		return (0);
	real_len = get_index(str);
	if (!*(str + real_len))
	{
		free(str);
		return (0);
	}
	if ((ret = (char *)malloc(ft_strlen(str) - real_len + 1)) == 0)
	{
		*flag = -1;
		free(str);
		return (0);
	}
	i = 0;
	real_len++;
	while (*(str + real_len))
		*(ret + i++) = *(str + real_len++);
	*(ret + i) = '\0';
	free(str);
	return (ret);
}

char	*get_line_until_newline(char *str, int *flag)
{
	char	*ret;
	size_t	len;

	if (!str)
		return (0);
	len = get_index(str);
	ret = my_strndup(str, len, flag);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*data[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	ssize_t		read_byte;
	int			flag;

	flag = 0;
	read_byte = 1;
	if (fd >= OPEN_MAX || fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (!my_strnewline(*(data + fd)) && read_byte)
	{
		if ((read_byte = read(fd, buff, BUFFER_SIZE)) == -1)
			return (-1);
		*(buff + read_byte) = 0;
		*(data + fd) = my_strjoin(*(data + fd), buff, &flag);
		if (flag == -3)
			return (-1);
	}
	*line = get_line_until_newline(*(data + fd), &flag);
	data[fd] = get_restdata(*(data + fd), &flag);
	if (flag == -1 || flag == -2)
		return (-1);
	if (read_byte == 0)
		return (0);
	return (1);
}
