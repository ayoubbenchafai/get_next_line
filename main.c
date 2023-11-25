#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
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

size_t ft_strlen(char *str)
{
    int len  =0;
    while(*str)
    {
        str++;
        len++;
    }
    return (len);
}

char	*ft_strncat(char *dest, char *src,size_t nb)
{
	size_t	i;
	size_t	size_dest;

	i = 0;
	size_dest = ft_strlen(dest);
	while (src[i] != '\0' && i < nb)
		dest[size_dest++] = src[i++];
	dest[size_dest] = '\0';
	return (dest);
}

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
        if(!ft_strchr(buf, '\n'))
        {
          i++;
          str = strncat(str, buf,cr);
          line = malloc((BUFFER_SIZE) + 1);
          line = strcpy(line,str);
         
        }
        else break;
        free(str);
    }
    printf("%s\n",line);
    //printf("len  = %zu",strlen(line));
    return (0);
}
