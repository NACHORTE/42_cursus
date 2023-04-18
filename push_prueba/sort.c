/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:12:35 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/09 15:28:26 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort(t_list *a, t_list *b, int size_a, int *full_sorted)
{
	int	midpoint;
	int	j;
	int	chunk_number;

	if (check_sorted(a, full_sorted, size_a))
		return (a);
	if (size_a > 100)
		chunk_number = size_a / 10;
	else if (size_a >= 10)
		chunk_number = size_a / 5;
	else
		chunk_number = size_a / 2;
	j = -1;
	while (ft_lstsize(a) > 0)
	{
		j = j + chunk_number;
		if (j >= size_a)
			j = size_a - 1;
		midpoint = full_sorted[j];
		push_chunk_tob(&a, &b, chunk_number, midpoint);
	}
	push_chunk_2(&a, &b, full_sorted, ft_lstsize(b));
	return (a);
}

t_list	*sort_3(t_list *a)
{
	int	next;
	int	last;

	next = a->next->content;
	last = ft_lstlast(a)->content;
	if (last > a->content && last > next)
		swap(&a, 'a');
	else if (a->content > next && next > last)
	{
		swap(&a, 'a');
		reverse(&a, 'a');
	}
	else if (a->content > next && next < last)
		rotate(&a, 'a');
	else if (a->content < next && next > last)
	{
		if (a->content < last)
		{
			swap(&a, 'a');
			rotate(&a, 'a');
		}
		else
			reverse(&a, 'a');
	}
	return (a);
}

t_list	*sort_little(t_list *a, t_list *b, int size_a, int *a_sorted)
{
	if (size_a == 2)
	{
		if (a->content > a->next->content)
		swap(&a, 'a');
		return (a);
	}
	push_little(&a, &b, a_sorted);
	if (a->content > a->next->content)
		swap(&a, 'a');
	if (ft_lstsize(b) == 3)
		push_btoa(&a, &b, 'a');
	if (b->content < b->next->content)
		swap(&b, 'b');
	push_btoa(&a, &b, 'a');
	push_btoa(&a, &b, 'a');
	return (a);
}
