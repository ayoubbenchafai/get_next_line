/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:58:32 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/30 22:40:24 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_check_line(const char *s, char c)
{
    while(*s)
    {
        if(*s == c)
            return (1);
        s++;    
    }
    return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*tab;

	i = 0;
	tab = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    int j;
    int size;
    char *tab;

    if(!s1)
        return (ft_strdup(s2));
    if(!s2)
        return (NULL);
    i = 0;
    j = 0;
    size = ft_strlen(s1) + ft_strlen(s2);
    tab = malloc(size + 1);
    if(!tab)
        return (NULL);
    while(i < ft_strlen(s1))
    {
        tab[i] = s1[i];
        i++;
    }
    while(i < size)
        tab[i++] = s2[j++];
    tab[i] = '\0';
    return (tab);
}
//ayoub ben chafai\nhatim
char *ft_get_line(char *s)
{
    int i;
    int size;
    char *line;

    i = 0;
    while(s[i] && s[i] != '\n')
        i++;
    i += (s[i] == '\n');
    size = i;
    line = malloc(size + 1);
    if(!line)
        return (NULL);
    i = 0;
    while(i < size)
    {
        line[i] = s[i];
        i++;
    }
    if(s[i] == '\n')
    {
        line[i] = s[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char *ft_set_pointer(char *s)
{
    int i =0;
    int j =0;
    char *res;

    while(s[i] && s[i] != '\n')
        i++;
    i += (s[i] == '\n');
    while(s[i + j])
        j++;
    res = malloc(j + 1);
    if(!res)
        return (NULL);
    j = 0;
    while(s[i])
        res[j++] = s[i++];
    res[j] = '\0';
    free(s);
    s = res;
    return (s);
}

static char *ft_read_save(char *str, int fd)
{
    int cr;
    char *buf;

    buf = malloc(BUFFER_SIZE + 1);
    if(!buf)
        return (NULL);
    while((cr = read(fd, buf, BUFFER_SIZE)))
    {
        if(cr == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[cr] = '\0';
        str = ft_strjoin(str, buf);
        if(ft_check_line(str, '\n'))
           break;
    }
    free(buf);
    return (str);
}

char *get_next_line(int fd)
{
    char *line;
    static char *str = NULL;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = ft_read_save(str, fd);
    if(!str)
        return (NULL);
    line = ft_get_line(str);
    str = ft_set_pointer(str);
    return (line);
}


#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    if(fd < 0)
        return (-1);
    char *line = get_next_line(fd);

    printf("%s\n", line);

    free(line);

    line = get_next_line(fd);

    printf("%s\n", line);

    free(line);


    line = get_next_line(fd);

    printf("%s\n", line);

    free(line);


    line = get_next_line(fd);

    printf("%s\n", line);

    free(line);
    return(0);
}
