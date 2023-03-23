/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:30:06 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/23 13:30:06 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10

size_t			ft_strlen(const char *str);

char			*ft_strchr(const char *s, int c);

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);

char			*ft_strjoin(char *s1, char *s2);

char			*get_next_line(int fd);

# endif

#endif