/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:02:50 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/17 12:54:58 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_int(char *s, int fd)
{
	if (s == NULL)
		return (0);
	if (*s != '\0')
		write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}
