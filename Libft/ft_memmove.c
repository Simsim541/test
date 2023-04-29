/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:54:11 by mberri            #+#    #+#             */
/*   Updated: 2021/11/17 16:03:18 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char *)dest;
	s2 = (char *)src;
	if (!s1 && !s2)
		return (s1);
	i = 0;
	if (s1 > s2)
	{
		i = 1;
		while (i <= len)
		{
			s1[len - i] = s2[len - i];
			i++;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			s1[i] = s2[i];
	}
	return (s1);
}
