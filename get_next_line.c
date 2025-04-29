/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figomes <figomes@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-24 18:12:51 by figomes           #+#    #+#             */
/*   Updated: 2025-04-24 18:12:51 by figomes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char *save_line, int fd)
{
	char	*line;
	int		reader;

	reader = 1;
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	while (!ft_strchr(save_line, '\n') && reader != 0)
	{
		reader = read(fd, line, BUFFER_SIZE);
		if (reader == -1)
		{
			free(line);
			free(save_line);
			return (NULL);
		}
		line[reader] = '\0';
		save_line = ft_strjoin(save_line, line);
	}
	free(line);
	return (save_line);
}

char	*ft_get_line(char *save_line)
{
	char	*line;
	int		i;

	i = 0;
	if (save_line[i] == '\0')
		return (NULL);
	while (save_line[i] != '\0' && save_line[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (line == 0)
		return (NULL);
	i = 0;
	while (save_line[i] != '\0' && save_line[i] != '\n')
	{
		line[i] = save_line[i];
		i++;
	}
	if (save_line[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_recover(char *save_line)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (save_line[i] != '\0' && save_line[i] != '\n')
		i++;
	if (save_line[i] == '\0')
	{
		free(save_line);
		return (NULL);
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(save_line) - i + 1));
	if (ptr == 0)
		return (NULL);
	i++;
	while (save_line[i])
		ptr[j++] = save_line[i++];
	ptr[j] = '\0';
	free(save_line);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*save_line;
	char		*get_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save_line = read_file(save_line, fd);
	if (save_line == NULL)
		return (NULL);
	get_line = ft_get_line(save_line);
	save_line = ft_recover(save_line);
	printf("%s\n", save_line);
	return (get_line);
}

int	main(void)
{
	int	a = open("test.txt", O_RDONLY);
	char *x = get_next_line(a);
	printf("%s\n", x);
	printf("\n");
	printf("\n");
	x = get_next_line(a);
	printf("%s\n", x);
	return (0);
}