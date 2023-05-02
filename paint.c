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

void circle(t_data *data, int y, int x, int color)
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
                mlx_pixel_put(data->mlx, data->mlx_win, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void paint_floor(t_data *data)
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
            mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0x0066CC);
            x++;
        }
     y++;
    }
}

void    paint_ceiling(t_data *data)
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
            mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0x00CCFF);
            x++;
        }
     y++;
    }
}

void ft_paint(t_data *data)
{
    find_player(data);
    paint_floor(data);
    paint_ceiling(data);
    circle(data, data->player->y * TILE_SIZE, data->player->x * TILE_SIZE, 0x00FF00);
}