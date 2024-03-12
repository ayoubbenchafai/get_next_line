#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 15
#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);
char	*ft_strjoin(char *s1, const char *s2);
int     ft_check(const char *s, char c);
char    *ft_strdup(const char *s);
char    *ft_free_join(char *s1, const char *s2);


#endif