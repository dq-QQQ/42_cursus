#include "../Inc/solong.h"

void move_down(t_game *game)
{
    if (game->map[game->player->x + 1][game->player->y] == '1')
        return ;
    else if (game->map[game->player->x + 1][game->player->y] == 'C')
        game->player->item_cnt++;
    else if (game->map[game->player->x + 1][game->player->y] == 'E')
        if (game->collectible == game->player->item_cnt)
            end_program(1);
    if (game->map[game->player->x + 1][game->player->y] != 'E')
        game->map[game->player->x++][game->player->y] = '0';
    game->map[game->player->x][game->player->y] = 'P';
    ft_putnbr(++(game->player->move_cnt));
    write(1, "\n", 1);
    draw_tiles(game);
}

void move_up(t_game *game)
{
    if (game->map[game->player->x - 1][game->player->y] == '1')
        return ;
    else if (game->map[game->player->x - 1][game->player->y] == 'C')
        game->player->item_cnt++;
    else if (game->map[game->player->x - 1][game->player->y] == 'E')
        if (game->collectible == game->player->item_cnt)
            end_program(1);
    if (game->map[game->player->x - 1][game->player->y] != 'E')
        game->map[game->player->x--][game->player->y] = '0';
    game->map[game->player->x][game->player->y] = 'P';
    ft_putnbr(++(game->player->move_cnt));
    write(1, "\n", 1);
    draw_tiles(game);
}

void move_left(t_game *game)
{
    if (game->map[game->player->x][game->player->y - 1] == '1')
        return ;
    else if (game->map[game->player->x][game->player->y + 1] == 'C')
        game->player->item_cnt++;
    else if (game->map[game->player->x][game->player->y - 1] == 'E')
        if (game->collectible == game->player->item_cnt)
            end_program(1);
    if (game->map[game->player->x][game->player->y - 1] != 'E')
        game->map[game->player->x][game->player->y--] = '0';
    game->map[game->player->x][game->player->y] = 'P';
    ft_putnbr(++(game->player->move_cnt));
    write(1, "\n", 1);
    draw_tiles(game);
}

void move_right(t_game *game)
{
    if (game->map[game->player->x][game->player->y + 1] == '1')
        return ;
    else if (game->map[game->player->x][game->player->y + 1] == 'C')
        game->player->item_cnt++;
    else if (game->map[game->player->x][game->player->y + 1] == 'E')
        if (game->collectible == game->player->item_cnt)
            end_program(1);
    if (game->map[game->player->x][game->player->y + 1] != 'E')
        game->map[game->player->x][game->player->y++] = '0';
    game->map[game->player->x][game->player->y] = 'P';
    ft_putnbr(++(game->player->move_cnt));
    write(1, "\n", 1);
    draw_tiles(game);
}