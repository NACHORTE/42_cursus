/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:03:55 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/17 15:17:03 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_putunbr_int(unsigned int n, int fd);
int		ft_putchar_int(char c, int fd);
int		ft_putnbr_int(int n, int fd);
int		ft_putstr_int(char *s, int fd);
int		ft_puthex(int nbr, char a);
int		ft_printf(char const *str, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_printmemo(unsigned long int memo);

#endif