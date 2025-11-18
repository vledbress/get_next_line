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

char *get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*remain;
	char		*line;
	

	read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = 0;
	printf("%s\n", buffer);
	

	return (line);
}
