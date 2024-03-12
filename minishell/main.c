#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 

int main()
{
    int fd[2];

    pipe(fd);
    execve("/bin/ls", (char *[]){"ls", "-la", NULL}, NULL);
    printf("%s\n", "hello world");
    return (0);
}