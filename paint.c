/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:12:19 by simoberri         #+#    #+#             */
/*   Updated: 2023/04/26 18:37:41 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void circle(t_player *game, int y, int x, int color)
{
    int i;
    int j;
    int r;

    r = 5;
    i = -r;
    while (i <= r)
    {
        j = -r;
        while (j <= r)
        {
            if (i * i + j * j <= r * r)
                mlx_pixel_put(game->mlx, game->win, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void paint_floor(t_player *game)
{
    int x;
    int y;

    y = HEIGHT / 2;
    x = 0;
    while (y <HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            mlx_pixel_put(game->mlx, game->win, x, y, 0x0000FF);
            x++;
        }
     y++;
    }
}

void    paint_ceiling(t_player *game)
{
    int x;
    int y;

    y = 0;
    x = 0;
    while (y < HEIGHT / 2)
    {
        x = 0;
        while (x < WIDTH)
        {
            mlx_pixel_put(game->mlx, game->win, x, y, 0x808080);
            x++;
        }
     y++;
    }
}

void ft_paint(t_player *game)
{
    paint_floor(game);
    paint_ceiling(game);
    circle(game, game->y, game->x, 0x00FF00);
}