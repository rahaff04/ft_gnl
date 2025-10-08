/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:36:12 by ralamair          #+#    #+#             */
/*   Updated: 2025/10/08 14:03:35 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	freee(char *str, char *str2)
{
	free(str);
	free(str2);
}

char	*read_toleft(int fd, char *leftstr, int byte)
{
	char	*buff;
	char	*tmp;

	if (!leftstr)
		leftstr = ft_strdup("");
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		free(leftstr);
		return (NULL);
	}
	while (!ft_strchr(leftstr, '\n') && byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte < 0)
		{
			freee(buff, leftstr);
			return (NULL);
		}
		buff[byte] = '\0';
		tmp = ft_strjoin(leftstr, buff);
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
	{
		free(leftstr);
		return (NULL);
	}
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
	leftstr = read_toleft(fd, leftstr, 1);
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
