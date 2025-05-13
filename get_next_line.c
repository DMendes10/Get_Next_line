/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:46:36 by diomende          #+#    #+#             */
/*   Updated: 2025/05/13 15:46:46 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	static char		*storage;
	int				counter;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_newline_finder(storage) == -1)
	{
		counter = read (fd, buffer, BUFFER_SIZE);
		if (counter < 0)
			return (NULL);
		if (counter == 0)
			break ;
		buffer[counter] = '\0';
		storage = ft_strjoin (storage, buffer);
	}
	line = ft_line_builder (storage);
	storage = ft_storage_builder (storage);
	return (line);
}

// int main(void)
// {
// 	int	i;
// 	int	fd = open("read_error.txt", O_RDONLY);
// 	char *line;

// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }