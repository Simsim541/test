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
    pl->ray_angle = pl->angle - (pl->fov / 2);
    pl->increment_angle = (double)pl->fov / (double)(WIDTH);
    pl->ray_x = 0;
    pl->ray_y = 0;
    pl->presicion = TILE_SIZE;
    return (pl);
}


int key_release(int keycode, t_player *mv)
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
    t_player *player;
    (void)ac;
    (void)av;

    int fd;
    player = init_var();
    char **line;
    int i;

    i = 0;
    line = malloc(sizeof(char *) * NUM_ROWS);
    line[NUM_ROWS] = NULL;
    fd = open(av[1], O_RDONLY);
    line[i] = get_next_line(fd);
    while (line[i])
        line[++i] = get_next_line(fd);
    player->map = line;
    player->mlx = mlx_init();
    player->win = mlx_new_window(player->mlx, WIDTH, HEIGHT, "Cub3D");
    // ft_paint(player);
    init_raycasting(player);
    mlx_hook(player->win, 3, 1L << 1, key_release, player);
    mlx_hook(player->win, 17, 0, &destroy_notify, player);
    mlx_loop(player->mlx);
    return (0);
}