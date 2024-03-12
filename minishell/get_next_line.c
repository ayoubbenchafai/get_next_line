#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    return (i);
}
char    *ft_strdup(const char *s)
{
    int i;
    int size;
    char *tmp;
    
    i = 0;
    size= ft_strlen(s);
    tmp = malloc(size + 1);
    if(!tmp)
        return (NULL);
    while(s[i])
    {
        tmp[i] = s[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}
int     ft_check(const char *s, char c)
{
    while(*s)
    {
        if(*s == c)
            return (1);
        s++;
    }
    return (0);
}
char	*ft_strjoin(char *s1, const char *s2)
{
    int i;
    char *tmp;
    int size;
    int size_s1;
    int size_s2;

    if(!s1)
        return (ft_strdup(s2));
    if(!s2)
        return (NULL);
    if(!s1 && !s2)
        return (NULL);
    size_s1= ft_strlen(s1);
    size_s2 = ft_strlen(s2);
    size = size_s1 + size_s2 + 1;
    tmp = malloc(size + 1);
    if(!tmp)
        return (NULL);
    i = 0;
    while(i < size_s1)
    {
        tmp[i] = s1[i];
        i++;
    }
    int j = 0;
    while(i < size)
    {
        tmp[i] = s2[j];
        i++;
        j++;
    }
    tmp[i] = '\0';
    return (tmp);
}
char    *ft_free_join(char *s1, const char *s2)
{
    char *tmp;

    tmp = ft_strjoin(s1, s2);
    free(s1);
    return (tmp);
}
static char *ft_read(char *s, int fd)
{
    int c;
    char *buffer;

    buffer = malloc((size_t)BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    c = read(fd, buffer, BUFFER_SIZE);
    while(c)
    {
        if(c < 0)
            return (free(buffer), free(s), NULL);
        buffer[c] = '\0';
        s = ft_free_join(s, buffer);
        if(!s)
            return (free(buffer), NULL);
        if(ft_check(s, '\n'))
            break;
        c = read(fd, buffer, BUFFER_SIZE);
    }
    free(buffer);
    return (s);
}
static char *get_line(char *s)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	i += (s[i] == '\n');
    int size =i;
	line = malloc(i + 1);
	if (!line)
		return (free(line), free(s), NULL);
	i = -1;
    while(++i < size)
        line[i] = s[i];
    line[i] = '\0';
    return (line);
}
static char *set_pointer(char *s)
{
    int     i;
    int     size;
    char    *r;

    i = 0;
    while(s[i] && s[i] != '\n')
        i++;
    i += (s[i] == '\n');
    if(!s[i])
        return (free(s), NULL);
    size = ft_strlen(s) - i;
    r = malloc(size + 1);
    if(!r)
        return (free(s), NULL);
    int j = 0;
    while(j < size)
        r[j++] = s[i++];
    r[j] = '\0';
    free(s);
    return (r);
}
char	  *get_next_line(int fd)
{
    static char *s;
    char *tmp;

    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        if(s)
            free(s);
        s = NULL;
        return (NULL);
    }
    s = ft_read(s, fd);
    if(!s)
        return (NULL);
    tmp = get_line(s);
    if(!tmp)
        return (s = NULL, NULL);
    s = set_pointer(s);
    return (tmp);
}
int main()
{
    
    int fd = open("doc", O_RDWR);

    char *s;

    while((s = get_next_line(fd)))
    {
        printf("%s",s);
        free(s);
    }
    return (0);
}