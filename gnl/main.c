#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int		ret;
	int		fd;
	char	*line;

//*line이 선언된 상태로 get_next_line 함수로 넘어감

	fd = open("Yourtext", O_RDONLY);
	while ((ret = (get_next_line(fd, &line)) > 0))
	{
	//	printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
}
