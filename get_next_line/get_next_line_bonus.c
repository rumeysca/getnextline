/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:58:50 by rcan              #+#    #+#             */
/*   Updated: 2023/12/04 18:46:55 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readlines(int fd, char *src)
{
	ssize_t	readb;
	char	*buff;

	readb = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		return (NULL);
	}
	while (!ft_strchr(src, '\n') && readb != 0)
	{
		readb = read(fd, buff, BUFFER_SIZE);
		if (readb == -1)
		{
			free(buff);
			free(src);
			return (NULL);
		}
		buff[readb] = '\0';
		src = ft_strjoin(src, buff);
	}
	free(buff);
	return (src);
}

char	*get_next_line(int fd)
{
	static char	*src[10240];
	char		*prnt;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	src[fd] = ft_readlines(fd, src[fd]);
	if (!src[fd])
	{
		return (NULL);
	}
	prnt = ft_getline(src[fd]);
	src[fd] = ft_getget(src[fd]);
	return (prnt);
}
