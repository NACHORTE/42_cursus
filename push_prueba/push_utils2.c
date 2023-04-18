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

void	sort_int_array(int *array, int size)
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
	return ;
}

void	print_list(t_list *a)
{
	t_list	*temp1;
	int		x;

	temp1 = a;
	while (temp1)
	{
		x = temp1->content;
		printf("%d\n", x);
		temp1 = temp1->next;
	}
	printf ("\n");
}

int	check_sorted(t_list *a, int *a_sorted, int size_a)
{
	t_list	*tmp;
	int		i;
	int		equal;

	equal = 0;
	i = 0;
	tmp = a;
	while (i < size_a)
	{
		if (equal == 1 && tmp->content != a_sorted[i])
			return (0);
		if (tmp->content == a_sorted[i])
		{
			equal = 1;
			tmp = tmp->next;
		}
		i++;
	}
	if (!tmp)
		return (1);
	return (0);
}

void	rr(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	last = ft_lstlast(*a);
	last->next = first;
	first->next = NULL;
	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	last = ft_lstlast(*b);
	last->next = first;
	first->next = NULL;
	write(1, "rr\n", 3);
}

void	push_little(t_list **a, t_list **b, int *a_sorted)
{
	int	i;
	int	j;
	int	number_topush;

	i = 0;
	while (ft_lstsize(*a) > 2)
	{
		if (i < 2)
			j = 2;
		else
			j = 3;
		number_topush = a_sorted[j];
		if ((*a)->content < number_topush)
		{
			push_btoa(b, a, 'b');
			i++;
		}
		else if (number_on_half_up(*a, number_topush))
			rotate(a, 'a');
		else
			reverse(a, 'a');
	}
}
