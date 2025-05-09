/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:46:58 by diomende          #+#    #+#             */
/*   Updated: 2025/05/09 19:16:58 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s);
	s2 = malloc((sizeof (char)) * len +1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s);
	return (s2);
}

size_t	ft_strlcpy(char *dst, const char *src)
{
	size_t	len;
	size_t	i;
	size_t	destlen;

	len = ft_strlen(src);
	destlen = ft_strlen(dst);
	i = 0;
	if (len + 1 < destlen)
	{
		while (src[i++])
			dst[i] = src[i];
		dst[i] = '\0';
	}
	else if (destlen != 0)
	{
		while (i < destlen -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (i[s])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1);
	ft_strlcat (s3, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	while (s1[i])
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&s1[i]);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstsize;
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	dstsize = ft_strlen(dst);
	if (dstsize > size)
		return (ft_strlen(src) + size);
	else
		ft_strlcpy (&dst[dstsize], src);
	return (ft_strlen(src) + dstsize);
}

