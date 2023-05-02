/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoberri <simoberri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:53:51 by mberri            #+#    #+#             */
/*   Updated: 2023/05/02 00:52:12 by simoberri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    key_up(t_player *player)
{
    int new_x;
    int new_y;

    new_x = floor(cos(degree_to_radian(player->angle)) / moveSpeed);
    new_y = floor(sin(degree_to_radian(player->angle)) / moveSpeed);
    if (player->map[player->y + new_y][player->x + new_x] != '1')
    {
       player->map[player->y + new_y][player->x + new_x] = 'P';
        player->map[player->y][player->x] = '0';
        find_player(player);
        init_raycasting(player);
    }
}

void    key_down(t_player *player)
{
    int new_x;
    int new_y;

    new_x = floor(cos(degree_to_radian(player->angle)) / moveSpeed);
    new_y = floor(sin(degree_to_radian(player->angle)) / moveSpeed);
    if (player->map[player->y - new_y][player->x - new_x] != '1')
    {
        player->map[player->y - new_y][player->x - new_x] = 'P';
        player->map[player->y][player->x] = '0';
        find_player(player);
        init_raycasting(player);
    }
}

void    key_left(t_player *player)
{
    player->angle -= rotSpeed;
   // init_raycasting(player);
}

void    key_right(t_player *player)
{
    player->angle += rotSpeed;
    //init_raycasting(player);
}