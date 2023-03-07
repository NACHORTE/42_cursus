/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:51:36 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/07 13:03:42 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strl(char *dest)
{
	unsigned int	length;

	length = 0;
	while (dest[length] != '\0')
		length++;
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destl;
	unsigned int	srcl;
	unsigned int	aux;

	destl = ft_strl(dest);
	srcl = ft_strl(src);
	aux = -1;
	if (size == 0)
		return (srcl);
	if (destl >= size)
		return (destl + size);
	while (src[aux] != '\0' && aux < (size - 1 - destl))
	{
		dest[destl + aux] = src[aux + 1];
		aux++;
	}
	dest[aux] = '\0';
	return (destl + srcl);
}
