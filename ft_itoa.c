/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:45:02 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/13 12:02:48 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numbers(int n)
{
	int	total;

	if (n < 0)
		n = -n;
	total = 0;
	while (n > 9)
	{
		n = n / 10;
		total++;
	}
	return (total + 1);
}

static char	*ft_uniquecase(char *str)
{
	str = (char *)malloc(12);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

static char	*ft_fill(char *num, int n, int i, int numbers)
{
	num[numbers] = '\0';
	while (numbers != i)
	{
		num[numbers - 1] = (n % 10) + '0';
		n = n / 10;
		numbers--;
	}
	return (num);
}

static char	*ft_isnegative(int n, int *i, char *num)
{
	int	numbers;

	if (n == -2147483648)
		return (ft_uniquecase(num));
	if (n < 0)
	{
		n = -n;
		numbers = ft_numbers(n);
		num = malloc(sizeof(char) * ++numbers + 1);
		*i = 1;
	}
	else
	{
		numbers = ft_numbers(n);
		num = malloc(sizeof(char) * numbers + 1);
		*i = 0;
	}
	if (num == 0)
		return (0);
	if (*i == 1)
		num [0] = '-';
	return (ft_fill(num, n, *i, numbers));
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;

	num = NULL;
	num = ft_isnegative(n, &i, num);
	return (num);
}
