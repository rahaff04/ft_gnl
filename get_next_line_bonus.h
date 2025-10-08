#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typeof struct s_fd
{
    int		fd;
    char	*leftstr;
    struct s_fd *next;
}	t_fd;

char	*get_next_line(int fd);
t_fd	*find_fd(t_fd **head, int fd);
void	freefd(t_fd **head, int fd);
char	*read_toleft(int fd, char *leftstr);
char	*gettline(char *leftstr);
char	*newleftstr(char *leftstr);
char	*freee(char *str);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
#endif  