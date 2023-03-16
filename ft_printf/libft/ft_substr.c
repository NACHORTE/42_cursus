/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:13:33 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/13 13:13:00 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*result;
	unsigned int		i;
	unsigned int		slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (len > slen + 1)
		len = slen;
	result = malloc(sizeof(char) * len + 1);
	if (result == 0)
		return (0);
	result[0] = '\0';
	if (start >= slen)
		return (result);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
