/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyepremy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:19:53 by vyepremy          #+#    #+#             */
/*   Updated: 2024/03/17 17:14:08 by vyepremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

ssize_t	read_buf(int fd, char *buf)
{
	ssize_t	size;

	size = read(fd, buf, BUFFER_SIZE);
	buf[size] = '\0';
	return (size);
}

char	*update_line(char *line, char *remainder)
{
	char	*tmp;

	tmp = ft_strchr(remainder, '\n');
	*tmp = '\0';
	line = ft_strjoin_free(line, remainder);
	line = ft_strjoin_free(line, "\n");
	ft_memmove(remainder, tmp + 1, BUFFER_SIZE - (tmp - remainder));
	return (line);
}
char	*ft_strjoin_free(char *s1, char *s2)
{
	char    *ret;
	size_t  s1_len;
	size_t  s2_len;

	if (!s2)
		return (s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(s1_len + s2_len + 1);
	if (!ret)
		return (NULL);
	ft_memmove(ret, s1, s1_len);
	ft_memmove(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	free(s1);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		size;

	line = NULL;
	if (fd > OPEN_MAX - 1 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!remainder[0])
		size = read_buf(fd, remainder);
	while (remainder[0])
	{
		if (ft_strchr(remainder, '\n'))
		{
			line = update_line(line, remainder);
			break ;
		}
		else
		{
			line = ft_strjoin_free(line, remainder);
			size = read_buf(fd, remainder);
		}
	}
	return (line);
}
