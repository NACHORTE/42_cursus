/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:31:01 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/18 15:17:19 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_rev(char *str)
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
}

int	ft_puthex(int nbr, char a)
{
	char	*hex_digits;
	int		i;
	int		j;
	char	result[10];
	char	*final;

	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
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
	result[i] = '\0';
	final = ft_rev(result);
	ft_putstr_fd(final, 1);
	return (i);
}
