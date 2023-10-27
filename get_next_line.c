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

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static char *ptr = 0;
	char *line;
	ssize_t	bytes;
	ssize_t	len;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
		return (0);
	buffer[bytes] = '\0';
	len = ft_len_strchr(buffer, '\n') + 1;
	line = (char *)malloc((len) * sizeof(char));
	if (!line)
		return (0);
	ft_strlcpy(line, buffer, len);
	line[len] = '\0';
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("texte.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	if (line)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
