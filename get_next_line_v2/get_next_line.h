/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:14:03 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/28 20:47:05 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE

# define BUFFER_SIZE 10

# endif

size_t			ft_strlen(char *s);

char			*ft_strchr(char *s, char c);

char			*ft_strjoin(char *s1, char *s2);

char			*get_next_line(int fd);

#endif