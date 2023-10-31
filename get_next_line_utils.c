/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbidaux <jeremie.bidaux@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:10:31 by jbidaux           #+#    #+#             */
/*   Updated: 2023/10/31 18:15:04 by jbidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char));
		s[0] = '\0';
	}
	if (!s || !s2)
		return (0);
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

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(1 * sizeof(char));
		if (sub)
			*sub = '\0';
		return (sub);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
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
