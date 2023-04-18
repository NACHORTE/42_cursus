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

# include "limits.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_chunk
{
	int				len;
	int				*chunks;
}					t_chunk;

void		reverse(t_list **stack, char l);
void		rotate(t_list **stack, char l);
void		push_btoa(t_list **a, t_list **b, char l);
void		swap(t_list **stack, char l);
void		rr(t_list **a, t_list **b);
void		ss(t_list **a, t_list **b);
void		push_little(t_list **a, t_list **b, int *a_sorted);
int			check_error(int argc, char **argv);
int			ft_strcmp(const char *s1, const char *s2);
void		sort_int_array(int *array, int size);
t_list		*sort(t_list *a, t_list *b, int size_a, int *full_sorted);
t_list		*sort_little(t_list *a, t_list *b, int size_a, int *a_sorted);
t_list		*sort_3(t_list *a);
void		print_list(t_list *a);
int			check_sorted(t_list *a, int *a_sorted, int size_a);
int			*sort_a(t_list *a, int size_a);
int			*sort_a(t_list *a, int size_a);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
int			ft_isdigit(int c);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);
int			is_on_half_up(t_list *b, int number_to_push);
void		push_chunk_2(t_list **a, t_list **b, int *chn, int n);
int			free_list(t_list **a);
int			number_on_half_up(t_list *a, int midpoint);
void		push_chunk_tob(t_list **a, t_list **b, int chn, int mp);

#endif