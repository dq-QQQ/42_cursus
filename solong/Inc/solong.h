/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:47:12 by kyujlee           #+#    #+#             */
/*   Updated: 2022/01/15 19:14:30 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define TILES 60
# define COL 15
# define ROW 15
# define X_EVENT_KEYPRESS 2
# define X_EVENT_EXIT 17
# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define KEY_ESC 53

typedef struct s_player
{
	int	x;
	int	y;
	int	move_cnt;
	int	item_cnt;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	player;
	char		map[ROW][COL];
	int			p_cnt;
	int			c_cnt;
	int			e_cnt;
	char		*map_path;
}	t_game;

void	ft_putnbr(int n);
int		end_program(int flag);
void	map_init(t_game *game);
int		get_next_line(char **line, int fd);
void	check_valid_map(t_game *game);
void	put_data_to_game(t_game *game, int i, char **line);
int		key_check(int keycode, t_game *game);
void	draw_tiles(t_game *game);
void	move_down(t_game *game);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	draw_element(t_game *game, int row, int col, char flag);
#endif
