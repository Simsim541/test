/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:24:53 by mberri            #+#    #+#             */
/*   Updated: 2023/04/26 18:59:59 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void init_variable(int *v1, int *v2, int *v3, int *v4, int *v5)
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

int destroy_notify(t_player *game)
{
	printf("EXITED SUCCESFULLY\n");
	mlx_destroy_window(game->mlx, game->win);
    free(game);
	ft_exit();
    return(0);
}

int degree_to_radian(int degree)
{
    return (degree * (M_PI / 180));
}

void    find_player(t_player  *pl)
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
                pl->x = j;
                pl->y = i;
                return ;
            }
            j++;
        }
        i++;
    }

}