/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:56:39 by rthammat          #+#    #+#             */
/*   Updated: 2022/03/11 18:57:21 by rthammat         ###   ########.fr       */
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

char	*ft_strchr(const char *string, int searchedChar )
{
	char	*str;

	str = (char *)string;
	while (*str != searchedChar && *str != 0)
		str++;
	if (*str == searchedChar)
		return (str);
	else
		return (NULL);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;

	res = (char *)malloc(elementSize * elementCount);
	if (!res)
		return (NULL);
	while (elementCount > 0)
		res[elementCount--] = '\0';
	res[0] = '\0';
	return (res);
}

size_t	ft_strxlen(const char *theString, char delim)
{
	size_t	i;

	i = 0;
	while (theString[i] && theString[i] != delim)
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
