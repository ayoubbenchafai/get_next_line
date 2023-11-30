#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
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

char *ft_set_pointer(char *str)
{
    int i;
    int l;
    int k;
    char *rest;
    
    i = 0;
    l = 0; 
    k = 0;
    while(str[i] && str[i] != '\n')
        i++;
    i += (str[i] == '\n');
    while(str[l + i])
        l++;
    rest = malloc((l + 1) * sizeof(char));
    if(!rest)
        return (NULL);
   
    while(str[k])
        rest[k] = str[i];
    rest[k] = '\0';
    free(str);
    str = rest;
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


char *get_next_line(int fd)
{
    char *line;
    static char *str;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = ft_read_save(fd,str);
    if(!str)
        return (NULL);
    line = get_line(str);
    // str = ft_set_pointer(str);
    return (line);   
}
int main()
{
    int fd = 0;

    fd = open("file.txt", O_RDONLY);
    if(fd < 0)
        return (-1);
    char *s = get_next_line(fd);

    printf("%s",s);

    free(s);
    // s= NULL;
    // s = get_next_line(fd);

    // printf("%s",s);
    
    return (0);
}