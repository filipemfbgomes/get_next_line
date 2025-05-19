/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-19 15:11:41 by figomes           #+#    #+#             */
/*   Updated: 2025-05-19 15:11:41 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char *buffer, int fd)
{
	char	*line;
	int		reader;

	reader = 1;
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && reader != 0)
	{
		reader = read(fd, line, BUFFER_SIZE);
		if (reader == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		line[reader] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*get_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = read_file(buffer, fd);
	if (!buffer)
		return (NULL);
	get_line = ft_get_line(buffer);
	buffer = ft_recover(buffer);
	return (get_line);
}

/*int	main(void)
{
	int	a = open("map1.ber", O_RDONLY);
	char *x = get_next_line(a);
	printf("%s\n", x);
	free(x);
	x = get_next_line(a);
	printf("%s\n", x);
	free(x);
	close(a);
	return (0);
}*/