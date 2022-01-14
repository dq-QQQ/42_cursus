#include "../Inc/solong.h"

char	*ft_emptystr(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) + 1);
	if (ret == NULL)
		return (NULL);
	ret[0] = '\0';
	return (ret);
}

char	*ft_strcjoin(char *str, char c)
{
	char	*ret;
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (str[len])
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 2));
	if (ret == NULL)
		return (NULL);
	ret[len] = c;
	ret[len + 1] = '\0';
	while (++i < len)
		ret[i] = str[i];
	return (ret);
}

int	get_next_line(char **line, int fd)
{
	char	buff[2];
	char	*tmp;

	buff[0] = 0;
	buff[1] = '\0';
	if (read(fd, buff, 0) == -1)
		return (-1);
	*line = ft_emptystr();
	while (read(fd, buff, 1) > 0)
	{
		if (buff[0] == '\n')
			return (1);
		tmp = *line;
		*line = ft_strcjoin(*line, buff[0]);
		free(tmp);
	}
	return (0);
}
