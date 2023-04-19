/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:04:46 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/19 14:49:58 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_a(t_list *a, int size_a)
{
	int		*a_sorted;
	t_list	*tmp;
	int		i;

	i = 0;
	a_sorted = malloc(sizeof(int) * size_a);
	if (!a_sorted)
		return (0);
	tmp = a;
	while (tmp)
	{
		a_sorted[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	if (is_dup(a_sorted, size_a))
	{
		free(a_sorted);
		return (0);
	}
	sort_int_array(a_sorted, size_a);
	return (a_sorted);
}

int	is_on_half_up(t_list *b, int number_to_push)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = b;
	if (ft_lstsize(b) <= 3)
		return (1);
	while (tmp)
	{
		if (tmp->content == number_to_push)
		{
			if (i <= ft_lstsize(b) / 2)
				return (1);
			else
				return (0);
		}
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	push_chunk_2(t_list **a, t_list **b, int *chn, int n)
{
	int	i;

	i = n - 1;
	while (n > 0)
	{
		while (is_on_half_up(*b, chn[i]) && n > 0)
		{
			if ((*b)->content == chn[i])
			{
				push_btoa(a, b, 'a');
				n--;
				i--;
			}
			else
				rotate(b, 'b');
			if (n <= 0)
				break ;
		}
		while (!is_on_half_up(*b, chn[i]))
			reverse(b, 'b');
	}
}

int	number_on_half_up(t_list *a, int midpoint)
{
	int		i;
	t_list	*tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		if (tmp->content < midpoint)
		{
			if (i <= ft_lstsize(a) / 2)
				return (1);
			else
				return (0);
		}
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	push_chunk_tob(t_list **a, t_list **b, int chn, int mp)
{
	int	i;

	i = 0;
	while (i < chn)
	{
		if (ft_lstsize(*a) <= 3)
		{
			push_btoa(b, a, 'b');
			push_btoa(b, a, 'b');
			push_btoa(b, a, 'b');
			i = i + 3;
		}
		else if ((*a)->content <= mp)
		{
			push_btoa(b, a, 'b');
			i++;
		}
		else if (number_on_half_up(*a, mp))
			rotate(a, 'a');
		else
			reverse(a, 'a');
	}
}
