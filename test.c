/*#include "get_next_line.h"

int main ()
{
    int fd = open("rahaf.txt", O_RDONLY);
    if (fd < 0)
    {
        printf ("open error ");
        return (1);
    }
    char *s = malloc (BUFFER_SIZE + 1);
    int by = read (fd, s, BUFFER_SIZE);
    printf ("%d\n", by);
    printf ("%s",s);

    return (0);
}*/