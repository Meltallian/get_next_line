/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:08:12 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/31 18:21:02 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rem_read(int fd, char *left_str)
{
	char	*buff;
	char	*temp;
	ssize_t	rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free (buff);
			return (0);
		}
		buff[rd_bytes] = '\0';
		temp = left_str;
		left_str = ft_strjoin(temp, buff);
		free (temp);
		temp = 0;
	}
	free (buff);
	return (left_str);
}

char	*n_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	while (str[i] && str[i] == '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (0);
	line = ft_substr(str, 0, i);
	return (line);
}

char	*new_str(char *str)
{
	char	*new_str;
	size_t	i;

	i = 0;
	while (str[i] && str[i] == '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new_str = malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!new_str)
		return (0);
	new_str = ft_substr(str, i, ft_strlen(str) - (i - 1));
	free (str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left = rem_read(fd, left);
	if (!left)
		return (0);
	line = n_line(left);
	left = new_str(left);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("texte.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	get_next_line(fd);
	printf("%s", line);
	get_next_line(fd);
	printf("%s", line);
	get_next_line(fd);
	printf("%s", line);
	get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
