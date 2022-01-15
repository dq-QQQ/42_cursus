#include "../Inc/solong.h"

void	game_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, TILES * COL, TILES * ROW, "");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game_init(&game);
		game.map_path = argv[1];
		map_init(&game);
		mlx_hook(game.win_ptr, X_EVENT_KEYPRESS, 0, &key_check, &game);
		mlx_hook(game.win_ptr, X_EVENT_EXIT, 0, &end_program, &game);
		mlx_loop(game.mlx_ptr);
	}
	end_program(-1);
	return (0);
}
