/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoberri <simoberri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:53:51 by mberri            #+#    #+#             */
/*   Updated: 2023/05/05 13:03:42 by simoberri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    key_up(t_data *data)
{
    mlx_clear_window(data->mlx, data->mlx_win);
    int new_x;
    int new_y;

    new_x = floor(cos(degree_to_radian(data->player->angle)) * moveSpeed);
    new_y = floor(sin(degree_to_radian(data->player->angle)) * moveSpeed);
    if (data->map[data->player->y + new_y][data->player->x + new_x] != '1' && data->map[data->player->y + new_y][data->player->x + new_x] == '0')
    {
        data->map[data->player->y + new_y][data->player->x + new_x] = 'P';
        data->map[data->player->y][data->player->x] = '0';
        init_raycasting(data);
    }
    else
    {
        init_raycasting(data);
        return ;
    }
}

void    key_down(t_data *data)
{
    int new_x;
    int new_y;

    mlx_clear_window(data->mlx, data->mlx_win);
    new_x = floor(cos(degree_to_radian(data->player->angle)) * moveSpeed);
    new_y = floor(sin(degree_to_radian(data->player->angle)) * moveSpeed);
    if (data->map[data->player->y - new_y][data->player->x - new_x] != '1' && data->map[data->player->y - new_y][data->player->x - new_x] == '0')
    {
        data->map[data->player->y - new_y][data->player->x - new_x] = 'P';
        data->map[data->player->y][data->player->x] = '0';
        init_raycasting(data);
    }
    else
    {
        init_raycasting(data);
        return ;
    }
}

void    key_left(t_data *data)
{
    mlx_clear_window(data->mlx, data->mlx_win);
    data->player->angle -= rotSpeed;
    data->player->angle = data->player->angle % 360;
    init_raycasting(data);
}

void    key_right(t_data *data)
{
    mlx_clear_window(data->mlx, data->mlx_win);
    data->player->angle += rotSpeed;
    data->player->angle = data->player->angle % 360;
    init_raycasting(data);
}