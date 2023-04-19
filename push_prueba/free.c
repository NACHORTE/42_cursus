/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:36:03 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/19 15:06:38 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_list(t_list **a)
{
	t_list	*temp;

	while (*a != 0)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	return (0);
}

int	is_dup(int *a, int size_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a - 1)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (a[i] == a[j])
				return (error_msg());
			j++;
		}
		i++;
	}
	return (0);
}
