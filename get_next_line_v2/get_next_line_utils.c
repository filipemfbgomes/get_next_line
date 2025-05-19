/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 14:45:43 by figomes           #+#    #+#             */
/*   Updated: 2025-04-29 14:45:43 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*newstr;

	len = ft_strlen(s) + 1;
	newstr = malloc(len);
	if (!newstr)
		return (NULL);
	ft_strcpy(newstr, s);
	return (newstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy(join + ft_strlen(s1), s2);
	free(s1);
	return (join);
}
