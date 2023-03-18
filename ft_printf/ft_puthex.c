/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:31:01 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/18 17:36:09 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static char	*ft_rev(char *str)
{
	int		i;
	char	a;

	i = 0;
	while (i < ((int) ft_strlen(str) / 2))
	{
		a = str[ft_strlen(str) - 1 - i];
		str[ft_strlen(str) - 1 - i] = str[i];
		str[i] = a;
		i++;
	}
	return (str);
}*/

static int	ft_write0(void)
{
	write (1, "0", 1);
	return (1);
}

int	ft_puthex(unsigned int nbr, char a)
{
	char	*hex_digits;
	int		i;
	int		j;
	char	result[20];
	int		z;

	if (nbr == 0)
		return (ft_write0());
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
