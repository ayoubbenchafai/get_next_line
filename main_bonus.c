#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    int fd3 = open("file3.txt", O_RDONLY);


    char *s;
    int tab[3] = {fd1, fd2, fd3};
    int i = 0;
    while((s = get_next_line(tab[i])))
    {
        i++;
            if(i == 3)
                i = 0;
        printf("%s",s);
        free(s);
    }
    
    return (0);
}