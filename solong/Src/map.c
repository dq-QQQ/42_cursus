#include "../Inc/solong.h"

void	draw_element(t_game *game, int row, int col, char flag)
{
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;

	row = row * 60;
	col = col * 60;
	if (flag == '1')
		path = "./asset/block.xpm";
	else if (flag == 'B')
		path = "./asset/background.xpm";
	else if (flag == 'P')
		path = "./asset/player.xpm";
	else if (flag == 'C')
		path = "./asset/collectible.xpm";
	else if (flag == 'E')
		path = "./asset/exit.xpm";
	else
		path = NULL;
	img = mlx_xpm_file_to_image(game->mlx_ptr, path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, row, col);
}

void	draw_tiles(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	draw_element(game, 0, 0, 'B');
	while (++row < ROW)
	{
		col = -1;
		while (++col < COL)
		{
			if (game->map[row][col] == '1')
				draw_element(game, col, row, '1');
			else if (game->map[row][col] == 'P')
			{
				game->player.x = row;
				game->player.y = col;
				draw_element(game, col, row, 'P');
			}
			else if (game->map[row][col] == 'C')
				draw_element(game, col, row, 'C');
			else if (game->map[row][col] == 'E')
				draw_element(game, col, row, 'E');
		}
	}
}

void	map_init(t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	line = NULL;
	i = 0;
	fd = open(game->map_path, O_RDONLY);
	while (get_next_line(&line, fd) > 0)
		put_data_to_game(game, i++, &line);
	put_data_to_game(game, i, &line);
	check_valid_map(game);
	draw_tiles(game);
}
