#include "get_next_line.h"

char	*freee(char *str)
{
	free(str);
	return (NULL);
}

char	*read_toleft(int fd, char *leftstr)
{
	char	*buff;
	char	*tmp;
	ssize_t	bytes;

	bytes = 1;
	if (!leftstr)
		leftstr = ft_strdup("");
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (freee(leftstr));
	while (!ft_strchr(leftstr, '\n') && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buff);
			return (freee(leftstr));
		}
		buff[bytes] = '\0';
		tmp = ft_strjoin(leftstr, buff);
		if (!tmp)
		{
			free(buff);
			return (freee(leftstr));
		}
		free(leftstr);
		leftstr = tmp;
	}
	free(buff);
	return (leftstr);
}

char	*gettline(char *leftstr)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!leftstr || !*leftstr)
		return (NULL);
	while (leftstr[i] && leftstr[i] != '\n')
		i++;
	if (leftstr[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, leftstr, i + 1);
	return (line);
}

char	*newleftstr(char *leftstr)
{
	size_t	i;
	char	*newstr;

	i = 0;
	if (!leftstr)
		return (NULL);
	while (leftstr[i] && leftstr[i] != '\n')
		i++;
	if (!leftstr[i])
		return (freee(leftstr));
	newstr = ft_strdup(leftstr + i + 1);
	free(leftstr);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*leftstr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftstr = read_toleft(fd, leftstr);
	if (!leftstr)
		return (NULL);
	line = gettline(leftstr);
	if (!line)
	{
		free(leftstr);
		leftstr = NULL;
		return (NULL);
	}
	leftstr = newleftstr(leftstr);
	return (line);
}