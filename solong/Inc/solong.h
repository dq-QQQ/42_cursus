/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:47:12 by kyujlee           #+#    #+#             */
/*   Updated: 2022/01/12 12:36:37 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>

#define TILES 60
#define COL 15
#define ROW 15
#define WIDTH TILES * COL
#define HEIGHT TILES * ROW
#define X_EVENT_KEYPRESS 2
#define X_EVENT_EXIT 17
#define KEYCODE_EXIT 53

typedef struct s_img
{
    void *img_ptr;
    int *data;
    int bpp;
    int size_line;
    int endian;
} t_img;

typedef struct s_game
{
    void *mlx_ptr;
    void *win_ptr;
    t_img img;
    int map[ROW][COL];
} t_game;


void map_init(t_game *game);


#endif
