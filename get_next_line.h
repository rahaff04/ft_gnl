/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 08:58:55 by ralamair          #+#    #+#             */
/*   Updated: 2025/09/21 13:26:43 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
size_t  ft_strlen(char *s);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
