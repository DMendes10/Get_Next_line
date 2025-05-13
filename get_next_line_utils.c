/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:46:58 by diomende          #+#    #+#             */
/*   Updated: 2025/05/13 15:45:59 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line_builder(char *s)
{
	int		i;
	int		line_size;
	char	*line;

	if (!s || !*s)
		return (NULL);
	line_size = ft_newline_finder (s);
	if (line_size == -1)
		line_size = ft_strlen(s) - 1;
	line = malloc ((line_size + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line[i] = '\0', line);
}

char	*ft_storage_builder(char *s)
{
	int		line_size;
	int		i;
	char	*storage;
	int		j;

	if (!s)
		return (NULL);
	line_size = ft_newline_finder(s);
	if (line_size == -1)
	{
		free (s);
		return (NULL);
	}
	storage = malloc((ft_strlen(s) - line_size) * sizeof(char));
	if (!storage)
		return (NULL);
	i = line_size + 1;
	j = 0;
	while (s[i] != '\0')
		storage[j++] = s[i++];
	storage[j] = '\0';
	free (s);
	return (storage);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (i[s] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	s3 = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	free (s1);
	return (s3);
}

int	ft_newline_finder(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
