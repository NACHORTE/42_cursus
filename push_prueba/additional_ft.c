/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:41:18 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/19 14:34:02 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(const char *str)
{
	int	num;
	int	neg;

	neg = 1;
	num = 0;
	while (ft_isspace(*str) && *str != '\0')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	if (*str == '+' && neg == 1)
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (num * neg);
		else
			num = 10 * num + *str - '0';
		str++;
	}
	num = num * neg;
	return (num);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	aux;

	aux = 0;
	while (*str != '\0')
	{
		aux++;
		str++;
	}
	return (aux);
}

int	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (-2);
}
