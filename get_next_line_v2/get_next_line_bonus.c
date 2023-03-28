/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:51:14 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/28 23:17:46 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_buff(int fd, char *buff)
{
	int		bytes;
	char	*reading;

	reading = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!reading)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buff, '\n') && bytes != 0)
	{
		if (bytes == -1)
		{
			free(reading);
			return (NULL);
		}
		bytes = read(fd, reading, BUFFER_SIZE);
		if (bytes > 0)
		{
			reading[bytes] = '\0';
			buff = ft_strjoin(buff, reading);
		}
	}
	free(reading);
	reading = 0;
	if (!buff)
		return (0);
	return (buff);
}

char	*ft_cut_line(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_next(char *buff)
{
	int		i;
	int		j;
	char	*newbuff;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	newbuff = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!newbuff)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		newbuff[j++] = buff[i++];
	newbuff[j] = '\0';
	free(buff);
	return (newbuff);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*line;

	if (read(fd, 0, 0) < 0)
	{
		free (buff[fd]);
		buff[fd] = 0;
		return (0);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	buff[fd] = ft_read_buff(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = ft_cut_line(buff[fd]);
	buff[fd] = ft_next(buff[fd]);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>


int main(void)
{
    int fd;
    char *str;
	str = "hola";
    fd = open("texto.txt", O_RDONLY);

	while (1)
	{
		str = get_next_line(fd);
		if (str == 0)
			return (0);
    	printf("%s", str);
	}
    return 0;
}*/
