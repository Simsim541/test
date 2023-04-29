/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:00:17 by mberri            #+#    #+#             */
/*   Updated: 2023/04/26 22:56:47 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    init_raycasting(t_player *player)
{
    int wall;
    int ray_count;
    int ray_cos;
    int ray_sin;
    int distance;
    int wall_height;
    
    
    ray_count = 0;
    int x = 0;
    int y = 0;
    find_player(player);
    while (ray_count < WIDTH)
    {
        player->ray_x = player->x;
        player->ray_y = player->y;
        init_variable(&wall, &ray_cos, &ray_sin, &distance, &wall_height);
        ray_cos = cos(degree_to_radian(player->ray_angle) / player->presicion);
        ray_sin = sin(degree_to_radian(player->ray_angle) / player->presicion);
        while (wall == 0)
        {
            player->ray_x += ray_cos;
            player->ray_y += ray_sin;
            x = floor(player->ray_x);
            y = floor(player->ray_y);
            mlx_pixel_put(player->mlx, player->win, x, y, 0x00FF00);
            if (player->map[y][x] == '1')
                wall = 1;
        }
        distance = sqrt(pow(x - player->x, 2) + pow(player->y - player->y, 2));
        distance = distance * cos(degree_to_radian(player->ray_angle - player->angle));
        wall_height = floor((HEIGHT / 2) / distance);
        draw(player, ray_count, wall_height);
        player->ray_angle += player->increment_angle;   
        ray_count++;
    }
    circle(player, player->y * TILE_SIZE, player->x * TILE_SIZE, 0x00FF00);

}

void draw(t_player *game, int ray_count, int wall_height)
{
    int x;
    int y;

    x = ray_count;
    y = 0;
    wall_height = wall_height * 2;
    while(y < HEIGHT)
    {
        mlx_pixel_put(game->mlx, game->win, x, y, 0x808080);
        y++;
    }
    y = (HEIGHT / 2) - wall_height;
    while(y < (HEIGHT / 2) + wall_height)
    {
        mlx_pixel_put(game->mlx, game->win, x, y, 0x0000FF);
        y++;
    }
    y = (HEIGHT / 2) + wall_height;
    while(y < HEIGHT)
    {
        mlx_pixel_put(game->mlx, game->win, x, y, 0xff0000);
        y++;
    }
}

