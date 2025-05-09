/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:46:36 by diomende          #+#    #+#             */
/*   Updated: 2025/05/09 20:44:05 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line_helper(char *line, char *nextline, char *buffer)
{
	if (nextline)
	{
		ft_strlcpy (buffer, nextline + 1);
		*(nextline + 1) = '\0';
	}
	else
		buffer[0] = '\0';
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*line;
	char	*nextline;
	int	count;

	count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup (buffer);
	// if (!line)
	// 	return (NULL);
	nextline = NULL;
	while (!nextline && count)
	{
		count = read (fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free (line);
			return (NULL);
		}
		buffer[count] = '\0';
		line = ft_strjoin (line, buffer);
		if (!line)
			return (NULL);
		nextline = ft_strchr(line, '\n');
	}
	line = next_line_helper (line, nextline, buffer);
	return (line);
}

int main (void)
{
	int	fd;
	char *str;

	fd = open ("teste.txt", O_RDWR);
	str = get_next_line(fd);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
}