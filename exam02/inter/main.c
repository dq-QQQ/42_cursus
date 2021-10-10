#include <unistd.h>

int		precheck(char *str, char c, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv){
	int i ,j;

	if (argc == 3){
		i = 0;
		while (argv[1][i]){
			j = 0;
			if (precheck(argv[1], argv[1][i], i)){
				while (argv[2][j]){
					if (argv[1][i] == argv[2][j]){
						write(1, &argv[1][i], 1);
						break;
					}
					j++;
				}
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 1;
}
