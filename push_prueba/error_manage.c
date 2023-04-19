/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:02:40 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/19 14:44:57 by iortega-         ###   ########.fr       */
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

int	error_msg(void)
{
	write(2, &"Error\n", 6);
	return (1);
}

static int	correct_arg( char **arg_split)
{
	int	z;
	int	j;

	z = 0;
	while (arg_split[z])
	{
		j = 0;
		if (arg_split[z][j] == '-')
			j++;
		while (arg_split[z][j] != '\0')
		{
			if (!ft_isdigit((int) arg_split[z][j++]))
				return (0);
		}
		if (ft_strlen(arg_split[z]) > 11 || ft_strlen(arg_split[z]) == 0)
			return (0);
		if (ft_atoi_long(arg_split[z]) > INT_MAX)
			return (0);
		if (ft_atoi_long(arg_split[z]) < INT_MIN)
			return (0);
		z++;
	}
	return (1);
}

int	check_error(int argc, char **argv)
{
	int		i;
	int		j;
	int		z;
	char	**arg_split;

	i = 1;
	while (i < argc)
	{
		arg_split = ft_split(argv[i], ' ');
		z = 0;
		if (!correct_arg(arg_split))
			return (error_msg());
		ft_free(arg_split);
		i++;
	}
	return (0);
}
