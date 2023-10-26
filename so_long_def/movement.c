/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:40:28 by iortega-          #+#    #+#             */
/*   Updated: 2023/07/26 11:12:58 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_right(t_data *var, int i, int j)
{
	if (var->mapa.map[i][j + 1] == 'C')
		var->mapa.collected++;
	if (var->mapa.map[i][j + 1] == '0' || var->mapa.map[i][j + 1] == 'C')
	{
		var->mapa.map[i][j] = '0';
		var->mapa.map[i][j + 1] = 'P';
		move_msg(var);
	}
	else if (var->mapa.map[i][j + 1] == 'E'
		&& var->mapa.collected == var->mapa.coins)
	{
		move_msg(var);
		mlx_destroy_window(var->mlx, var->win);
		var->win = NULL;
		return (0);
	}
	return (1);
}

static int	move_up(t_data *var, int i, int j)
{
	if (var->mapa.map[i - 1][j] == 'C')
		var->mapa.collected++;
	if (var->mapa.map[i - 1][j] == '0' || var->mapa.map[i - 1][j] == 'C')
	{
		var->mapa.map[i][j] = '0';
		var->mapa.map[i - 1][j] = 'P';
		move_msg(var);
	}
	else if (var->mapa.map[i - 1][j] == 'E'
		&& var->mapa.collected == var->mapa.coins)
	{
		move_msg(var);
		mlx_destroy_window(var->mlx, var->win);
		var->win = NULL;
		return (0);
	}
	return (1);
}

static int	move_left(t_data *var, int i, int j)
{
	if (var->mapa.map[i][j - 1] == 'C')
		var->mapa.collected++;
	if (var->mapa.map[i][j - 1] == '0' || var->mapa.map[i][j - 1] == 'C')
	{
		var->mapa.map[i][j] = '0';
		var->mapa.map[i][j - 1] = 'P';
		move_msg(var);
	}
	else if (var->mapa.map[i][j - 1] == 'E'
		&& var->mapa.collected == var->mapa.coins)
	{
		move_msg(var);
		mlx_destroy_window(var->mlx, var->win);
		var->win = NULL;
		return (0);
	}
	return (1);
}

static int	move_down(t_data *var, int i, int j)
{
	if (var->mapa.map[i + 1][j] == 'C')
		var->mapa.collected++;
	if (var->mapa.map[i + 1][j] == '0' || var->mapa.map[i + 1][j] == 'C')
	{
		var->mapa.map[i][j] = '0';
		var->mapa.map[i + 1][j] = 'P';
		move_msg(var);
	}
	else if (var->mapa.map[i + 1][j] == 'E'
		&& var->mapa.collected == var->mapa.coins)
	{
		move_msg(var);
		mlx_destroy_window(var->mlx, var->win);
		var->win = NULL;
		return (0);
	}
	return (1);
}

int	select_move(int key, t_data *var)
{
	int	i;
	int	j;

	if (key == ESC)
	{
		mlx_destroy_window(var->mlx, var->win);
		var->win = NULL;
		return (0);
	}
	i = var->mapa.char_y;
	j = var->mapa.char_x;
	if (key == D)
		if (!move_right(var, i, j))
			return (0);
	if (key == W)
		if (!move_up(var, i, j))
			return (0);
	if (key == A)
		if (!move_left(var, i, j))
			return (0);
	if (key == S)
		if (!move_down(var, i, j))
			return (0);
	refresh(var);
	return (0);
}
