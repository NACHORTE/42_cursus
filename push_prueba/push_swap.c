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

t_list	*get_array(int numbers, char **input)
{
	t_list	*a;
	int		i;
	int		number;
	t_list	*aux;

	i = 1;
	a = NULL;
	while (i <= numbers)
	{
		number = ft_atoi(input[i]);
		aux = ft_lstnew(number);
		if (!aux)
			return (0);
		ft_lstadd_back(&a, aux);
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		*a_sorted;

	if (check_error(argc, argv) || argc <= 2)
		return (0);
	size_a = argc - 1;
	b = NULL;
	a = get_array(size_a, argv);
	if (!a)
		return (free_list(&a));
	a_sorted = sort_a(a, size_a);
	if (!a)
		return (free_list(&a));
	if (check_sorted(a, a_sorted, size_a))
		return (0);
	if (size_a == 3)
		a = sort_3(a);
	else if (size_a <= 5)
		a = sort_little(a, b, size_a, a_sorted);
	else
		a = sort(a, b, size_a, a_sorted);
	free (a_sorted);
}
