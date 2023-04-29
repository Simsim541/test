/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:05:34 by mberri            #+#    #+#             */
/*   Updated: 2021/11/20 19:11:10 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*string, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *) string;
	while (ptr[i])
	{
		if (ptr[i] == (char) c)
			return (&ptr[i]);
		i++;
	}
	if (ptr[i] == (char) c)
		return (&ptr[i]);
	return (NULL);
}
