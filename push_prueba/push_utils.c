/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:20:37 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/09 15:29:49 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char l)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
	write(1, "s", 1);
	write(1, &l, 1);
	write(1, "\n", 1);
}

void	push_btoa(t_list **a, t_list **b, char l)
{
	t_list	*temp;

	if (*b != NULL)
	{
		temp = *b;
		*b = (*b)->next;
		ft_lstadd_front(a, temp);
	}
	write(1, "p", 1);
	write(1, &l, 1);
	write(1, "\n", 1);
}

void	rotate(t_list **stack, char l)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
	write(1, "r", 1);
	write(1, &l, 1);
	write(1, "\n", 1);
}

void	reverse(t_list **stack, char l)
{
	t_list	*last;
	t_list	*prev_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1, "rr", 2);
	write(1, &l, 1);
	write(1, "\n", 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
