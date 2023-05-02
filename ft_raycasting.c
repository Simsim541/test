/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoberri <simoberri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:00:17 by mberri            #+#    #+#             */
/*   Updated: 2023/05/02 03:20:04 by simoberri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    init_raycasting(t_data *data)
{
    int wall;
    int ray_count;
    double ray_cos;
    double ray_sin;
    int distance;
    int wall_height;
    
    ray_count = 0;
    int x = 0;
    int y = 0;
    find_player(data);
    data->player->ray_angle = data->player->angle - (data->player->fov / 2);
    ft_paint(data);
    while (ray_count < WIDTH)
    {
        data->player->ray_x = data->player->x;
        data->player->ray_y = data->player->y;
        init_variable(&wall, &ray_cos, &ray_sin, &distance, &wall_height);
        ray_cos = (double)cos(degree_to_radian(data->player->ray_angle)) / (double)data->player->presicion;
        ray_sin = (double)sin(degree_to_radian(data->player->ray_angle)) / (double)data->player->presicion;
        while (wall == 0)
        {
            data->player->ray_x += ray_cos;
            data->player->ray_y += ray_sin;
            x = floor(data->player->ray_x);
            y = floor(data->player->ray_y);
            mlx_pixel_put(data->mlx, data->mlx_win, x * 64, y * 64, 0x00FF00);
            if (data->map[y][x] == '1')
                wall = 1;
        }
        distance = sqrt(pow(x - data->player->x, 2) + pow(data->player->y - data->player->y, 2));
        distance = distance * cos(degree_to_radian(data->player->ray_angle - data->player->angle));
        wall_height = floor((HEIGHT / 2) / distance);
        draw_wall(data, ray_count, wall_height);
        data->player->ray_angle += data->player->increment_angle;
        ray_count++;
    }
    circle(data, data->player->y * TILE_SIZE, data->player->x * TILE_SIZE, 0xCC0000);
}

void    draw_wall(t_data *data, int ray_count, int wall_height)
{
    int x;
    int y;
    int color;

    x = ray_count;
    y = (HEIGHT / 2) - (wall_height / 2);
    color = 0x331900;
    while (y < (HEIGHT / 2) + (wall_height / 2))
    {
        mlx_pixel_put(data->mlx, data->mlx_win, x, y, color);
        y++;
    }
}