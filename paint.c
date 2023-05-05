/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoberri <simoberri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:12:19 by simoberri         #+#    #+#             */
/*   Updated: 2023/05/05 14:45:01 by simoberri        ###   ########.fr       */
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
            data->image->buffer_img[y][x] = 0x0066CC;
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
            data->image->buffer_img[y][x] = 0x00CCFF;
            x++;
        }
     y++;
    }
}

void ft_paint(t_data *data)
{
    paint_floor(data);
    paint_ceiling(data);
}

void    put_img(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < HEIGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            data->image->data[i * WIDTH + j] = data->image->buffer_img[i][j];
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->image->img,0, 0);
}