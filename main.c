/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoberri <simoberri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:12:19 by mberri            #+#    #+#             */
/*   Updated: 2023/05/05 13:32:55 by simoberri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_player *init_var()
{
    t_player *pl;

    pl = malloc(sizeof(t_player));
    pl->fov = 60;
    pl->angle = 90;
    pl->increment_angle = (double)pl->fov / (double)(WIDTH);
    pl->ray_x = 0;
    pl->ray_y = 0;
    pl->presicion = TILE_SIZE;
    return (pl);
}

void    fill_arr_img(t_image    *img)
{
    int i;
    int j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j = 0;
        while (j < TILE_SIZE)
        {
            img->arr_img[0][i * TILE_SIZE + j] = img->addr[i * TILE_SIZE + j];
            j++;
        }
        i++;
    }
}

void    load_img(t_data *data)
{
    int i;
    int j;
    while (i < HEIGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            data->image->buffer_img[i][j] = 0;
            j++;
        }
        i++;
    }
    data->image->arr_img = (int **)malloc(sizeof(int *));
    data->image->arr_img[0] = malloc(sizeof(int) * (TILE_SIZE * TILE_SIZE));
    ft_memset(data->image->arr_img[0], 0, TILE_SIZE * TILE_SIZE);
    data->image->img = mlx_xpm_file_to_image(data->mlx, "./image/wall.xpm", &data->image->width, &data->image->height);
    data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bits_per_pixel, &data->image->line_length, &data->image->endian);
    fill_arr_img(data->image);
    mlx_destroy_image(data->mlx, data->image->img);
}

int key_release(int keycode, t_data *mv)
{
     if (keycode <= 148 && keycode != 119 && keycode != 115 && keycode != 97 && keycode != 100)
        exit(0);
    if (keycode == 119)
        key_up(mv);
    if (keycode == 115)
        key_down(mv);
    if (keycode == 97)
        key_left(mv);
    if (keycode == 100)
        key_right(mv);
    return (0);
}

int main(int ac, char **av)
{
    t_data data;
    (void)ac;
    (void)av;

    int fd;
    char **line;
    int i;

    i = 0;
    line = malloc(sizeof(char *) * NUM_ROWS);
    line[NUM_ROWS] = NULL;
    fd = open(av[1], O_RDONLY);
    line[i] = get_next_line(fd);
    while (line[i])
        line[++i] = get_next_line(fd);
    data.player = init_var();
    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");
    data.map = line;
    data.image = malloc(sizeof(t_image));
    data.image->img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.image->img = (int *)mlx_get_data_addr(data.image->img, &data.image->bits_per_pixel, &data.image->line_length, &data.image->endian);
    load_img(&data);
    init_raycasting(&data);
    put_img(&data);
    mlx_hook(data.mlx_win, 3, 1L << 1, key_release, &data);
    mlx_hook(data.mlx_win, 17, 0, &destroy_notify, &data);
    mlx_loop(data.mlx);
    return (0);
}