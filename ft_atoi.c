/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:05:21 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/07 13:20:34 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	num;
	int	neg;

	neg = 1;
	num = 0;
	while (*str == ' ' && *str != '\0')
		str++;
	while (*str != '\0')
	{
		if (*str == '-')
		{
			neg = -1;
			str++;
		}
		if (*str < '0' || *str > '9')
			return (num * neg);
		else
			num = 10 * num + *str - '0';
		str++;
	}
	num = num * neg;
	return (num);
}
