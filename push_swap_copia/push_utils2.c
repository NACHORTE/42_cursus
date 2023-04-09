/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:45:44 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/09 15:25:23 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*sort_int_array(int *array, int size)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[i])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
			j++;
		}
		i++;
	}
}

void print_list(t_list *a)
{
			t_list *temp1 = a;
	while (temp1)
	{
   		int x = temp1->content;
    	printf("%d\n", x);
    	temp1 = temp1->next;
	}
	printf ("\n");
}

int	check_sorted(t_list *a)
{
	t_list *tmp;
	int	aux;

	tmp = a;
	while (tmp)
	{
		aux = tmp->content;
		tmp = tmp->next;
		if (!tmp)
			break;
		if (aux > tmp->content)
			return (0);
	}
	return (1);
}