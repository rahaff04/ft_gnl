#include "get_next_line.h"

char    *read_toleft (int fd, char *leftstr)
{
    char    *buff;
    size_t     bytes;
    char    *tmp;

    buff = malloc (BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    bytes = 1;
    while (!ft_strchr(leftstr, '\n') && bytes != 0)
    {
        bytes = read (fd, buff, BUFFER_SIZE);
        if (bytes == -1)
        {
            free (buff);
            return (NULL);
        }
        buff[bytes] = '\0';
        tmp = ft_strjoin(leftstr, buff);
        free (leftstr);
        leftstr = tmp;
    }
    free (buff);
    return (leftstr);
}

char    *getline (char *leftstr)
{
    size_t     i;
    char    *line;

    if (!leftstr)
        return (NULL);
    i = 0;
    while (leftstr[i] && leftstr[i] != '\n')
        i++;
    if (leftstr[i] == '\n')
        i++;
    line = malloc (i + 1);
    if (!line)
        return (NULL);
    ft_strlcpy(line, leftstr, i + 1);
    return (line);
}

char    *newleftstr(char *leftstr)
{
    size_t      i;
    char    *newstr;

    i  = 0;
    while (leftstr[i] && leftstr[i] != '\n')
        i++;
    if (!leftstr[i]) 
    {
        free(leftstr);
        return NULL;
    }
    i++;
    newstr = ft_strdup (leftstr + i);
    free (leftstr);
    return (leftstr);
}
char	*get_next_line(int fd)
{   
    static char   *leftstr;
    char  *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    leftstr = read_toleft(fd, leftstr);
    if (!leftstr)
        return NULL;
    line = getline(leftstr);
    leftstr = newleftstr(leftstr);
    return (line);
}

int main(void)
{
    int fd;
    char    *line;

    fd = open("rahaf.txt", O_RDONLY);
    if (fd < 0)
    {
        printf ("error in open");
        return (1);
    }
    line = get_next_line(fd);   
   // while (line != NULL)
   // {
        printf ("%s", line);
     //   line = get_next_line (fd);
    //}
   

    return (0);
}