/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:20:37 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/02 20:20:37 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	first = *stack;
	second = first->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
	write(1, "sa\n", 3);
}

void	push_btoa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*b != NULL)
	{
		temp = *b;
		*b = (*b)->next;
		ft_lstadd_front(a, temp);
	}
}

void	rotate(t_list **stack)
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
}

void	reverse(t_list **stack)
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
