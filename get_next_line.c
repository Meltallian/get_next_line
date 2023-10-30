/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:08:12 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/27 17:50:49 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	line_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	*ptr = buffer;
	t_struct	var;

	if (*ptr == '\0')
	{
		var.bytes = read(fd, buffer, BUFFER_SIZE);
		if (var.bytes == -1 || var.bytes == 0)
			return (0);
		else if (var.bytes > 0)
		{
			buffer[var.bytes] = '\0';
			ptr = buffer;
		}
	}
	var.line = ft_strndup(ptr, line_len(ptr));
	ptr += line_len(ptr);
	return (var.line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("texte.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	if (line)
		printf("%s", line);
	line = get_next_line(fd);
	if (line)
		printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
 */