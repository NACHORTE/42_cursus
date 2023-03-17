/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:31:01 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/17 00:31:01 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(int nbr, char a)
{
	char	*hex_digits;
	int		i;
	int		j;
	char	result[9];

	if (a == 'X')
		hex_digits = "0123456789ABCDEF";
	if (a == 'x')
		hex_digits = "0123456789abcdef";
	i = 0;
	while (nbr > 0)
	{
		j = nbr % 16;
		result[i++] = hex_digits[j];
		nbr = nbr / 16;
	}
	ft_putstr_fd(result, 1);
	return (i);
}
