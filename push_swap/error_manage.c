/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:02:40 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/03 00:02:40 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static long long	ft_atoi_long(const char *str)
{
	long long	num;
	long long	neg;

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

static int	error_msg(void)
{
	write(1, &"Error\n", 6);
	return (1);
}

static int	is_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
		j++;
		}
		i++;
	}
	return (0);
}

int	check_error(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc <= 1)
		return (error_msg());
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit((int) argv[i][j++]))
				return (error_msg());
		}
		if (ft_strlen(argv[i]) > 11 || ft_strlen(argv[i]) == 0)
			return (error_msg());
		if (ft_atoi_long(argv[i]) > INT_MAX || ft_atoi_long(argv[i]) < INT_MIN)
			return (error_msg());
		i++;
	}
	if (is_dup(argc, argv))
		return (error_msg());
	return (0);
}
