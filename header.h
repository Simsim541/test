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
#define NUM_ROWS 6

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
# define rotSpeed 10

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct s_image {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
    int     *data;
    int     **arr_img;
    int     buffer_img[H][HEIGHT];
    int     width;
    int     height;
}	t_image;

typedef struct s_player{
    int     x;
    int     y;
    int     fov;
    int     angle;
    double  ray_angle;
    double  increment_angle;
    int     presicion;
    double  ray_x;
    double  ray_y;
}t_player;

typedef struct s_data
{
    void        *mlx;
    void        *mlx_win;
    char        **map;
    t_player    *player;
    t_image     *image;
}t_data;

//Key functions
int     key_release(int keycode, t_data *mv);
void    key_up(t_data       *data);
void    key_down(t_data     *data);
void    key_left(t_data     *data);
void    key_right(t_data    *data);

void    init_variable(int *v1, double *v2, double *v3, double *v4, int *v5);
void    find_player(t_data  *pl);
void    ft_exit();
int     destroy_notify(t_data *game);
void    circle(t_data *data, int x, int y, int color);
void    draw_wall(t_data *data, int ray_count, int wall_height);
void    init_raycasting(t_data *data);
double  degree_to_radian(double degree);
void    paint_ceiling(t_data *data);
void    ft_paint(t_data *data);
void    paint_floor(t_data *data);

//get_next_line functions
char	*get_next_line(int fd);
int		read_file(char **buffer, char **line, char **text, int fd);
char	*get_line(char **text, char **line);
void    put_img(t_data  *data);
#endif