/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:03:55 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/16 19:03:55 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_putchar_int(char c, int fd);
int		ft_putnbr_int(int n, int fd, int i);
int		ft_putstr_int(char *s, int fd);
int		ft_puthex(int nbr, char a);

#endif