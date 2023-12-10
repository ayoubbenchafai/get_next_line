#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY | O_CREAT);
    int fd2 = open("file2.txt", O_RDONLY | O_CREAT);
    int fd3 = open("file3.txt", O_RDONLY | O_CREAT);
    return (0);
}