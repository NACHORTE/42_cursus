/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:00:56 by iortega-          #+#    #+#             */
/*   Updated: 2023/04/19 14:33:52 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	word;
	int	result;

	result = 0;
	i = 0;
	word = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && word == 1)
		{
			result++;
			word = 0;
		}
		if (s[i] == c)
			word = 1;
		i++;
	}
	return (result);
}

static int	ft_countchars(char const *s, char c)
{
	int	chars;

	chars = 0;
	while (s[chars] != c && s[chars] != '\0')
	{
		chars++;
	}
	return (chars);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*result;
	unsigned int		i;
	unsigned int		slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (len >= slen + 1)
		len = slen;
	if (start >= slen)
		len = 0;
	else if (len > slen - start)
		len = slen - start;
	result = malloc(sizeof(char) * len + 1);
	if (result == 0)
		return (0);
	result[0] = '\0';
	i = 0;
	while (i < len && s[start] != '\0')
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		total;
	char	**array;

	total = ft_countwords(s, c);
	array = malloc(sizeof(char *) * (total + 1));
	if (array == 0)
		return (0);
	array[total] = NULL;
	i = 0;
	j = 0;
	while (s[i] != '\0' && j < total)
	{
		while (s[i] == c)
			i++;
		array[j++] = ft_substr(s, i, ft_countchars(&s[i], c));
		if (array[j - 1] == 0)
			i = ft_free(array);
		if (i == -2)
			return (0);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (array);
}
