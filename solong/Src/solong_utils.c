#include "../Inc/solong.h"

int	end_program(int flag)
{
	char	*notify_str;

	if (flag == -1)
		notify_str = "Error\nTry again.";
	else if (flag == 1)
		notify_str = "You find an exit";
	else
		notify_str = "End program at the request of the user.";
	while (*notify_str)
	{
		write(1, notify_str, 1);
		notify_str++;
	}
	exit(0);
	return (0);
}

void	put_data_to_game(t_game *game, int i, char **line)
{
	int	j;

	j = -1;
	while (++j < COL)
		    game->map[i][j] = (*line)[j];
	free(*line);
	*line = NULL;
}

int		check_ber(t_game *game)
{
	int	i;
	char *tmp;

	i = 0;
	tmp = game->map_path;
	while (tmp[i + 1])
		i++;
	if (tmp[i] != 'r' || tmp[i - 1] != 'e' || tmp[i - 2] != 'b')
		return (0);
	else
		return (1);
}

void	check_valid_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ROW)
	{
		j = -1;
		while (++j < COL)
		{
			if (game->map[i][j] == 'P')
				game->p_cnt++;
			else if (game->map[i][j] == 'C')
				game->c_cnt++;
			else if (game->map[i][j] == 'E')
				game->e_cnt++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				end_program(-1);
			if (i == 0 || i == 14 || j == 0 || j == 14)
				if (game->map[i][j] != '1')
					end_program(-1);
		}
	}
	if (game->c_cnt == 0 || game->e_cnt != 1 || game->p_cnt != 1
	|| check_ber(game) == 0)
		end_program(-1);
}

void	ft_putnbr(int n)
{
	char	num;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n <= 9)
	{
		num = '0' + n;
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
