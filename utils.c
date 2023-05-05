/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoberri <simoberri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:24:53 by mberri            #+#    #+#             */
/*   Updated: 2023/05/04 00:38:07 by simoberri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void init_variable(int *v1, double *v2, double *v3, double *v4, int *v5)
{
    *v1 = 0;
    *v2 = 0;
    *v3 = 0;
    *v4 = 0;
    *v5 = 0;    
}

void ft_exit()
{
    exit(1);
} 

int destroy_notify(t_data *game)
{
	printf("EXITED SUCCESFULLY\n");
	mlx_destroy_window(game->mlx, game->mlx_win);
    free(game);
	ft_exit();
    return(0);
}

double degree_to_radian(double degree)
{
    return (degree * (M_PI / 180));
}

void    find_player(t_data  *pl)
{
    int i;
    int j;

    i = 0;
    while (pl->map[i])
    {
        j = 0;
        while(pl->map[i][j])
        {
            if (pl->map[i][j] == 'P')
            {
                pl->player->x = j;
                pl->player->y = i;
                return ;
            }
            j++;
        }
        i++;
    }

}