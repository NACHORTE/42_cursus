/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:05:55 by iortega-          #+#    #+#             */
/*   Updated: 2023/05/01 22:18:46 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_neighbors(t_data *aux, int i, int j, int wrote)
{
	if (wrote != 1)
		wrote = 0;
	if (aux->mapa.map[i][j + 1] == '0' || aux->mapa.map[i][j + 1] == 'C')
	{
		aux->mapa.map[i][j + 1] = 'x';
		wrote = 1;
	}
	if (aux->mapa.map[i][j - 1] == '0' || aux->mapa.map[i][j - 1] == 'C')
	{
		aux->mapa.map[i][j - 1] = 'x';
		wrote = 1;
	}
	if (aux->mapa.map[i + 1][j] == '0' || aux->mapa.map[i + 1][j] == 'C')
	{
		aux->mapa.map[i + 1][j] = 'x';
		wrote = 1;
	}
	if (aux->mapa.map[i - 1][j] == '0' || aux->mapa.map[i - 1][j] == 'C')
	{
		aux->mapa.map[i - 1][j] = 'x';
		wrote = 1;
	}
	return (wrote);
}

static int	check_end(t_data *aux, int i, int j)
{
	if (aux->mapa.map[i][j + 1] == 'x')
		return (1);
	if (aux->mapa.map[i][j - 1] == 'x')
		return (1);
	if (aux->mapa.map[i + 1][j] == 'x')
		return (1);
	if (aux->mapa.map[i - 1][j] == 'x')
		return (1);
	return (0);
}

static int	check_coins(t_data *var, t_data *aux)
{
	int	i;
	int	j;

	i = 0;
	while (var->mapa.map[i] != 0)
	{
		j = 0;
		while (var->mapa.map[i][j] != '\0')
		{
			if (var->mapa.map[i][j] == 'C')
			{
				if (aux->mapa.map[i][j] != 'x')
					return (0);
			}
			if (var->mapa.map[i][j] == 'E')
			{
				if (!check_end(aux, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	find_x(t_data *aux)
{
	int	wrote;
	int	i;
	int	j;

	i = 0;
	wrote = 0;
	while (aux->mapa.map[i] != 0)
	{
		j = 0;
		while (aux->mapa.map[i][j] != '\0')
		{
			if (aux->mapa.map[i][j] == 'x')
			{
				wrote = check_neighbors(aux, i, j, wrote);
			}
			j++;
		}
		i++;
	}
	return (wrote);
}

int	valid_path(t_data *var, char *path)
{
	t_data	aux;
	int		wrote;

	if (!get_map(&aux, path))
	{
		write(1, "Error reading map (validating path).\n", 37);
		return (0);
	}
	find_player(var, &aux);
	wrote = 1;
	while (wrote)
	{
		wrote = 0;
		wrote = find_x(&aux);
	}
	if (!check_coins(var, &aux))
	{
		free_mem(&aux);
		return (0);
	}
	free_mem(&aux);
	return (1);
}
