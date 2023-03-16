/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:46:20 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/13 12:44:22 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	aux;

	if (n == 0)
		return (0);
	aux = 0;
	while (*s1 != '\0' && (*s1 == *s2) && (aux < n - 1))
	{
		s1++;
		s2++;
		aux++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
