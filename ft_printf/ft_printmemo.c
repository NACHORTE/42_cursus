/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:11:53 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/17 15:49:40 by iortega-         ###   ########.fr       */
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

static int	ft_puthex_long(long int nbr, char a)
{
	char	*hex_digits;
	int		i;
	int		j;
	char	result[64];
	char	*final;

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
	ft_putstr_fd(result, 1);
	return (i);
}

int	ft_printmemo(long int memo)
{
	int	i;

	write (1, "0x", 2);
	i = ft_puthex_long(memo, 'x');
	return (i + 2);
}
