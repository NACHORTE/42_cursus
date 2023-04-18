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
	if (!a_sorted)
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

static int	*sort_b(t_list *b, int size_b)
{
	int *b_sorted;
	t_list *tmp;
	int	i;

	i = 0;
	b_sorted = malloc(sizeof(int) * size_b);
	if (!b_sorted)
		return(0);
	tmp = b;
	while(i < size_b)
	{
		b_sorted[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	if (size_b > 1)
		sort_int_array(b_sorted, size_b);
	return (b_sorted);
}

void	push_chunk(t_list **a, t_list **b, int *a_sorted, int n_push)
{
	int	midpos;
	int	i;
	int j;
	int	rotations;
	int midpoint;

	if (n_push == 1)
		{
			push_btoa(a, b, 'a');
			return ;
		}
	i = n_push - 1;
	while (n_push > 2)
	{
		midpos = n_push / 2;
		midpoint = a_sorted[midpos];
		j = 0;
		rotations = 0;
		while (n_push == 3)
		{
			if ((*b)->content > (*b)->next->content && (*b)->content > (*b)->next->next->content)
			{
				push_btoa(a, b, 'a');
				j++;
				n_push--;
			}
			else
			{
				rotate(b, 'b');
				rotations++;
				if ((*b)->content > (*b)->next->content)
					{
						push_btoa(a, b, 'a');
						j++;
						n_push--;
					}
				else
					{
						swap(b, 'b');
						push_btoa(a, b, 'a');
						j++;
						n_push--;
					}
			}
		}
		int elements;
		elements = (n_push / 2) - 1;
		while(j < elements && n_push > 3)  //ARREGLAR
		{
			if ((*b)->content == a_sorted[i])
			{
				push_btoa(a, b, 'a');
				j++;
				i--;
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

int	is_on_half_up(t_list *b, int number_to_push)
{
	int	i;
	t_list	*tmp;

	i = 0;
	tmp = b;
	while (tmp)
	{
		if (tmp->content == number_to_push)
		{
			if (i < ft_lstsize(b) / 2)
				return (1);
			else
				return (0);
		}
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	push_chunk_2(t_list **a, t_list **b, int *chunk_numbers, int n_push)
{
	int	i;
	int	rotations;

	i = n_push - 1;
	rotations = 0;
	while (n_push > 0)
	{
		while(is_on_half_up(*b, chunk_numbers[i]) && n_push > 0)
		{
		if ((*b)->content == chunk_numbers[i])
		{
			push_btoa(a, b, 'a');
			n_push--;
			i--;
		}
		else
		{
			rotate(b, 'b');
			rotations++;
		}
		}
		if (n_push <= 0 || ft_lstsize(*b) <= 3)
			break;
		while(!is_on_half_up(*b, chunk_numbers[i]))
			reverse(b, 'b');
		/*while (rotations != 0 && n_push > 0)
		{
			reverse(b, 'b');
			rotations--;
			if ((*b)->content == chunk_numbers[i])
			{
				push_btoa(a, b, 'a');
				n_push--;
				i--;
			}
		}*/
	}
	while (ft_lstsize(*b) > 0 && n_push > 0)
	{
		if ((*b)->content == chunk_numbers[i])
		{
			push_btoa(a, b, 'a');
			n_push--;
			i--;
		}
		else
			rotate(b, 'b');
	}
}

void	back_to_a(t_list **a, t_list **b, t_chunk chunks, int *a_sorted)
{
	int	i;
	int	*chunk_numbers;

	if (*b == NULL)
		return ;
	i = 0;
	while (i < chunks.len)
	{
		chunk_numbers = sort_b(*b, chunks.chunks[i]);
		/*printf("\n");
		for(int j = 0; j<chunks.chunks[i];j++)
		{
			printf("%d\n", chunk_numbers[j]);
		}
		printf("\n");
		print_list(*b);*/
		push_chunk_2(a, b, chunk_numbers, chunks.chunks[i]);
		//push_chunk(a, b, a_sorted, chunks.chunks[i]);
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

int		number_on_half_up(t_list *a, int midpoint)
{
	int	i;
	t_list *tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		if (tmp->content < midpoint)
		{
			if (i < ft_lstsize(a) / 2)
				return (1);
			else
				return (0);
		}
		i++;
		tmp = tmp->next;
	}
	return (0);
}

t_list	*sort(t_list *a, t_list *b, int size_a)
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
			return (NULL);
		if (check_sorted(a, a_sorted, size_a))
			break;
		midpoint = a_sorted[size_a / 2];
		i = 0;
		while (i < size_a / 2)
		{
			/*while (!number_on_half_up(a, midpoint))
			{
				reverse(&a, 'a');
			}*/
			/*if (ft_lstlast(a)->content < midpoint)
			{
				reverse(&a, 'a');
				if (check_sorted(a, a_sorted, size_a))
					break;
				push_btoa(&b, &a, 'b');
				i++;
			}
			else */if (a->content < midpoint)
			{
				push_btoa(&b, &a, 'b');
				i++;
			}
			else if (number_on_half_up(a, midpoint))
			{
				if (ft_lstsize(b) > 1)
				{
					if (b->content < b->next->content)
						rr(&a, &b);
					else
						rotate(&a, 'a');
				}
				else
					rotate(&a, 'a');
				if (check_sorted(a, a_sorted, size_a))
					break;
			}
			else
			{
				if (ft_lstsize(b) > 1)
				{
					if (b->content < ft_lstlast(b)->content)
						rrr(&a, &b);
					else
						reverse(&a, 'a');
				}
				else
					reverse(&a, 'a');
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