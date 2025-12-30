/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:50:04 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/24 12:29:33 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(char *s, char c); 
char	*ft_strjoin(char *s1, char *s2);
char	*ft_extract_line(char *stash);
char	*ft_clean_stash(char *stash);

char *get_next_line(int fd)
{
    char        buffer[BUFFER_SIZE + 1];
    static char *stash;
	char		*line;
    ssize_t     bytes_read;

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






