#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

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

// line = get_line(stash)
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
    if(s[i] == '\n')
    {
        str[i] = s[i];
        i++;
    }
    str[i]  = '\0';   
    return (str);    
}



// char *ft_save_into_stash(char *buf,int fd)
// {
//     char *str;
//     int chars_read;
//     str = malloc(BUFFER_SIZE + 1);
//     if(!str)
//         return (NULL);
//     int cr = 1;
//     while()    
// }
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	int		j;
	size_t	size;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s1)
		return (strdup(s2));
	size = strlen(s1) + strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i < size)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
int main() 
{
    int fd;
    int cr = 1;
    static char *str;
    char *buf;
    char *line = "";

    fd = open("file.txt", O_RDONLY);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (-1);
    buf =  malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buf)
        return (-1);
    int i = 0;
    while((cr = read(fd, buf, BUFFER_SIZE)))
    {
        if(cr == -1)
        {
            free(buf);
            return (-1);
        }
        
        buf[cr] = '\0';

        str = ft_strjoin(str, buf);
        if(check_line(str,'\n'))
            break ;
    }
    line = get_line(str);
    while (str[i] && str[i] != '\n')
        i++;
    i += (str[i] == '\n');
    int l = 0;
    char *rest;
    while (str[l + i])
        l++;
    rest = malloc(l + 1);
    l = 0;
    while (str[l + i])
    {
        rest[l] = str[l + i];
        l++;
    }
    rest[l] = 0;
    free(str);
    str = rest;
    printf("%s", line);
    free(buf);

    //printf("%s",str);
         
    return 0;
}