#include <unistd.h>

int		precheck(char *str, char c, int index)
{
	int		i;

	i = -1;
	while (++i < index)
		if (str[i] == c)
			return (0);
	return (1);
}

int main(int argc, char **argv){
	int i,j;

	if (argc == 3){
		i = -1;
		while (argv[1][++i])
			if (precheck(argv[1], argv[1][i], i))
					write (1, &argv[1][i], 1);

		j = -1;
		while (argv[2][++j])
			if (precheck(argv[2], argv[2][j], j))
					if (precheck(argv[1], argv[2][j], i))
							write (1, &argv[2][j], 1);
	}
	write(1, "\n", 1);
	return 0;
}
