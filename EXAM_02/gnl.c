#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    int i = 0;
    int rd = 0;
    char ch;
    char *buffer = malloc(10000);

    while ((rd = read(fd, &ch, 1)) > 0)
    {
        buffer[i++] = ch;
        if (ch == '\n')
            break;
    }
    if ((!buffer[i - 1] && !rd) || rd == -1)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] =  '\0';
    return(buffer);
}
