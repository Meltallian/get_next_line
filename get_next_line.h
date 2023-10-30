/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:08:46 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/27 17:36:44 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_struct {
	char	*line;
	ssize_t	bytes;
	size_t	i;
	char 	*temp;
	char	*new_line;
}	t_struct;

size_t	ft_strlen(const char *c);
char	*ft_strchr(const char *src, int c);
int		ft_len_strchr(const char *src, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_strndup(const char *src, size_t len);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s, const char *s2);

#endif // GET_NEXT_LINE_H
