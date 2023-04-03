/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:13:54 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/13 13:33:34 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		total;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	total = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * total + 1);
	if (str == 0)
		return (0);
	i = 0;
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, total + 1);
	return (str);
}
