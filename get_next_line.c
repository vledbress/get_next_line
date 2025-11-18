/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:50:04 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/18 11:22:02 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


    // char *line = ft_substr(remain, 0, newline_pos - remain + 1); // строка до \n
    // char *tmp = ft_strdup(newline_pos + 1);                     // остаток

char *get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*line;
	

	if (!line)
	{
		read(fd, buffer, BUFFER_SIZE);
	}



	
	buffer[BUFFER_SIZE] = 0;

	

	return (line);
}
