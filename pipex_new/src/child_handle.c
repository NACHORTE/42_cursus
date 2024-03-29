/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:05:29 by iortega-          #+#    #+#             */
/*   Updated: 2023/09/06 21:08:27 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	no_command(t_pipex pipex, int child)
{
	int	len;

	if (child == 1)
	{
		write(2, &"Command not found: ", 19);
		if (*pipex.cmd1)
		{
			len = ft_strlen(pipex.cmd1[0]);
			write(2, pipex.cmd1[0], len);
		}
		write(2, &"\n", 1);
	}
	if (child == 2)
	{
		write(2, &"Command not found: ", 19);
		if (*pipex.cmd2)
		{
			len = ft_strlen(pipex.cmd2[0]);
			write(2, pipex.cmd2[0], len);
		}
		write(2, &"\n", 1);
	}
}

void	call_child1(t_pipex pipex, char **envp)
{
	dup2(pipex.port[1], 1);
	close(pipex.port[0]);
	dup2(pipex.infile, 0);
	if (!pipex.cmd_path1)
	{
		no_command(pipex, 1);
		exit(127);
	}
	execve(pipex.cmd_path1, pipex.cmd1, envp);
	perror(*pipex.cmd1);
	exit(1);
}

void	call_child2(t_pipex pipex, char **envp)
{
	dup2(pipex.port[0], 0);
	close(pipex.port[1]);
	dup2(pipex.outfile, 1);
	if (!pipex.cmd_path2)
	{
		no_command(pipex, 2);
		exit(127);
	}
	execve(pipex.cmd_path2, pipex.cmd2, envp);
	perror(*pipex.cmd2);
	exit(1);
}
