/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:58:24 by iortega-          #+#    #+#             */
/*   Updated: 2023/08/01 13:00:56 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
//# include <X11/keysym.h>
//# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

# define D 2
# define W 13
# define A 0
# define S 1
# define IMG_SIZE 100
# define ESC 53

typedef struct s_img {
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;
}	t_img;

typedef struct s_map {
	char	**map;
	char	*path;
	int		char_x;
	int		char_y;
	int		collected;
	int		coins;
	int		end;
}	t_map;

typedef struct s_data {
	void	*mlx;
	void	*win;
	int		moves;
	t_img	character;
	t_img	floor;
	t_img	wall;
	t_img	coin;
	t_img	chest;
	t_map	mapa;
}	t_data;

int			check_edges(t_data var);
int			check_ber(char *str);
int			character_failure(t_data *var);
int			rect_map(t_data var);
void		move_msg(t_data *var);
int			draw(t_data *var, int pos, int i, int j);
int			refresh(t_data *var);
void		path_images(t_data *var);
void		init_images(t_data *var);
int			select_move(int key, t_data *var);
int			check_error(t_data *var, char *argv);
int			get_map(t_data *var, char *name);
int			x_press(t_data *data);
int			free_mem(t_data *var);
int		destroy_images(t_data *var);
int			valid_path(t_data *var, char *path);
void		find_player(t_data *var, t_data *aux);

#endif