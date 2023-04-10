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

void	push_chunk(t_list **a, t_list **b, int *a_sorted, int n_push)
{
	int	midpos;
	int j;
	int	rotations;
	int midpoint;

	if (n_push == 1)
		{
			push_btoa(a, b, 'a');
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
				push_btoa(a, b, 'a');
				j++;
				n_push--;
			}
			else
			{
				rotate(b, 'b');
				rotations++;
			}
		}
		int elements;
		elements = (n_push / 2) - 1;
		while(j < elements && n_push > 3)
		{
			if ((*b)->content > midpoint)
			{
				push_btoa(a, b, 'a');
				j++;
				n_push--;
			}
			else
			{
				rotate(b, 'b');
				rotations++;
			}
		}
		while (rotations != 0)
		{
			reverse(b, 'b');
			rotations--;
		}
	}
	if ((*b)->content > (*b)->next->content)
	{
		push_btoa(a, b, 'a');
		push_btoa(a, b, 'a');
		return ;
	}
	else
	{
		swap(b, 'b');
		push_btoa(a, b, 'a');
		push_btoa(a, b, 'a');
	}
	return ;
}

void	back_to_a(t_list **a, t_list **b, t_chunk chunks, int *a_sorted)
{
	int	i;

	if (*b == NULL)
		return ;
	i = 0;
	while (i < chunks.len)
	{
		push_chunk(a, b, a_sorted, chunks.chunks[i]);
		i++;
	}
}

void reverse_array(int arr[], int size)
{
    int i = 0, j = size - 1;
    while (i < j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        i++;
        j--;
    }
}


void	new_chunk(t_chunk *chunk, int new)
{
	int	*tmp;
	int	i;

	i = 0;
	tmp = 0;
	if (chunk->chunks != 0)
		tmp = chunk->chunks;
	chunk->chunks = malloc(sizeof(int) * chunk->len);
	if (!chunk->chunks)
		return ;
	while (i < chunk->len - 1)
	{
		chunk->chunks[i] = tmp[i];
		i++;
	}
	chunk->chunks[i] = new;
	if (tmp)
		free(tmp);
}

t_list	*sort(t_list *a, t_list *b, int size_a, int size_b)
{
	int	*a_sorted;
	int	midpoint;
	int	i;
	t_chunk	chunks;
	int	*full_sorted;

	chunks.len = 0;
	chunks.chunks = 0;
	full_sorted = sort_a(a, size_a);
	while (ft_lstsize(a) > 2)
	{
		/*if (check_sorted(a))
			break;*/
		size_a = ft_lstsize(a);
		a_sorted = sort_a(a, size_a);
		if (!a_sorted)
			return ;
		if (check_sorted(a, a_sorted, size_a))
			break;
		midpoint = a_sorted[size_a / 2];
		i = 0;
		while (i < size_a / 2)
		{
			if (ft_lstlast(a)->content < midpoint)
			{
				reverse(&a, 'a');
				if (check_sorted(a, a_sorted, size_a))
					break;
				push_btoa(&b, &a, 'b');
				i++;
			}
			else if (a->content < midpoint)
			{
				push_btoa(&b, &a, 'b');
				i++;
			}
			else
			{
				rotate(&a, 'a');
				if (check_sorted(a, a_sorted, size_a))
					break;
			}
		}
		if (i > 0)
		{
			chunks.len++;
			new_chunk(&chunks, i);
		}

	}
	reverse_array(chunks.chunks, chunks.len);
	i = 0;
	/*printf ("\n");
	while (i < chunks.len)
	{
		printf("%d ", chunks.chunks[i]);
		i++;
	}
	printf ("\n");*/
	if (ft_lstsize(a) == 2)
	{
		if (a->content > a->next->content)
			swap(&a, 'a');
	}
	
	/*print_list(a);

	print_list(b);*/
	
	back_to_a(&a, &b, chunks, full_sorted);

	//print_list(a);
	return (a);
}