/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:56:39 by rthammat          #+#    #+#             */
/*   Updated: 2022/03/16 14:24:01 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	size_res;
	char	*res;

	i = -1;
	j = -1;
	size_res = ft_strxlen(s1, '\0') + ft_strxlen(s2, '\0');
	res = malloc((size_res + 1) * sizeof(char));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++j])
		res[i++] = s2[j];
	res[size_res] = 0;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c > 256)
		c -= 256;
	if (c == '\0')
	{
		while (((char *)s)[i] != '\0')
			++i;
		s = &s[i];
		return ((char *)s);
	}
	while (s[i])
	{
		if (((char *)s)[i] == c)
		{
			s = &s[i];
			return ((char *)s);
		}
		++i;
	}
	s = NULL;
	return ((char *)s);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;
	size_t	t_size;

	t_size = count * size;
	res = malloc(t_size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < t_size)
	{
		res[i] = '\0';
		++i;
	}
	return ((void *)res);
}

size_t	ft_strxlen(const char *s, char delim)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != delim)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = -1;
	p = NULL;
	if (s == NULL)
		return (NULL);
	if ((size_t)start > ft_strxlen(s, '\0'))
		len = 0;
	else if (len > ft_strxlen(&s[start], '\0'))
		len = ft_strxlen(&s[start], '\0');
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (NULL);
	while (++i < len)
		p[i] = s[start + i];
	p[i] = '\0';
	return (p);
}
