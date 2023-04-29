/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:47:35 by mberri            #+#    #+#             */
/*   Updated: 2021/11/10 12:29:39 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	x;

	x = (unsigned char) c;
	ptr = str;
	i = 0;
	while (i < len)
	{
		ptr[i] = x;
		i++;
	}
	return (str);
}
