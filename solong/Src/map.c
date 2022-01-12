#include "../Inc/solong.h"


void draw_pixels_of_tile(t_game *game, int row, int col)
{
    void	*img;
	char	*relative_path = "./asset/background.xpm";
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->mlx_ptr, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, row, col);
}



void draw_player(t_game *game, int row, int col){

	void	*img;
	char	*relative_path = "./asset/player.xpm";
	int		img_width;
	int		img_height;


	img = mlx_xpm_file_to_image(game->mlx_ptr, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, row * 60, col * 60);
}

void draw_block(t_game *game, int row, int col){

	void	*img;
	char	*relative_path = "./asset/block.xpm";
	int		img_width;
	int		img_height;

    if (col == 14)
        printf ("ho");
	img = mlx_xpm_file_to_image(game->mlx_ptr, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, row * 60, col * 60);
}
void draw_exit(t_game *game, int row, int col){

	void	*img;
	char	*relative_path = "./asset/exit.xpm";
	int		img_width;
	int		img_height;


	img = mlx_xpm_file_to_image(game->mlx_ptr, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, row * 60, col * 60);
}
void draw_collectible(t_game *game, int row, int col){

	void	*img;
	char	*relative_path = "./asset/collectible.xpm";
	int		img_width;
	int		img_height;


	img = mlx_xpm_file_to_image(game->mlx_ptr, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, row * 60, col * 60);
}

void draw_tiles(t_game *game)
{
    int row, col;

    row = 0;
    draw_pixels_of_tile(game, 0, 0);
    
    while (row < ROW)
    {
        col = -1;
        while (++col < COL)
        {
            if (game->map[row][col] == '1')
                draw_block(game, row, col);
			else if (game->map[row][col] == '3')
				draw_player(game, row, col);
            else if (game->map[row][col] == '4')
				draw_collectible(game, row, col);
            else if (game->map[row][col] == '5')
				draw_exit(game, row, col);
        }
        row++;
    }
}

void map_init(t_game *game)
{
    char *line = NULL;
	int fd;
    int i = 0,j;
	fd = open("./Map/42.ber", O_RDONLY);

	while (get_next_line(&line, fd) > 0){
        j = -1;
        while (++j < COL){
		    game->map[i][j] = line[j];
            
        }
        i++;
        //printf ("%s\n", game->map[i]);
        //printf ("%s\n", line);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
    

    draw_tiles(game);
}
