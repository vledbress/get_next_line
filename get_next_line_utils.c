/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vborysov <vborysov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:50:07 by vborysov          #+#    #+#             */
/*   Updated: 2025/11/22 22:51:04 by vborysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(char *s1)
{
	size_t	len;
	if (!s1)
		return (0);
	len = 0;
	while (s1[len])
		len++;
	return (len);
}

char *	ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char *ft_substr(char *s, size_t start, size_t len)
{
	char	*result;
	size_t	index;
	
	if (!s)
		return (NULL);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	index = 0;
	while (s[index + start] && index < len)
	{
		result[index] = s[index + start];
		index++;
	}
	result[index] = 0;
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2)
		return (s1);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	return (result[i + j] = '\0', free(s1), result);
}

char	*ft_extract_line(char *stash)
{
	size_t i;
	
	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr(stash, 0, i));
}


char	*ft_clean_stash(char *stash)
{
	char	*newline;
	char	*new_stash;
	size_t	start;

	newline = ft_strchr(stash, '\n');
	if (!newline)
		return (free(stash), NULL);
	start = (newline - stash) + 1;
	new_stash = ft_substr(stash, start, ft_strlen(stash) - start);
	free(stash);
	return (new_stash);
}
