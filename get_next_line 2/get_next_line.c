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

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*tab;

	i = 0;
	tab = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2) 
{
	size_t	i;
	int		j;
	size_t	size;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i < size)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

int check_line(char *s, char c)
{
    while(*s)
    {
        if(*s == c)
            return (1);
        s++;
    }
    return (0);
}

//mzl lblan dial ila makansh new line andir i + 1
 char *get_line(char *s)
{
    int i;
    int j;
    char *str;
    
    i = 0;
    j = 0;
    while(s[i] != '\0' && s[i] != '\n')
        i++;
    str = malloc(i + 2);
    if(!str)
        return (NULL);
    while(j < i)
    {
        str[j] = s[j];
        j++;
    }
    i += (str[i] == '\n');
    // if(s[i] == '\n')
    // {
    //     str[i] = s[i];
    //     i++;
    // }
    str[i]  = '\0';   
    return (str);    
}

char *ft_read_save(int fd, char *buf)
{
    int cr;
    char *str;
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
        if(check_line(buf, '\n'))
            break;
    }
    free(buf);
    return (str); 
}

 char *ft_set_pointer(char *str)
{
    int i;
    int k;
    int l;
    char *rest;
    
    i = 0; 
    k = 0; 
    l = 0;
    //Lorem ipsum dolor sit ame(t,\nco)
    while(str[i] && str[i] != '\n')
        i++;
    i += (str[i] == '\n');
    while(str[l + i])
        l++;
    rest = malloc(l + 1);
    if(!rest)
        return (NULL);
    while(str[i])
        rest[k++] = str[i++];
    rest[k] = '\0';
    free(str);
    str = rest;
    return (str);
}

char *get_next_line(int fd)
{
    char *line;
    static char *str;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = ft_read_save(fd, str);
    if(!str)
        return (NULL);
    line = get_line(str);
    str = ft_set_pointer(str);  
    return (line);
}

#include <stdio.h>

int main()
{
    int fd =0;
    fd = open("file.txt", O_RDONLY);
    char *s = get_next_line(fd);
    
    printf("%s",s);
    free(s);
}