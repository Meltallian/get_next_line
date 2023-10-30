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

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
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

char	*ft_strndup(const char *src, size_t	len)
{
	char	*dup;
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (len > src_len)
		len = src_len;
	dup = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i] && i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(const char *s, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	res = (char *)malloc((ft_strlen(s) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

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
