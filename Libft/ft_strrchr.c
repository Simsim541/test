/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:59:36 by mberri            #+#    #+#             */
/*   Updated: 2021/11/10 18:31:49 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int		i;
	int		j;
	char	*ptr;
	int		isfound;

	i = 0;
	j = 0;
	isfound = 0;
	ptr = (char *) s;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (char) c)
		{
			j = i;
			isfound = 1;
		}
		i++;
	}
	if (ptr[i] == (char) c)
		return (&ptr[i]);
	if (!isfound)
		return (0);
	return (&ptr[j]);
}
