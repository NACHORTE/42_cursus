/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:47:29 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/08 19:47:29 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		chars;
	int		total;
	char	**array;

	total = ft_countwords(s, c);
	array = malloc(sizeof(char *) * total);
	if (array == 0 || *s == '\0' || total == 0)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0' && j <= total)
	{
		while (s[i] == c)
			i++;
		chars = ft_countchars(&s[i], c);
		array[j] = malloc(sizeof(char) * chars);
		if (array[j] == 0)
			return (0);
		array[j++] = ft_substr(s, i, chars);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (array);
}
