#include "../Inc/solong.h"

void draw_element(t_game *game, int row, int col, char flag){

	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	if (flag == '1')
		relative_path = "./asset/block.xpm";
	else if (flag == 'B')
		relative_path = "./asset/background.xpm";
	else if (flag == 'P')
		relative_path = "./asset/player.xpm";
	else if (flag == 'C')
		relative_path = "./asset/collectible.xpm";
	else if (flag == 'E')
		relative_path = "./asset/exit.xpm";
	img = mlx_xpm_file_to_image(game->mlx_ptr, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, row * 60, col * 60);
}


void draw_tiles(t_game *game)
{
    int row, col;
    row = -1;

    draw_element(game, 0, 0, 'B');
    while (++row < ROW)
    {
        col = -1;
        while (++col < COL)
        {
            if (game->map[row][col] == '1')
                draw_element(game, col, row, '1');
			else if (game->map[row][col] == 'P'){
				game->player->x = row;
				game->player->y = col;
				draw_element(game, col, row, 'P');
			}
            else if (game->map[row][col] == 'C'){
				draw_element(game, col, row, 'C');
			}
            else if (game->map[row][col] == 'E')
				draw_element(game, col, row, 'E');
        }
    }
}

void map_init(t_game *game, char *map_path)
{
    char *line = NULL;
	int fd;
    int i;
	int j;

	i = 0;
	fd = open(map_path, O_RDONLY);
	while (get_next_line(&line, fd) > 0)
        put_data_to_game(game, i++, &line);
	put_data_to_game(game, i, &line);
	check_valid_map(game);
    draw_tiles(game);
}