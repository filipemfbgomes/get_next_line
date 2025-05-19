/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 18:13:37 by figomes           #+#    #+#             */
/*   Updated: 2025-05-05 18:13:37 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line_helper(char *newline, char *buffer, char *line)
{
	if (newline)
	{
		ft_strcpy(buffer, newline + 1);
		*(newline + 1) = '\0';
	}
	else
		buffer[0] = '\0';
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			count;

	count = 1;
	newline = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	line = ft_strdup(buffer[fd]);
	if (!line)
		return (NULL);
	while (!newline && count != 0)
	{
		count = read(fd, buffer[fd], BUFFER_SIZE);
		if (count == -1)
		{
			free(line);
			return (NULL);
		}
		buffer[fd][count] = '\0';
		line = ft_strjoin(line, buffer[fd]);
		newline = ft_strchr(line, '\n');
	}
	return (get_next_line_helper(newline, buffer[fd], line));
}

/*int	main(void)
{
	int		x;
	int		y;
	int		z;
	char	*test;
	char	*test2;
	char	*test3;

	x = open("test.txt", O_RDONLY);
	y = open("test2.txt", O_RDONLY);
	z = open("test3.txt", O_RDONLY);
	test = get_next_line(x);
	printf("%s", test);
	test2 = get_next_line(y);
	printf("%s", test2);
	test3 = get_next_line(z);
	printf("%s", test3);
	free(test);
	free(test2);
	free(test3);
	close(x);
	close(y);
	close(z);
	return (0);
}
 */