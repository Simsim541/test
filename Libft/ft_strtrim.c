/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 09:45:16 by mberri            #+#    #+#             */
/*   Updated: 2021/11/20 19:05:07 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_check(char c, const char *chsc)
{
	int	j;

	j = 0;
	while (chsc[j])
	{
		if (c == chsc[j])
			return (1);
		j++;
	}
	return (0);
}

static int	ft_start(const char *str, const char *sp)
{
	int	start;

	start = 0;
	while (ft_check(str[start], sp))
		start++;
	return (start);
}

static int	ft_end(const char *str, const char *sp)
{
	int	len;

	len = ft_strlen(str) - 1;
	while (ft_check(str[len], sp))
		len--;
	len++;
	return (len);
}

static int	ft_size(const char *string, const char *sep)
{
	return (ft_end(string, sep) - ft_start(string, sep));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*ptr;
	int		k;
	int		j;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = 0;
	k = ft_end(s1, set);
	if (k == 0)
		return (ft_strdup(""));
	while (ft_check(s1[i], set))
		i++;
	ptr = (char *)malloc(ft_size(s1, set) + 1 * sizeof(char));
	if (!ptr)
		return (0);
	while (i < k)
	{
		ptr[j] = s1[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
