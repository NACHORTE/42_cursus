/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:46:16 by iortega-          #+#    #+#             */
/*   Updated: 2023/05/01 18:55:30 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_edges(t_data var)
{
	int	i;
	int	j;

	i = 0;
	while (var.mapa.map[i] != 0)
	{
		j = 0;
		while (var.mapa.map[i][j] != '\0')
		{
			if (i == 0 || var.mapa.map[i + 1] == 0)
				if (var.mapa.map[i][j] != '1' && var.mapa.map[i][j] != '\n')
					return (0);
			if (var.mapa.map[i][0] != '1')
				return (0);
			if (var.mapa.map[i][j + 1] == '\n')
				if (var.mapa.map[i][j] != '1')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_ber(char *str)
{
	int		i;
	int		j;
	char	aux[4];

	if (ft_strlen(str) < 4)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	j = 0;
	i--;
	while (j < 4)
	{
		aux[3 - j] = str[i - j];
		j++;
	}
	i = 0;
	while (i < 4)
	{
		if (aux[i] != ".ber"[i])
			return (0);
		i++;
	}
	return (1);
}

static int	valid_char(char c, t_data *var)
{
	if (c == 'C')
		var->mapa.coins++;
	if (c != '1' && c != '0' && c != 'P' && c != 'E'
		&& c != 'C' && c != '\n')
		return (0);
	else
		return (1);
}

int	character_failure(t_data *var)
{
	int	i;
	int	j;
	int	ps;
	int	es;

	i = -1;
	ps = 0;
	es = 0;
	while (var->mapa.map[++i] != 0)
	{
		j = 0;
		while (var->mapa.map[i][j] != '\0')
		{
			if (!valid_char(var->mapa.map[i][j], var))
				return (1);
			if (var->mapa.map[i][j] == 'P')
				ps++;
			else if (var->mapa.map[i][j] == 'E')
				es++;
			j++;
		}
	}
	if (ps != 1 || es != 1)
		return (1);
	return (0);
}

int	rect_map(t_data var)
{
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(var.mapa.map[i]);
	while (var.mapa.map[i] != 0)
	{
		if (var.mapa.map[i + 1] == 0)
			size--;
		if (ft_strlen(var.mapa.map[i]) != size)
			return (0);
		i++;
	}
	return (1);
}
