/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:40:06 by figomes           #+#    #+#             */
/*   Updated: 2025/05/02 15:44:03 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			count;

	count = 1;
	newline = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	while (!newline && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(line);
			return (NULL);
		}
		buffer[count] = '\0';
		line = ft_strjoin(line, buffer);
		newline = ft_strchr(line, '\n');
	}
	return (get_next_line_helper(newline, buffer, line));
}

/*int	main(void)
{
	int		x;
	char	*test;
	char	*test2;
	char	*test3;
	char	*test4;

	x = open("test.txt", O_RDONLY);
	printf("%d\n", x);
	test = get_next_line(x);
	printf("%s", test);
	test2 = get_next_line(x);
	printf("%s", test2);
	test3 = get_next_line(x);
	printf("%s", test3);
	test4 = get_next_line(x);
	printf("%s", test4);
	free(test);
	free(test2);
	free(test3);
	free(test4);
	return (0);
}
*/