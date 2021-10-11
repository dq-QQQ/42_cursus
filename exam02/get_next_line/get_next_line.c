#include "get_next_line.h"

int ft_strlen(char *str){
	int ret = 0;
	while (str[ret])
		ret++;
	return  ret;
}

char *ft_strndup(char *str, int size){
	char *ret;
	int i = 0;

	ret = (char *)malloc(sizeof(char) * size + 1);
	ret[size] = '\0';
	while (str[i] && i < size){
		ret[i] = str[i];
		i++;
	}
	return ret;
}

char *ft_strjoin(char *str1, char *str2){
	char *ret;
	int len1 = ft_strlen(str1);
	int len2 = ft_strlen(str2);
	int i = 0,j = 0;

	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	*(ret + len1 +len2) = '\0';
	while (i < len1){
		ret[i] = str1[i];
		i++;
	}

	while (i < len1 + len2){
		ret[i] = str2[j];
		i++;
		j++;
	}
	return ret;
}

char *ft_strchr(char *str, char c){
	int i = 0;

	while (str[i]){
		if (str[i] == c){
			return (str + i);
		}
		i++;
	}
	if (c == '\0')
		return(str + i);
	return NULL;
}

int get_next_line(char **line){
	static char *data;
	char *tmp;
	int byte;
	char *nextline;
	char buff[2] = {0};

	if (data == NULL){
		data = ft_strndup("", 0);
		while ((byte = read(0, buff, 1) > 0)){
			tmp = data;
			data = ft_strjoin(data, buff);
			free(tmp);
		}
	}

	nextline = ft_strchr(data, '\n');

	if (nextline != NULL){
		*line = ft_strndup(data, nextline - data);
		data = nextline + 1;
		return 1;
	}
	else{
		*line = ft_strndup(data, ft_strchr(data, '\0') - data);
		return 0;
	}
}