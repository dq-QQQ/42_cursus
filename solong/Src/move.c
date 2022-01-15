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

void	move_down(t_game *game)
{
	if (game->map[game->player.x + 1][game->player.y] == '1')
		return ;
	else if (game->map[game->player.x + 1][game->player.y] == 'C')
		game->player.item_cnt++;
	else if (game->map[game->player.x + 1][game->player.y] == 'E')
	{
		if (game->c_cnt == game->player.item_cnt)
			end_program(1);
		else
			return ;
	}
	if (game->map[game->player.x + 1][game->player.y] != 'E')
		game->map[game->player.x++][game->player.y] = '0';
	game->map[game->player.x][game->player.y] = 'P';
	ft_putnbr(++(game->player.move_cnt));
	write(1, "\n", 1);
	draw_tiles(game);
}

void	move_up(t_game *game)
{
	if (game->map[game->player.x - 1][game->player.y] == '1')
		return ;
	else if (game->map[game->player.x - 1][game->player.y] == 'C')
		game->player.item_cnt++;
	else if (game->map[game->player.x - 1][game->player.y] == 'E')
	{
		if (game->c_cnt == game->player.item_cnt)
			end_program(1);
		else
			return ;
	}
	if (game->map[game->player.x - 1][game->player.y] != 'E')
		game->map[game->player.x--][game->player.y] = '0';
	game->map[game->player.x][game->player.y] = 'P';
	ft_putnbr(++(game->player.move_cnt));
	write(1, "\n", 1);
	draw_tiles(game);
}

void	move_left(t_game *game)
{
	if (game->map[game->player.x][game->player.y - 1] == '1')
		return ;
	else if (game->map[game->player.x][game->player.y - 1] == 'C')
		game->player.item_cnt++;
	else if (game->map[game->player.x][game->player.y - 1] == 'E')
	{
		if (game->c_cnt == game->player.item_cnt)
			end_program(1);
		else
			return ;
	}
	if (game->map[game->player.x][game->player.y - 1] != 'E')
		game->map[game->player.x][game->player.y--] = '0';
	game->map[game->player.x][game->player.y] = 'P';
	ft_putnbr(++(game->player.move_cnt));
	write(1, "\n", 1);
	draw_tiles(game);
}

void	move_right(t_game *game)
{
	if (game->map[game->player.x][game->player.y + 1] == '1')
		return ;
	else if (game->map[game->player.x][game->player.y + 1] == 'C')
		game->player.item_cnt++;
	else if (game->map[game->player.x][game->player.y + 1] == 'E')
	{
		if (game->c_cnt == game->player.item_cnt)
			end_program(1);
		else
			return ;
	}
	if (game->map[game->player.x][game->player.y + 1] != 'E')
		game->map[game->player.x][game->player.y++] = '0';
	game->map[game->player.x][game->player.y] = 'P';
	ft_putnbr(++(game->player.move_cnt));
	write(1, "\n", 1);
	draw_tiles(game);
}
