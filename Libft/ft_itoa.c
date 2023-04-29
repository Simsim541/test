/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:29:26 by mberri            #+#    #+#             */
/*   Updated: 2021/11/20 18:50:40 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	len(long int number)
{
	int	len;

	len = 0;
	if (number < 0)
	{
		len++;
		number = number * (-1);
	}
	while (number)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i <= j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j--;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			i;
	int			size;
	long int	num;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	i = 0;
	ptr = (char *)ft_calloc((len(num) + 1), sizeof(char));
	if (!ptr)
		return (0);
	if (n < 0)
		num *= -1;
	size = len(num);
	while (i < size)
	{
		ptr[i++] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		ptr[i++] = '-';
	ptr = ft_strrev(ptr);
	return (ptr);
}
