/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:05:27 by mberri            #+#    #+#             */
/*   Updated: 2021/11/10 18:18:01 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n && ptr[i] != (unsigned char) c)
		i++;
	if (i >= n)
		return (0);
	if (ptr[i] == (unsigned char) c)
		return (&ptr[i]);
	return (0);
}
