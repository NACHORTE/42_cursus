/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:06:45 by iortega-          #+#    #+#             */
/*   Updated: 2023/08/04 13:15:42 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	x_press(t_data *data)
{
	/*mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;*/
	free_mem(data);
	destroy_images(data);
	exit (0);
}

static int	get_lines(t_data *var)
{
	int		lines;
	char	buff;
	int		fd;
	int		bytes;

	lines = 1;
	bytes = 1;
	fd = open(var->mapa.path, O_RDONLY);
	if (fd <= 0)
		return(0);
	while (bytes == 1)
	{
		bytes = read(fd, &buff, 1);
		if (buff == '\n')
			lines++;
	}
	close(fd);
	return (lines);
}

static int	save_lines(t_data *var, int lines)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(var->mapa.path, O_RDONLY);
	if (fd <= 0)
		return (0);
	var->mapa.map = malloc(sizeof(char *) * lines + sizeof(char *));
	if (var->mapa.map == 0)
		return (0);
	line = get_next_line(fd);
	while (line != 0)
	{
		var->mapa.map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	var->mapa.map[i] = 0;
	close(fd);
	if (i != lines)
		return (free_mem(var));
	return (1);
}

int	get_map(t_data *var, char *name)
{
	int		lines;

	var->mapa.path = name;
	lines = get_lines(var);
	if (lines == 0)
		return (0);
	if (!save_lines(var, lines))
		return (0);
	return (1);
}

int	check_error(t_data *var, char *argv)
{
	if (!check_ber(argv))
	{
		write(1, "Error, not .ber file.\n", 22);
		return (1);
	}
	if (!rect_map(*var) || !check_edges(*var))
	{
		write(1, "Error, incorrect map structure.\n", 32);
		return (1);
	}
	var->mapa.coins = 0;
	if (character_failure(var))
	{
		write(1, "Error, invalid map content.\n", 28);
		return (1);
	}
	if (var->mapa.coins == 0)
	{
		write(1, "Error, invalid map content.\n", 28);
		return (1);
	}
	return (0);
}
