#include "get_next_line_bonus.h"



t_fd	*find_fd(t_fd **head, int fd)
{
    t_fd *curr;
    t_fd *new;

    curr = *head;
    while (curr)
    {
        if (curr -> fd == fd)
            return (curr);
        curr = curr -> next;
    }
    new = malloc(sizeof(t_fd));
    if (!new)
        return (NULL);
    new -> fd = fd;
    new -> leftstr = NULL;
    new -> next = *head;
    *head = new;
    return (new);
}

void	freefd(t_fd **head, int fd)
{
    t_fd *curr;
    t_fd *prev;

    curr = *head;
    prev = NULL;
    while (curr)
    {
        if (curr -> fd == fd)
        {
            if (prev)
                prev -> next = curr -> next;
            else
                *head = curr -> next;
            if (curr -> leftstr)
                free(curr -> leftstr);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr -> next;
    }
}

char	*get_next_line(int fd)
{
    static t_fd *head;
    t_fd *curr;
    char	*line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    curr = find_fd(&head, fd);
    if (!curr)
        return (NULL);
    curr -> leftstr = read_toleft(fd, curr -> leftstr);
    if (!curr -> leftstr)
        return (NULL);
    line = gettline(curr -> leftstr);
    if (!line)
    {
        freefd(&head, fd);
        return (NULL);
    }
    curr -> leftstr = newleftstr(curr -> leftstr);
    if (!curr -> leftstr)
        freefd(&head, fd);
    return (line);
}
