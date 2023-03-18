/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:11:53 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/18 16:53:34 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_long(unsigned long int nbr, char a)
{
	char	*hex_digits;
	int		i;
	int		j;
	char	result[20];
	int		z;
	result[19] = '\0';
	if (a == 'X')
		hex_digits = "0123456789ABCDEF";
	if (a == 'x')
		hex_digits = "0123456789abcdef";
	i = 18;
	z = 0;
	while (nbr > 0)
	{
		j = nbr % 16;
		result[i--] = hex_digits[j];
		nbr = nbr / 16;
		z++;
	}
	ft_putstr_fd(&result[i + 1], 1);
	return (z);
}

int	ft_printmemo(unsigned long int memo)
{
	int	i;

	if (memo == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write (1, "0x", 2);
	i = ft_puthex_long(memo, 'x');
	return (i + 2);
}
