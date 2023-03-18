/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:47:29 by iortega-          #+#    #+#             */
/*   Updated: 2023/03/18 13:31:08 by iortega-         ###   ########.fr       */
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

static int	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (-2);
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
