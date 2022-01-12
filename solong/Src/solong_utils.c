#include "../Inc/solong.h"

int	key_check(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		end_program(0);
	if (keycode == LEFT)
		move_left(game);
	if (keycode == RIGHT)
		move_right(game);
	if (keycode == UP)
		move_up(game);
	if (keycode == DOWN)
		move_down(game);
	return (0);
}

int end_program(int flag)
{
    char *notify_str;

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


void put_data_to_game(t_game *game, int i, char **line)
{
	int j;

	j = -1;
	while (++j < COL)
		    game->map[i][j] = (*line)[j];
	free(*line);
	*line = NULL;
}

void check_valid_map(t_game *game)
{
	int i;
	int j;
	int at_least_one;

	at_least_one = 0;
	i = -1;
	while (++i < ROW)
    {
        j = -1;
        while (++j < COL){
			if (game->map[i][j] == 'P' ||game->map[i][j] == 'E')
				at_least_one++;
			else if (game->map[i][j] == 'C')
				game->collectible++;
			else if (i == 0 || i == 14 || j == 0 || j == 14)
				if (game->map[i][j] != '1')
					end_program(-1);
		}
	}
	if (at_least_one != 2 || game->collectible == 0)
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