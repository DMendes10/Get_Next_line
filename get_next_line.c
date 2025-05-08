/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:46:36 by diomende          #+#    #+#             */
/*   Updated: 2025/05/08 18:36:03 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	void	*buffer;
	read (fd, buffer, 5);

	return ((char *)buffer);
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