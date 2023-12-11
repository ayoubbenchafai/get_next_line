/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:38:35 by aben-cha          #+#    #+#             */
/*   Updated: 2023/12/11 22:50:46 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_free(char *s, const char *buf)
{
	char	*r;

	r = ft_strjoin(s, buf);
	free(s);
	return (r);
}

static char	*ft_read(char *s, int fd)
{
	char	*buf;
	int		cr;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(s), NULL);
	cr = read(fd, buf, BUFFER_SIZE);
	while (cr)
	{
		if (cr == -1)
			return (free(buf), free(s), NULL);
		buf[cr] = '\0';
		s = ft_free(s, buf);
		if (!s)
			return (free(buf), free(s), NULL);
		if (ft_check_line(s, '\n'))
			break ;
		cr = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (s);
}

static char	*ft_get_line(char *s)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	i += (s[i] == '\n');
	line = malloc(i + 1);
	if (!line)
		return (free(line), free(s), NULL);
	while (s[j] && s[j] != '\n')
	{
		line[j] = s[j];
		j++;
	}
	if (s[j] && s[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char	*ft_set_pointer(char *s)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	i += (s[i] == '\n');
	if (!s[i])
		return (free(s), NULL);
	j = ft_strlen(s) - i;
	res = malloc(j + 1);
	if (!res)
		return (free(s), NULL);
	j = 0;
	while (s[i])
		res[j++] = s[i++];
	res[j] = '\0';
	free(s);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s[OPEN_MAX];

	if (fd > OPEN_MAX)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (s[fd])
			free(s[fd]);
		s[fd] = NULL;
		return (NULL);
	}
	s[fd] = ft_read(s[fd], fd);
	if (!s[fd])
		return (NULL);
	line = ft_get_line(s[fd]);
	if (!line)
		return (s[fd] = NULL, NULL);
	s[fd] = ft_set_pointer(s[fd]);
	return (line);
}
