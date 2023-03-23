/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:14:39 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/23 12:14:39 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		bytes = read(fd, reading, BUFFER_SIZE);
		reading[bytes] = '\0';
		buff = ft_strjoin(buff, reading);
	}
	free(reading);
	return (buff);
}

char	*ft_cut_line(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	if (*buff == 0)
		return (NULL);
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
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
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\0')
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
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	buff = ft_read_buff(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_cut_line(buff);
	buff = ft_next(buff);
	return (line);
}
