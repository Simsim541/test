/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:08:09 by mberri            #+#    #+#             */
/*   Updated: 2021/11/18 18:20:46 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*str, const char	*to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	if (!*to_find || !to_find)
		return (ptr);
	while (ptr[i] && i < len)
	{
		j = 0;
		while (ptr[i + j] == to_find[j] && to_find[j] && i + j < len)
			j++;
		if (to_find[j] == '\0')
			return (&ptr[i]);
		i++;
	}
	return (0);
}
