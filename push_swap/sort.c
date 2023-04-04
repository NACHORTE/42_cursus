/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:12:35 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/04 19:12:35 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_a(t_list *a, int size_a)
{
	int *a_sorted;
	t_list *tmp;
	int	i;

	i = 0;
	a_sorted = malloc(sizeof(int) * size_a);
	if (!a)
		return(0);
	tmp = a;
	while(tmp)
	{
		a_sorted[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	sort_int_array(a_sorted, size_a);
	return (a_sorted);
}

void	sort(t_list *a, t_list *b, int size_a, int size_b)
{
	int	*a_sorted;
	int	midpoint;
	int	i;

	//printf("%d\n", midpoint);
	while (ft_lstsize(a) > 2)
	{
		size_a = ft_lstsize(a);
		a_sorted = sort_a(a, size_a);
		if (!a_sorted)
			exit;
		midpoint = a_sorted[size_a / 2];
		printf("\n%d  %d\n", midpoint, size_a);
		i = 0;
		while (i < size_a / 2)
		{
			if (a->content < midpoint)
			{
				push_btoa(&b, &a);
				i++;
			}
			else if (ft_lstlast(a)->content < midpoint)
			{
				reverse(&a);
				push_btoa(&b, &a);
				i++;
			}
			else
				rotate(&a);
		}
	}
	t_list *temp = b;
	while (temp)
	{
   		int x = temp->content;
    	printf("%d\n", x);
    	temp = temp->next;
	}
}