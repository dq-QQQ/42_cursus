#include "../Inc/solong.h"

void game_init(t_game *game)
{
    game->mlx_ptr = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Create 2D Map!");
}

int	main(int argc, char **argv)
{
    t_game game;
    
    if (argc == 2){
        game_init(&game);
        map_init(&game, argv[1]);
        mlx_hook(game.win_ptr, X_EVENT_KEYPRESS, 0, &key_check, &game);
        mlx_hook(game.win_ptr, 17, 0, &end_program, &game);
        //printf ("%d %d", game.player_loc->x, game.player_loc->y);
        system("leaks solong > tmp; cat tmp | grep leaks ; rm tmp");
        mlx_loop(game.mlx_ptr);
    }
    end_program(-1);
	return (0);
}