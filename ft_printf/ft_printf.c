/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:56:29 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/16 18:56:29 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i++] == '%')
		{
			if (str[i] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (str[i] == 'i' || str[i] == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (str[i] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (str[i] == 'u')
				ft_putunbr_fd(va_arg(args, unsigned int), 1);
			else if (str[i] == 'x')
				ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
			else if (str[i] == 'X')
				ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
			else if (str[i] == '%')
				ft_putchar_fd(str[i], 1);
		}
		else
			ft_putchar_fd(str[i], 1);
	}
}
