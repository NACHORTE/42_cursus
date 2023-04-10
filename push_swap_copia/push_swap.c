/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:49:18 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/02 22:49:18 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_array(int numbers, char **input)
{
	t_list	*a;
	int	i;
	int	number;
	t_list	*aux;

	i = 1;
	a = NULL;
	while (i <= numbers)
	{
		number = ft_atoi(input[i]);
		aux = ft_lstnew(number);
		if (!aux)
			return(0);
		ft_lstadd_back(&a, aux);
		i++;
	}
	/*printf("%d\n", ft_lstsize(a));
	t_list *temp = a;
	while (temp)
	{
   		int x = temp->content;
    	printf("%d\n", x);
    	temp = temp->next;
	}*/
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int	size_a;

	if (check_error(argc, argv) || argc == 2)
		return (0);
	size_a = argc - 1;
	b = NULL;
	a = get_array(size_a, argv);
	a = sort(a, b, size_a);
	print_list(a);
	//print_list(b);
}
