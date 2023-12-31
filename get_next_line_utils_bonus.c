/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:53:51 by jbidaux           #+#    #+#             */
/*   Updated: 2023/11/03 11:15:56 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	if (!c)
		return (0);
	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s, char *s2)
{
	ssize_t	i;
	size_t	j;
	char	*res;

	res = (char *)malloc((ft_strlen(s) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (s[j])
		res[i++] = s[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	if (!src)
		return (0);
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(1 * sizeof(char));
		if (sub)
			*sub = '\0';
		return (sub);
	}
	sub = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!sub)
		return (0);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc((ft_strlen(src)+1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
