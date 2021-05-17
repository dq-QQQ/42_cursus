/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:17:13 by kyujlee           #+#    #+#             */
/*   Updated: 2021/05/17 19:43:15 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_restdata(char *str)
{
	char	*ret;
	int		total_len;
	int		real_len;
	int		i;

	if (!str)
		return (0);
	real_len = my_strnewline(str);
	if (!*(str + real_len))
	{
		return (0);
	}
	total_len = ft_strlen(str);
	if ((ret = (char *)malloc(total_len - real_len + 1)) == 0)
		return (0);
	*(ret + total_len - real_len) = 0;
	i = 0;
	while (real_len < total_len)
	{
		*(ret + i) = *(str + real_len);
		i++;
		real_len++;
	}
	return (ret);
}

char	*get_line_until_newline(char *str)
{
	char	*ret;
	int		len;
	
	len = my_strnewline(str);
	ret = my_strndup(str, len);
	return (ret);
}


int get_next_line(int fd, char **line)
{
	static char	*data[OPEN_MAX];
	char		*buff;
	int			read_byte;
	read_byte = 1;
	if (fd >= OPEN_MAX || fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((buff = (char *)malloc(BUFFER_SIZE + 1)) == 0)
		return (-1);
	while (!my_strnewline(data[fd])  && read_byte)
	{
		if ((read_byte = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[read_byte] = '\0';
		printf("%s\n",buff);
		data[fd] = my_strjoin(data[fd], buff);
	}
	*line = get_line_until_newline(data[fd]);
	data[fd] = get_restdata(data[fd]);
	if (read_byte == 0)
		return (0);
	return (1);
}
