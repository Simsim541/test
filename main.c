/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:12:19 by mberri            #+#    #+#             */
/*   Updated: 2023/04/26 22:57:17 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_player    *init_var()
{
    t_player *pl;
    pl = malloc(sizeof(t_player));
    pl->fov = 60;
    pl->angle = 0;
    pl->ray_angle = pl->angle - (pl->fov / 2);
    pl->increment_angle = (double)pl->fov / (double)(WIDTH);
    pl->ray_x = 0;
    pl->ray_y = 0;
    pl->presicion = TILE_SIZE;
    return (pl);
}

int key_press(int keycode, t_player *mv)
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
    t_player *player;
    (void)ac;
    (void)av;
    
    int  fd;
    player = init_var();
    char **line;
    int  i;

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
    //ft_paint(player);
    init_raycasting(player);
    mlx_hook(player->win, KEY_EVENT_PRESS, 0, &key_press, player);
    mlx_hook(player->win, 17, 0, &destroy_notify, player);
    mlx_loop(player->mlx);
    return (0);
}