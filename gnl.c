/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:49:39 by mberri            #+#    #+#             */
/*   Updated: 2023/04/12 22:25:10 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_line(char **text, char **line)
{
	int		nl;
	char	*ff;

	nl = 0;
	while ((*text)[nl] != '\n' && (*text)[nl])
		nl++;
	ff = *text;
	if (ft_strchr(*text, '\n'))
	{
		*line = ft_substr(*text, 0, nl + 1);
		*text = ft_strdup(*text + nl + 1);
	}
	else
	{
		*line = ft_strdup(*text);
		*text = NULL;
	}
	free(ff);
	return (*line);
}

int	read_file(char **buffer, char **line, char **text, int fd)
{
	int		bytes;
	char	*ff;

	bytes = 1;
	while (!ft_strchr(*text, '\n') && bytes)
	{
		bytes = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes] = '\0';
		ff = *text;
		*text = ft_strjoin(*text, *buffer);
		free(ff);
	}
	free(*buffer);
	*line = get_line(text, line);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*text = NULL;
	char		*line;
	char		*buffer;
	int			bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!text)
		text = ft_strdup("");
	bytes = read_file(&buffer, &line, &text, fd);
	if (bytes == 0 && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}