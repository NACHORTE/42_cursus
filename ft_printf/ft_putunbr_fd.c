/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:48:54 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/16 20:48:54 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

int	ft_putunbr_int(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd((char)(n + '0'), fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	return (ft_count(n));
}
