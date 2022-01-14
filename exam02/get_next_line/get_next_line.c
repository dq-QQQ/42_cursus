#include "get_next_line.h"

char *ft_emptystr(){
	char *ret;

	ret = (char *)malloc(sizeof(char) + 1);
	if (ret == NULL)
		return NULL;
	
	ret[0] = '\0';
	
	return ret;
}

char *ft_strcjoin(char *str, char c){
	char *ret;
	int len;
	int i = -1;

	while (str[len])
		len++;

	ret = (char *)malloc(sizeof(char) * (len + 2));
	if (ret == NULL)
		return NULL;
	
	ret[len] = c;
	ret[len + 1] = '\0';
	
	while (++i < len)
		ret[i] = str[i];

	return ret;
}

int get_next_line(char **line, int fd){
	char buff[2] = {0, '\0'};
	char *tmp;

	//while buffer is reading, if error happen then return -1
	if (read(fd,buff,0) == -1)
		return (-1);
	
	//line = "";
	*line = ft_emptystr();

	//read buffer and return whole string
	while (read(fd, buff, 1) > 0){
		//if buff character is '\n' return 1
		if (buff[0] == '\n')
			return 1;
		
		//store current address for free
		//reassign pointer with new character
		//lastly free previous pointer
		tmp = *line;
		*line = ft_strcjoin(*line, buff[0]);
		free(tmp);
	}

	return 0;
}

int main(){
	char *line = NULL;
	int fd;

	fd = open("./42.ber", O_RDONLY);

	while (get_next_line(&line, fd) > 0){
		printf ("%s\n", line);
		free(line);
		line = NULL;
	}
	printf ("%s\n", line);
	free(line);
	line = NULL;
	system("leaks a.out > tmp; cat tmp | grep leaks ; rm tmp");
}
