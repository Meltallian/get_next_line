/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:10:31 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/27 17:36:25 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == (char)c)
			return ((char *)&src[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&src[i]);
	return (0);
}

int	ft_len_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == (char)c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i + 1 < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 0)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
