/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:31:02 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/11/01 23:42:14 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strl(const char *str)
{
	size_t	i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	if (!(dest = malloc(sizeof(char) * (ft_strl(src) + 1))))
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((!s1 && !s2) || !s1)
		return (0);
	if (!(p = malloc(sizeof(char *) * (ft_strl(s1) + ft_strl(s2) + 1))))
		return (0);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i++] = s2[j];
		j++;
	}
	p[i] = '\0';
	return (p);
}

char		*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str && *str != (char)c)
		str++;
	if (*str == c)
		return (str);
	return (0);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strl(s))
		return (0);
	if (!(p = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len && s[start + i])
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
