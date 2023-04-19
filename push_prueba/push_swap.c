/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:49:18 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/19 15:10:05 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_array(int numbers, char **input)
{
	t_list	*a;
	int		i;
	t_list	*aux;
	char	**arg_split;
	int		j;

	i = 1;
	a = NULL;
	while (i <= numbers)
	{
		j = 0;
		arg_split = ft_split(input[i], ' ');
		while (arg_split[j])
		{
			aux = ft_lstnew(ft_atoi(arg_split[j]));
			if (!aux)
				return (0);
			ft_lstadd_back(&a, aux);
			j++;
		}
		ft_free(arg_split);
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*a_sorted;
	int		size_a;

	if (check_error(argc, argv) || argc == 1)
		return (0);
	b = NULL;
	a = get_array(argc - 1, argv);
	if (!a)
		return (free_list(&a));
	size_a = ft_lstsize(a);
	a_sorted = sort_a(a, size_a);
	if (!a_sorted)
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
	return (0);
}
