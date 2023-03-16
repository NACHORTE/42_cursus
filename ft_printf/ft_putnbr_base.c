/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:29:37 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/16 20:29:37 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	unique_case(int nb, char *base, int len)
{
	int		aux;
	char	c;

	aux = nb % len;
	aux = -aux;
	c = base[aux];
	write(1, &c, 1);
}

static int	ok_base(char *base, int len)
{
	int		i;
	int		j;

	j = 1;
	i = 0;
	if (*base == '\0' || len == 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != '\0' || j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char			c;
	int				b_len;

	b_len = ft_strlen(base);
	if (!ok_base(base, b_len))
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(nbr / b_len, base);
		unique_case(nbr, base, b_len);
	}
	else if (nbr < 0)
	{
		write(1, &"-", 1);
		nbr = -nbr;
	}
	if (nbr >= b_len)
	{
		ft_putnbr_base(nbr / b_len, base);
	}
	nbr = nbr % b_len;
	c = base[nbr];
	write(1, &c, 1);
}
