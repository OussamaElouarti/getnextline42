/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ouar <oel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:28:29 by oel-ouar          #+#    #+#             */
/*   Updated: 2019/11/02 14:08:28 by oel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlcpy(char *d, const char *s, size_t n)
{
	size_t			k;
	void			*dest;

	dest = d;
	k = ft_strl(s);
	if (n == 0)
		return (k);
	if (dest == NULL)
		return (0);
	if (n)
	{
		while (n - 1 > 0 && *s)
		{
			*(unsigned char *)dest++ = *(unsigned char *)s++;
			n--;
		}
	}
	*(unsigned char *)dest = '\0';
	return (k);
}

int			get_result(char **line, char **p, int i)
{
	char *s;
	char *temp;

	temp = *line;
	if (i == -1)
		return (-1);
	if (!(s = ft_strchr(*p, '\n')))
	{
		s = ft_strchr(*p, '\0');
		i = -1;
	}
	s++;
	if (!(*line = malloc(sizeof(char) * ((size_t)(s - *p) + 1))))
		return (-1);
	ft_strlcpy(*line, *p, (size_t)(s - *p));
	s = *p;
	free(temp);
	*p = ft_substr(*p, ft_strl(*line) + 1, ft_strl(*p) - ft_strl(*line) + 1);
	free(s);
	if ((i == -1) || *line)
		return ((i == -1) ? 0 : 1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char		*p;
	char			*ptr;
	char			*pp;
	int				i;

	if (BUFFER_SIZE < 0 || fd < 0 || line == NULL)
		return (-1);
	if (!(ptr = malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (p == NULL)
		p = ft_strdup("");
	*line = ft_strdup("");
	while (!ft_strchr(p, '\n') && (i = read(fd, ptr, BUFFER_SIZE)) > 0)
	{
		ptr[i] = '\0';
		pp = p;
		p = ft_strjoin(p, ptr);
		free(pp);
	}
	free(ptr);
	return (get_result(line, &p, i));
}
