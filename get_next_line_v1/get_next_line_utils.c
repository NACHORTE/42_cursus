/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:41:00 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/22 15:41:00 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	aux;

	aux = 0;
	while (*str != '\0')
	{
		aux++;
		str++;
	}
	return (aux);
}

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	destl;
	unsigned int	srcl;
	unsigned int	initial;
	char			*aux;

	destl = ft_strlen(dest);
	initial = destl;
	srcl = ft_strlen(src);
	if (size == 0)
		return (srcl);
	if (destl >= size)
		return (srcl + size);
	aux = dest + destl;
	while (*src != '\0' && destl < (size - 1) && size >= 2)
	{
		*aux = *src;
		aux++;
		src++;
		destl++;
	}
	if (size != 0)
		*aux = '\0';
	return (initial + srcl);
}

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	aux;
	unsigned int	counter;

	aux = 0;
	counter = 0;
	while (src[counter] != '\0')
		counter++;
	if (size != 0)
	{
		while (src[aux] != '\0' && aux < (size - 1))
		{
			dest[aux] = src[aux];
			aux++;
		}
		dest[aux] = '\0';
	}
	return (counter);
}

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dest;
	int		i;

	len = ft_strlen(src);
	i = 0;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == 0)
		return (dest);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		total;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	total = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * total + 1);
	if (str == 0)
		return (0);
	i = 0;
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, total + 1);
	return (str);
}
