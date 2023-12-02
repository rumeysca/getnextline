/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcan <rcan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:25:15 by rcan              #+#    #+#             */
/*   Updated: 2023/12/02 19:59:34 by rcan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readlines(int fd, char *src)
{
	int		readb;
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
	static char	*src;
	char		*prnt;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	src = ft_readlines(fd, src);
	if (!src)
	{
		return (NULL);
	}
	prnt = ft_getline(src);
	src = ft_getget(src);
	return (prnt);
}
/*
#include<fcntl.h>
#include<stdio.h>
int main()
{
	int fd = open("a.txt", O_RDONLY);
	char *str;
	int x = 0;
	while (x < 4)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		x++;
		//system("leaks a.out");
	}
}
*/
