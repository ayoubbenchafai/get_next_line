#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <errno.h>
#include <string.h>

void f1()
{
    system("leaks a.out");
}
int main()
{

    int fd = open("file.txt", O_RDONLY);
    char *s;

    s = malloc((size_t)2147483648 + 1);
    if (s)
        printf("s is allocated\n");

    ssize_t t = read(1, s, (size_t)(INT_MAX) + 1);
    printf("error : %s\n", strerror(errno));
    //ssize_t t = 0;
    printf("%zd, %lu\n", t, (size_t)(INT_MAX) +1 );
    // s = get_next_line(fd);
    // printf("%s",s);
    // free(s);
    // s = NULL;

    // s = get_next_line(fd);
    // printf("%s",s);
    // free(s);
    // s = NULL;

    
    
//    atexit(f1);
}
//ayoub\nhatim