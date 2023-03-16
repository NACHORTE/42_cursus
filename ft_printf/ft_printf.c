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

int	ft_cases(va_list *args, char id, int j)
{
	if (id == 'c')
		j = j + ft_putchar_int(va_arg(*args, int), 1);
	else if (id == 'i' || id == 'd')
		j = j + ft_putnbr_int(va_arg(*args, int), 1, 0);
	else if (id == 's')
		j = j + ft_putstr_int(va_arg(*args, char *), 1);
	else if (id == 'u')
		j = j + ft_putunbr_int(va_arg(*args, unsigned int), 1);
	else if (id == 'x')
		j = j + ft_putnbr_base(va_arg(*args, int), "0123456789abcdef");
	else if (id == 'X')
		j = j + ft_putnbr_base(va_arg(*args, int), "0123456789ABCDEF");
	else if (id == '%')
		j = j + ft_putchar_int(id, 1);
	return (j);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		printed;

	i = 0;
	printed = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i++] == '%')
		{
			printed = printed + ft_cases(&args, str[i], printed);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			printed++;
		}
	}
}
