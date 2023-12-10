/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:58:32 by aben-cha          #+#    #+#             */
/*   Updated: 2023/12/10 19:22:49 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


#include <stdio.h>

// static int ft_get_len(const char *s)
// {
//     int i;
    
//     i = 0;
//     while(s[i] && s[i] != '\n')
//         i++;
//     i += (s[i] == '\n');
//     return (i);
// }

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
     return (free(line), free(s), NULL);
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
    char *p;
    
    p = NULL;
    buf = malloc(BUFFER_SIZE + 1);
    if(!buf)
        return (free(s),NULL);
    cr = read(fd, buf, BUFFER_SIZE);
    while(cr)
    {
        if(cr == -1)
            return (free(buf), free(s), NULL);
        buf[cr] = '\0';
        p = s;
        s = ft_strjoin(s, buf);
        free(p);
        p = NULL;
        if(!s)
            return (free(buf), free(s), NULL);
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
    //problem in s
    if(!res)
        return (free(s), NULL);
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
    static char *s;
        
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        if (s) // do not free NULL 
            free(s);
        s = NULL;
        return NULL;
    }
    s = ft_read(s, fd);
    if(!s)  
        return (NULL);
    line = ft_get_line(s);
    if (!line)
        return (s = NULL, NULL);
    s = ft_set_pointer(s);
    return (line);    
}

// what is offset
// static variable storage
// how to delete a file descriptor
// memory leak : fuite de memoire 