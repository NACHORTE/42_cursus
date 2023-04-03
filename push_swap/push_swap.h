/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:32:36 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/03 12:32:36 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "limits.h"

void	reverse(int *x, int sizex);
void	rotate(int *x, int sizex);
void	push(int *x, int *y, int sizex, int sizey);
void	swap(int *x, int size);
int		check_error(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);

#endif