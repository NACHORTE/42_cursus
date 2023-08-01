/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:58:29 by iortega-          #+#    #+#             */
/*   Updated: 2023/08/01 13:20:59 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	variable_init(t_data *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, 1900, 1000, "so_long");
	path_images(var);
	init_images(var);
	var->moves = -1;
	var->mapa.collected = 0;
	var->mapa.end = 0;
	move_msg(var);
}

/*int	quetecla(int key, t_data *var)
{
	t_data *hola;
	hola = var;
	hola = hola + 1;
	printf("%d \n", key);
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_data	var;

	if (argc != 2)
	{
		write(1, "Error reading map.\n", 19);
		return(0);
	}
	if (!get_map(&var, argv[1]))
	{
		write(1, "Error reading map.\n", 19);
		return (0);
	}
	if (check_error(&var, argv[1]))
		return (free_mem(&var));
	if (!valid_path(&var, argv[1]))
	{
		write(1, "Impossible to complete level.\n", 30);
		return (0);
	}
	variable_init(&var);
	mlx_loop_hook(var.mlx, &refresh, &var);
	//mlx_key_hook(var.win, select_move, &var);
	mlx_key_hook(var.win, select_move, &var);
	mlx_hook(var.win, 17, 0, &x_press, &var);
	mlx_loop(var.mlx);
	free_mem(&var);
	destroy_images(&var);
	return (0);
}
