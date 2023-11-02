/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:33:59 by jbidaux           #+#    #+#             */
/*   Updated: 2023/11/02 17:53:05 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*rem_read(int fd, char *left, char *buffer)
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
		else if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!left)
			left = ft_strdup("");
		tmp = left;
		left = ft_strjoin(tmp, buffer);
		free (tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left);
}

char	*cut(char *str)
{
	char	*cut_str;
	ssize_t	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0' || str[1] == 0)
		return (NULL);
	cut_str = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (!*cut_str)
	{
		free (cut_str);
		cut_str = 0;
	}
	str[i + 1] = '\0';
	return (cut_str);
}

char	*get_next_line(int fd)
{
	static char	*left[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (left[fd]);
		free (buffer);
		left[fd] = NULL;
		buffer = NULL;
		return (0);
	}
	if (!buffer)
		return (0);
	line = rem_read(fd, left[fd], buffer);
	free (buffer);
	buffer = 0;
	if (!line)
		return (0);
	left[fd] = cut(line);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("texte.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)))
		printf("%s", line);
	get_next_line(fd);
	printf("%s", line);
//	free(line);
	close(fd);
	return (0);
}
 */