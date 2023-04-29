/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:08:38 by mberri            #+#    #+#             */
/*   Updated: 2023/04/12 22:25:03 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc((sizeof(char) * ft_strlen(str)) + 1);
	if (!ptr)
		return (0);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (0);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (0);
	ptr = (char *) malloc ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ptr)
		return (0);
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start > len)
		str = (char *)malloc(len + 1 * sizeof(char));
	else
		str = (char *)malloc(((ft_strlen(s) - start) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

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
