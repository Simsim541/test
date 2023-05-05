/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoberri <simoberri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:00:17 by mberri            #+#    #+#             */
/*   Updated: 2023/05/05 15:03:01 by simoberri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    init_raycasting(t_data *data)
{
    int wall;
    int ray_count;
    double ray_cos;
    double ray_sin;
    double distance;
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
        ray_cos = cos(degree_to_radian(data->player->ray_angle)) / (double)data->player->presicion;
        ray_sin = sin(degree_to_radian(data->player->ray_angle)) / (double)data->player->presicion;
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
        distance = sqrt(pow(x - data->player->x, 2) + pow(y - data->player->y, 2));
        distance = distance * cos(degree_to_radian(data->player->ray_angle - data->player->angle));
        wall_height = floor((double)(HEIGHT / 2) / (double)distance);
        if (wall_height > 0)
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

    mlx
    x = ray_count;
    y = (HEIGHT / 2) - wall_height;
    color = 0x331900;
    while (y < (HEIGHT / 2) + wall_height)
    {
        mlx_pixel_put(data->mlx, data->mlx_win, x, y, color);
        y++;
    }
}

/*void	draw_textured_wall(t_data *data, int ray_count, int wall_height, int tex_num)
{
    int		x;
    int		y;
    int		tex_x;
    int		tex_y;
    int		color;
    double	step;
    double	tex_pos;

    step = 1.0 * data->image[tex_num]->height / wall_height;
    tex_pos = (0.5 * wall_height - 0.5 * HEIGHT + (HEIGHT / 2)) * step;
    x = ray_count;
    y = (HEIGHT / 2) - (wall_height / 2);
    while (y < (HEIGHT / 2) + (wall_height / 2))
    {
        tex_x = (int)tex_pos & (data->image[tex_num]->width - 1);
        tex_y = (int)tex_pos & (data->image[tex_num]->height - 1);
        color = mlx_get_color_value(data->mlx, data->image[tex_num]->addr + (tex_y * data->image[tex_num]->line_length + tex_x * (data->image[tex_num]->bits_per_pixel / 8)));
        mlx_pixel_put(data->mlx, data->mlx_win, x, y, color);
        tex_pos += step;
        y++;
    }
}
*/