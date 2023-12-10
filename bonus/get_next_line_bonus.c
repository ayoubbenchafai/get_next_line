/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:32:21 by aben-cha          #+#    #+#             */
/*   Updated: 2023/12/10 18:00:09 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char *ft_get_line(char *s)
{
    int i = 0;
    char *line;
    
    if(!s[i])
        return (NULL);
    while(s[i] && s[i] != '\n')
        i++;
    i += (s[i] == '\n');
    line = malloc(i + 1);
    if(!line)
     return (free(line),NULL);
    int j = 0;
    while(s[j] && s[j] != '\n')
    {
        line[j] = s[j];
        j++;
    }
    if(s[j] && s[j] == '\n')
        line[j++] = '\n';
    line[j] = '\0';
    return (line);
}
static char *ft_read(char *s, int fd)
{
    int cr;
    char *buf;
    char *p = NULL;
    buf = malloc(BUFFER_SIZE + 1);
    if(!buf)
        return (free(s),NULL);
    cr = read(fd, buf, BUFFER_SIZE);
    while(cr)
    {
        if(cr == -1)
            return (free(buf), NULL);
        buf[cr] = '\0';
        p = s;
        s = ft_strjoin(s, buf);
        free(p);
        p = NULL;
        if(!s)
            return (free(buf), NULL);
        if(ft_check_line(s,'\n'))
            break;
        cr = read(fd, buf, BUFFER_SIZE);
    }
    free(buf);
    return (s);
}

static char *ft_set_pointer(char *s)
{
    int j = 0;
    int i;
    char *res;
    
    i = 0;
    while(s[i] && s[i] != '\n')
        i++;
    i += (s[i] == '\n');
    if(!s[i])
            return (free(s), NULL);        
    j = ft_strlen(s) - i;
    res = malloc(j + 1);
    if(!res)
        return (NULL);
    j = 0;
    while(s[i])
        res[j++] = s[i++];
    res[j] = '\0';
    free(s);
    return (res);
}

char    *get_next_line(int fd)
{
    char *line;
    static char *s[3];
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(s);
        s[fd] = NULL;
        return NULL;
    }
    s[fd] = ft_read(s[fd], fd);
    if(!s[fd])  
        return (NULL);
    line = ft_get_line(s[fd]);
    s[fd] = ft_set_pointer(s[fd]);
    return (line);    
}