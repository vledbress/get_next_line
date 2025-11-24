/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:50:04 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/24 14:13:06 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char	*s1);
char	*ft_substr(char *s, size_t start, size_t len);

char	*ft_extract_line(char *stash)
{
	size_t	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr(stash, 0, i));
}

char	*ft_clean_stash(char	*stash)
{
	char	*newline;
	char	*new_stash;
	size_t	start;
	size_t	len;

	if (!stash)
		return (NULL);
	newline = ft_strchr(stash, '\n');
	if (!newline)
		return (free(stash), NULL);
	start = (newline - stash) + 1;
	len = ft_strlen(stash);
	if (start >= len)
		return (free(stash), NULL);
	new_stash = ft_substr(stash, start, len - start);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*stash;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = 0;
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(stash), stash = NULL, NULL);
	}
	line = ft_extract_line(stash);
	stash = ft_clean_stash(stash);
	return (line);
}
