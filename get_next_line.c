/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:56:17 by jbidaux           #+#    #+#             */
/*   Updated: 2023/11/03 11:16:23 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_read(int fd, char	*left, char *buffer)
{
	char	*tmp;
	ssize_t	bytes;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (left);
			return (0);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!left)
			left = ft_strdup("");
		tmp = left;
		left = ft_strjoin(tmp, buffer);
		free (tmp);
		tmp = 0;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left);
}

char	*cut_line(char	*left)
{
	char	*cut_line;
	size_t	i;

	i = 0;
	while (left[i] != '\n' && left[i])
		i++;
	if (left[i] == '\0' || left[1] == '\0')
		return (0);
	cut_line = ft_substr(left, i + 1, ft_strlen(left) - i);
	if (!*cut_line)
	{
		free (cut_line);
		cut_line = 0;
	}
	left[i + 1] = '\0';
	return (cut_line);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (left);
		free (buffer);
		left = 0;
		buffer = 0;
		return (0);
	}
	if (!buffer)
		return (0);
	line = next_read(fd, left, buffer);
	free (buffer);
	buffer = 0;
	if (!line)
		return (0);
	left = cut_line(line);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
 	while ((line = get_next_line(fd)))
		printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
//	free(line);
	close(fd);
	return (0);
}
 */