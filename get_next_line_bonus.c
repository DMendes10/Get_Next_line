/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:46:36 by diomende          #+#    #+#             */
/*   Updated: 2025/05/16 17:28:01 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		buffer[1024][BUFFER_SIZE + 1];
	int				counter;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	line = NULL;
	if (*buffer[fd] != '\0')
		line = ft_strjoin (line, buffer[fd]);
	while (ft_newline_finder(line) == -1)
	{
		counter = read (fd, buffer[fd], BUFFER_SIZE);
		if (counter < 0)
		{
			buffer[fd][0] = '\0';
			return (free(line), NULL);
		}
		if (counter == 0)
			break ;
		buffer[fd][counter] = '\0';
		line = ft_strjoin (line, buffer[fd]);
	}
	line = ft_line_builder (line);
	ft_storage_builder (buffer[fd]);
	return (line);
}

// int main(void)
// {
// 	int	i;
// 	int	fd = open("read_error.txt", O_RDONLY);
// 	char *line;

// 	i = 0;

// 	while (i < 10)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// }