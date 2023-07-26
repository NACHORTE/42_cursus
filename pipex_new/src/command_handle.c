/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:00:38 by iortega-          #+#    #+#             */
/*   Updated: 2023/07/22 16:09:12 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_path(char **envp)
{
	char	**path;

	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	path = ft_split(*envp + 5, ':');
	return (path);
}

char	*get_cmd_path(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

int	divide_command(t_pipex *pipex, char **argv)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd_path1 = get_cmd_path(pipex->path, pipex->cmd1[0]);
	if (!pipex->cmd_path1)
	{
		free_doublearray(pipex->cmd1);
		return (0);
	}
	pipex->cmd2 = ft_split(argv[3], ' ');
	pipex->cmd_path2 = get_cmd_path(pipex->path, pipex->cmd2[0]);
	if (!pipex->cmd_path2)
	{
		free_doublearray(pipex->cmd1);
		free(pipex->cmd_path1);
		free_doublearray(pipex->cmd2);
		return (0);
	}
	return (1);
}
