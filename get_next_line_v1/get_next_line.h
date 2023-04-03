/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:41:13 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/22 15:41:13 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10

size_t	ft_strlen(const char *str);

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);

char	*ft_strdup(const char *src);

char	*ft_strjoin(char const *s1, char const *s2);

char	*get_next_line(int fd);

# endif

#endif