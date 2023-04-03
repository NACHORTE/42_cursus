/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:09:19 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/22 13:09:19 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (0);
}

static char	*cut(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i + 1] = '\0';
			return (str);
		}
		i++;
	}
	return (str);
}

static int	end(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (0);
			str++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*str = "";
	char		temp[10];
	char		*aux;
	int			bytes;

	str = (str == NULL) ? ft_strdup("") : str;
	bytes = 1;
	if (!end(str))
	{
		str = ft_strchr(str, '\n');
		str++;
	}
	else
		str = ft_strchr(str, '\0');
	while (end(str) && bytes > 0)
	{
		bytes = read(fd, temp, 10);
		if (bytes == -1)
			break ;
		temp[bytes] = '\0';
		aux = ft_strjoin("", temp);
		str = ft_strjoin(str, aux);
		free(aux);
	}
	aux = ft_strdup(str);
	aux = cut(aux);
	return (aux);
}
