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

void	back_toa(t_list **a, t_list **b, int *a_sorted, int midpoint, int n_push)
{
	int	i;
	int	midpos;
	int j;
	int	rotations;

	printf ("%d\n", n_push);
	printf ("\n");
	t_list *temp = *b;
	while (temp)
	{
   		int x = temp->content;
    	printf("%d\n", x);
    	temp = temp->next;
	}
	printf ("\n");
	i = 0;
	if (n_push == 1)
		{
			push_btoa(a, b);
			printf ("+\n");
			t_list *temp = *a;
	while (temp)
	{
   		int x = temp->content;
    	printf("%d\n", x);
    	temp = temp->next;
	}
	printf ("+\n");
			return ;
		}
	while (n_push > 2)
	{
		midpos = n_push / 2;
		midpoint = a_sorted[midpos];
		j = 0;
		rotations = 0;
		while (n_push == 3)
		{
			if ((*b)->content > a_sorted[1])
			{
				push_btoa(a, b);
				j++;
				n_push--;
			}
			else
			{
				rotate(b);
				rotations++;
			}
		}
		int elements;
		elements = (n_push / 2) - 1;
		while(j < elements && n_push > 3)
		{
			if ((*b)->content > midpoint)
			{
				push_btoa(a, b);
				j++;
				n_push--;
			}
			else
			{
				rotate(b);
				rotations++;
			}
		}
		while (rotations != 0)
		{
			reverse(&b);
			rotations--;
		}
	}
	if ((*b)->content > (*b)->next->content)
	{
		push_btoa(a, b);
		push_btoa(a, b);
		printf ("-\n");
	t_list *temp2 = *a;
	while (temp2)
	{
   		int x = temp2->content;
    	printf("%d\n", x);
    	temp2 = temp2->next;
	}
	printf ("-\n");
		return ;
	}
	else
	{
		swap(b);
		push_btoa(a, b);
		push_btoa(a, b);
	}
	printf ("-\n");
	t_list *temp2 = *a;
	while (temp2)
	{
   		int x = temp2->content;
    	printf("%d\n", x);
    	temp2 = temp2->next;
	}
	printf ("-\n");
	return ;
}

void	sort(t_list *a, t_list *b, int size_a, int size_b)
{
	int	*a_sorted;
	int	midpoint;
	int	i;

	//printf("%d\n", midpoint);
	
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
	if (ft_lstsize(a) > 2)
		sort(a, b, size_a, size_b);
	if (ft_lstsize(a) == 2)
	{
		if (a->content > a->next->content)
			swap(&a);
	}
	
	printf ("*\n");
			t_list *temp1 = a;
	while (temp1)
	{
   		int x = temp1->content;
    	printf("%d\n", x);
    	temp1 = temp1->next;
	}
	printf ("*\n");

	back_toa(&a, &b, a_sorted, midpoint - 1, i);

	
}