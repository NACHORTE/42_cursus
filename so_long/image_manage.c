/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:08:24 by iortega-          #+#    #+#             */
/*   Updated: 2023/05/01 20:04:10 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_images(t_data *var)
{
	var->character.path = "./textures/char.xpm";
	var->wall.path = "./textures/agua.xpm";
	var->floor.path = "./textures/piedra.xpm";
	var->coin.path = "./textures/coin.xpm";
	var->chest.path = "./textures/chest.xpm";
}

void	init_images(t_data *var)
{
	var->wall.img = mlx_xpm_file_to_image(var->mlx, var->wall.path,
			&var->wall.img_width, &var->wall.img_height);
	var->floor.img = mlx_xpm_file_to_image(var->mlx, var->floor.path,
			&var->floor.img_width, &var->floor.img_height);
	var->character.img = mlx_xpm_file_to_image(var->mlx, var->character.path,
			&var->character.img_width, &var->character.img_height);
	var->coin.img = mlx_xpm_file_to_image(var->mlx, var->coin.path,
			&var->coin.img_width, &var->coin.img_height);
	var->chest.img = mlx_xpm_file_to_image(var->mlx, var->chest.path,
			&var->chest.img_width, &var->chest.img_height);
}

void	move_msg(t_data *var)
{
	var->moves++;
	printf("Moves counter: %d\n", var->moves);
}

int	draw(t_data *var, int pos, int i, int j)
{
	if (var->mapa.map[i][j] == '1')
		mlx_put_image_to_window(var->mlx, var->win,
			var->wall.img, pos, IMG_SIZE * i);
	if (var->mapa.map[i][j] == '0')
		mlx_put_image_to_window(var->mlx, var->win,
			var->floor.img, pos, IMG_SIZE * i);
	if (var->mapa.map[i][j] == 'P')
	{
		var->mapa.char_x = j;
		var->mapa.char_y = i;
		mlx_put_image_to_window(var->mlx, var->win,
			var->character.img, pos, IMG_SIZE * i);
	}
	if (var->mapa.map[i][j] == 'C')
	{
		mlx_put_image_to_window(var->mlx, var->win,
			var->coin.img, pos, IMG_SIZE * i);
		return (1);
	}
	if (var->mapa.map[i][j] == 'E')
		mlx_put_image_to_window(var->mlx, var->win,
			var->chest.img, pos, IMG_SIZE * i);
	return (0);
}

int	refresh(t_data *var)
{
	int	i;
	int	j;
	int	all_coins;
	int	pos;

	all_coins = 0;
	if (var->win == NULL)
		return (0);
	i = 0;
	pos = 0;
	while (var->mapa.map[i] != 0)
	{
		j = 0;
		while (var->mapa.map[i][j] != '\0')
		{
			all_coins = all_coins + draw(var, pos, i, j);
			pos = pos + IMG_SIZE;
			j++;
		}
		i++;
		pos = 0;
	}
	return (all_coins);
}
