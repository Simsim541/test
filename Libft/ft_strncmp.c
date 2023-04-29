/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:58:25 by mberri            #+#    #+#             */
/*   Updated: 2021/11/11 20:58:30 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		i++;
	}
	if (i == n)
		return (0);
	if (s1[i] == '\0' && s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	if (s1[i] && s2[i] == '\0')
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
