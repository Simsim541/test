/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:07:28 by mberri            #+#    #+#             */
/*   Updated: 2021/11/20 18:49:59 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_word(const char *str, char n)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (str[0] != n)
		count++;
	while (str[i] != '\0')
	{
		if (str[i] != n && str[i - 1] == n)
			count++;
		i++;
	}
	return (count);
}

static int	check(const char *str, int i, char a)
{
	int	x;

	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == a)
			return (x);
		x++;
		i++;
	}
	return (x);
}

static char	*ft_dup(char *str, char x, int d, const char *string)
{
	int	i;
	int	index;

	index = d;
	i = 0;
	while (string[index] != x && string[index])
	{
		str[i] = string[index];
		i++;
		index++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_free(char **str, int n)
{
	n--;
	while (n >= 0)
	{
		free(str[n]);
		n--;
	}
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;

	if (!s)
		return (0);
	ptr = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (0);
	j = 0;
	i = 0;
	while (i < count_word(s, c) && s[j])
	{
		while (s[j] == c && s[j])
			j++;
		ptr[i] = (char *)malloc((check(s, j, c) + 1) * sizeof(char));
		if (!ptr[i])
			return (ft_free(&ptr[i], i));
		ptr[i] = ft_dup(ptr[i], c, j, s);
		j += ft_strlen(ptr[i]);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}