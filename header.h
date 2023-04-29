/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoberri <simoberri@student.42.fr>        +#+  +:+       +#+        */
/*                               
                 +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:13:04 by mberri            #+#    #+#             */
/*   Updated: 2023/04/19 00:47:14 by simoberri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#define BUFFER_SIZE 1

#define TILE_SIZE 64

#define NUM_COLS 21
#define NUM_ROWS 11

#define WIDTH NUM_COLS * TILE_SIZE
#define HEIGHT NUM_ROWS * TILE_SIZE

# define KEY_EVENT_PRESS		02
# define KEY_EVENT_RELEASE		03

# define KEY_ESC	53
# define KEY_W	13
# define KEY_A	0
# define KEY_D	2
# define KEY_S	1
# define KEY_LEFT	123
# define KEY_RIGHT	124

# define moveSpeed 1
# define rotSpeed 3

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct s_player{
    int x;
    int y;
    int fov;
    int angle;
    int ray_angle;
    double increment_angle;
    int presicion;
    int ray_x;
    int ray_y;
    void *mlx;
    void *win;
    void *img;
    char **map;
}t_player;

void    init_variable(int *v1, int *v2, int *v3, int *v4, int *v5);
int     key_press(int keycode, t_player *mv);
void    key_up(t_player *player);
void    key_down(t_player *player);
void    key_left(t_player *player);
void    key_right(t_player *player);
void    find_player(t_player  *pl);
void    ft_exit();
int     destroy_notify(t_player   *game);
void    circle(t_player *game, int x, int y, int color);
void    draw(t_player *game, int ray_count, int wall_height);
void    init_raycasting(t_player *player);
int     degree_to_radian(int degree);
void    paint_ceiling(t_player *game);
void    ft_paint(t_player *game);
void    paint_floor(t_player *game);
char	*get_next_line(int fd);
int		read_file(char **buffer, char **line, char **text, int fd);
char	*get_line(char **text, char **line);
#endif