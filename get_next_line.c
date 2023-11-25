/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:12:50 by aben-cha          #+#    #+#             */
/*   Updated: 2023/11/25 19:43:48 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 15

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)(s));
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s));
	return (NULL);
}
char *get_next_line(int fd)
{
    int cr;
    char buf[BUFFER_SIZE];
    static char *str;
    char *line;
    int i = 0;

    fd = open("file.txt", O_RDONLY);
    while((cr = read(fd, buf, 15)))
    {
        if(cr == -1)
        {
            return (NULL);
            break;
        }
        str = malloc(cr + 1);
          if(!str)
            return NULL;
        if(!ft_strchr(buf, '\n'))
        {
          i++;
          str = strncat(str, buf,cr);
          line = malloc((BUFFER_SIZE) + 1);
          line = strcpy(line,str);
         
        }
        else break;
        free(str);
        bzero(buf,BUFFER_SIZE);
    }
    return (line);
}

int main()
{
    int fd = open("file.txt", O_RDONLY);
    char *s = get_next_line(fd);

    printf("%s",s);
    printf("\nlen de line =%zu",strlen(s));
}
// int main (void)
// {
//     int fd;
//     int cr;
//     char buf[15];
//     static char *stash;
//     fd = open("file.txt", O_RDONLY);
//     if(fd < 0)
//        return (-1);
       
//     cr = read(fd,buf,10);
//     if(cr < 0)
//        return (-1);
//     stash = malloc(cr + 1);
//     stash = buf;
//     stash[cr] = '\0';
//     printf("%s",stash);
//     //-------
//    // memset(buf, 0,cr);
//     if( BUFFER_SIZE < cr)
//      bzero(buf, cr);
//     cr = read(fd,buf,10);
//     if(cr < 0)
//        return (-1);
//     stash = malloc(cr + 1);
//     stash = buf;
//     stash[cr] = '\0';
//     printf("%s",stash);

//     cr = read(fd,buf,10);
//     if(cr < 0)
//        return (-1);
//     stash = malloc(cr + 1);
//     stash = buf;
//     stash[cr] = '\0';
//     printf("%s",stash);
//     //--------
//     //  cr = read(fd,buf,10);
//     // stash = malloc(cr + 1);
//     // stash = buf;
//     // stash[cr] = '\0';
//     // printf("%s\n",stash);
     

//     // if(size_buffer < rc)
//       //bzero(buf)
//     return (0);
// }


/*

int main (void)
{
    int fd;
    int cr;
    char buf[BUFFER_SIZE];
    static char *str;
    char *line;
    int i = 0;
    fd = open("file.txt", O_RDONLY);

    while((cr = read(fd, buf, 15)))
    {
        if(cr == -1)
        {
            return (-1);
            break;
        }
        str = malloc(cr + 1);
          if(!str)
            return -1;
        if(ft_strchr(buf, '\n') == NULL)
        {
          i++;
          str = strncat(str, buf,cr);

          
        //printf("%s",str);
        //printf("line : %zu",ft_strlen(str));
        }
        else break;

        
         line = malloc((BUFFER_SIZE) + 1);
         line = strncat(str, buf,BUFFER_SIZE);


    }
    
    return (0);
}
*/


