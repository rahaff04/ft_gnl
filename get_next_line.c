/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:31:01 by ralamair          #+#    #+#             */
/*   Updated: 2025/09/28 14:25:00 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freee(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

char	*read_toleft(int fd, char *leftstr, int bytes)
{
	char	*buff;
	char	*tmp;

	if (!leftstr)
		leftstr = ft_strdup("");
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (freee(leftstr));
	while (!ft_strchr(leftstr, '\n') && bytes > 2)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(leftstr);
			return (freee(buff));
		}
		buff[bytes] = '\0';
		tmp = ft_strjoin(leftstr, buff);
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

	if (!leftstr)
		return (NULL);
	i = 0;
	while (leftstr[i])
	{
		i++;
		if (leftstr[i] == '\n')
			break ;
	}
	i++;
	line = malloc(i + 1);
	if (!line)
		return (freee(leftstr));
	ft_strlcpy(line, leftstr, i + 1);
	return (line);
}

char	*newleftstr(char *leftstr)
{
	size_t	i;
	char	*newstr;

	i = 0;
	while (leftstr[i])
	{
		if (leftstr[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (!leftstr[i])
		return (freee(leftstr));
	i++;
	newstr = ft_strdup(leftstr + i);
	free(leftstr);
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*leftstr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftstr = read_toleft(fd, leftstr, 1);
	if (!leftstr || leftstr[0] == '\0')
		return (freee(leftstr));
	line = gettline(leftstr);
	if (!line)
		return (line);
	leftstr = newleftstr(leftstr);
	return (line);
}

int	main(void)
 {
	int		fd;
	char	*line;

	fd = open("rahaf.txt", O_RDONLY);
	line = get_next_line(0);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(0);
	return (0);
}
