/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:07:19 by iortega-          #+#    #+#             */
/*   Updated: 2023/09/06 19:54:17 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_pipes(t_pipex *pipex)
{
	close(pipex->port[0]);
	close(pipex->port[1]);
}

void	free_doublearray(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	pipex_free(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->path)
		free_doublearray(pipex->path);
}

void	childs_free(t_pipex *pipex)
{
	free_doublearray(pipex->cmd1);
	free_doublearray(pipex->cmd2);
	free(pipex->cmd_path1);
	free(pipex->cmd_path2);
}
