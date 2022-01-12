#include "../Inc/solong.h"

void minilibx_init(t_game *game)
{
    game->mlx_ptr = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Create 2D Map!");
}

void img_init(t_game *game)
{
    game->img.img_ptr = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
    game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr, &game->img.bpp, &game->img.size_line, &game->img.endian);
}


int    press_key(int keycode, t_game game)
{
    if (keycode == KEYCODE_EXIT)
        exit(0);
    return (0);
}

int red_button(){
    exit(0);
}


int main(void)
{
    t_game game;

    minilibx_init(&game);
    img_init(&game);
    map_init(&game);
    mlx_hook(game.win_ptr, X_EVENT_KEYPRESS, 0, &press_key, &game);
    mlx_hook(game.win_ptr, 17, 0, &red_button, &game);
    mlx_loop(game.mlx_ptr);
    return (0);
}