/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:09:03 by iortega-          #+#    #+#             */
/*   Updated: 2023/05/01 22:16:58 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_mem(t_data *var)
{
	int	i;

	i = 0;
	while (var->mapa.map[i] != 0)
	{
		free(var->mapa.map[i]);
		i++;
	}
	free(var->mapa.map);
	return (0);
}

void	destroy_images(t_data *var)
{
	mlx_destroy_image(var->mlx, var->wall.img);
	mlx_destroy_image(var->mlx, var->floor.img);
	mlx_destroy_image(var->mlx, var->coin.img);
	mlx_destroy_image(var->mlx, var->character.img);
	mlx_destroy_image(var->mlx, var->chest.img);
	mlx_destroy_display(var->mlx);
}

void	find_player(t_data *var, t_data *aux)
{
	int	i;
	int	j;

	i = 0;
	while (var->mapa.map[i] != 0)
	{
		j = 0;
		while (var->mapa.map[i][j] != '\0')
		{
			if (var->mapa.map[i][j] == 'P')
			{
				aux->mapa.map[i][j] = 'x';
				aux->mapa.char_x = j;
				aux->mapa.char_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
