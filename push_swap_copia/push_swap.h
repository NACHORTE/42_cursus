/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:32:36 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/09 15:22:53 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "limits.h"

typedef struct s_chunk
{
	int				len;
	int				*chunks;
}					t_chunk;

void	reverse(t_list **stack, char l);
void	rotate(t_list **stack, char l);
void	push_btoa(t_list **a, t_list **b, char l);
void	swap(t_list **stack, char l);
int		check_error(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
void		*sort_int_array(int *array, int size);
t_list	*sort(t_list *a, t_list *b, int size_a, int size_b);
void print_list(t_list *a);
int	check_sorted(t_list *a, int *a_sorted, int size_a);

#endif