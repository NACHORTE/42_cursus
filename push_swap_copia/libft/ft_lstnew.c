/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:10:59 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/18 13:48:08 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*newl;

	newl = malloc(sizeof(t_list));
	if (newl == 0)
		return (0);
	newl->content = content;
	newl->next = 0;
	return (newl);
}
