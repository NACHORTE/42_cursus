/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:25:38 by iortega-          #+#    #+#             */
/*   Updated: 2023/02/06 23:52:43 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	aux;

	aux = 0;
	while (str[aux] != '\0')
	{
		if (str[aux] >= 'A' && str[aux] <= 'Z')
		str[aux] = (str[aux] - 'A') + 'a';
		aux++;
	}
	return (str);
}
