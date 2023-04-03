/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:49:18 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/02 22:49:18 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_array(int numbers, char **input)
{
	int	*a;
	int	i;

	a = malloc(sizeof(int) * numbers);
	if (!a)
		return (0);
	i = 0;
	while (i < numbers)
	{
		a[i] = ft_atoi(input[i + 1]);
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;

	if (check_error(argc, argv))
		return (0);
	size_a = argc - 1;
	size_b = 0;
	b = malloc(sizeof(int) * size_a);
	if (!b)
		return (0);
	a = get_array(size_a, argv);
}
