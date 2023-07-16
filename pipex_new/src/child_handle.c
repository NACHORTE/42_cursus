/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:05:29 by iortega-          #+#    #+#             */
/*   Updated: 2023/07/16 19:25:43 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	call_child1(t_pipex pipex, char **envp)
{
	dup2(pipex.port[1], 1);
	close(pipex.port[0]);
	dup2(pipex.infile, 0);
	if (!pipex.cmd_path1)
	{
		error_msg();
		exit(1);
	}
	execve(pipex.cmd_path1, pipex.cmd1, envp);
}

void	call_child2(t_pipex pipex, char **envp)
{
	dup2(pipex.port[0], 0);
	close(pipex.port[1]);
	dup2(pipex.outfile, 1);
	if (!pipex.cmd_path2)
	{
		error_msg();
		exit(1);
	}
	execve(pipex.cmd_path2, pipex.cmd2, envp);
}
