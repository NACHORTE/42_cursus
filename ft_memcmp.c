/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:39:23 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/07 16:04:03 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				aux;
	const unsigned char	*a1;
	const unsigned char	*a2;

	a1 = s1;
	a2 = s2;
	if (n == 0)
		return (0);
	aux = 0;
	while (*a1 != '\0' && (*a1 == *a2) && (aux < n - 1))
	{
		a1++;
		a2++;
		aux++;
	}
	return (*a1 - *a2);
}
