/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 18:12:32 by figomes           #+#    #+#             */
/*   Updated: 2025-04-24 18:12:32 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buffer[1024];
	char		*get_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	buffer[fd] = read_file(buffer[fd], fd);
	if (buffer[fd] == NULL)
		return (NULL);
	get_line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_recover(buffer[fd]);
	return (get_line);
}

/*int	main(void)
{
	int	a = open("test.txt", O_RDONLY);
	char *x = get_next_line(a);
	printf("%s\n", x);
	return (0);
}
*/