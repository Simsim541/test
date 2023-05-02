/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoberri <simoberri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:12:19 by mberri            #+#    #+#             */
/*   Updated: 2023/05/02 03:14:59 by simoberri        ###   ########.fr       */
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


int key_release(int keycode, t_data *mv)
{
     if (keycode == KEY_ESC)
        exit(0);
    if (keycode == KEY_W)
        key_up(mv);
    if (keycode == KEY_S)
        key_down(mv);
    if (keycode == KEY_A)
        key_left(mv);
    if (keycode == KEY_D)
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
    init_raycasting(&data);
    mlx_hook(data.mlx_win, 3, 1L << 1, key_release, &data);
    mlx_hook(data.mlx_win, 17, 0, &destroy_notify, &data);
    mlx_loop(data.mlx);
    return (0);
}