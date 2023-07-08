/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:54:40 by iortega-          #+#    #+#             */
/*   Updated: 2023/06/18 16:54:51 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error_msg(void)
{
	write(2, &"Something went wrong.\n", 22);
	return (1);
}

char	**get_path(char **envp)
{
	char	**path;
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	path = ft_split(*envp + 5, ':');
	return (path);
}

static char	*get_cmd_path(char **paths, char *cmd)
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

void	call_child1(t_pipex pipex, char **envp)
{
	dup2(pipex.port[1], 1);
	close(pipex.port[0]);
	dup2(pipex.infile, 0);
	/*pipex.cmd1 = ft_split(argv[2], ' ');
	pipex.cmd_path = get_cmd_path(pipex.path, pipex.cmd1[0]);*/
	if (!pipex.cmd_path1)
	{
		//child_free(&pipex);
		//msg(ERR_CMD);
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
	/*pipex.cmd2 = ft_split(argv[3], ' ');
	pipex.cmd_path = get_cmd_path(pipex.path, pipex.cmd2[0]);*/
	if (!pipex.cmd_path2)
	{
		//child_free(&pipex);
		//msg(ERR_CMD);
		error_msg();
		exit(1);
	}
	execve(pipex.cmd_path2, pipex.cmd2, envp);
}

void close_pipes(t_pipex *pipex)
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
	free_doublearray(pipex->path);
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

void	childs_free(t_pipex *pipex)
{
	free_doublearray(pipex->cmd1);
	free_doublearray(pipex->cmd2);
	free(pipex->cmd_path1);
	free(pipex->cmd_path2);
}

int	pipe_init(t_pipex *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		return (1);
	pipex->outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->outfile < 0)
		return (1);
	if (pipe(pipex->port) < 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (error_msg());
	if (pipe_init(&pipex, argv))
		return (write(2, &"Error pipe\n", 11));
	pipex.path = get_path(envp);
	if (!divide_command(&pipex, argv))
	{
		pipex_free(&pipex);
		return (error_msg());
	}
	pipex.child1 = fork();
	if (pipex.child1 == 0)
		call_child1(pipex, envp);
	pipex.child2 = fork();
	if (pipex.child2 == 0)
		call_child2(pipex, envp);
	close_pipes(&pipex);
	waitpid(pipex.child1, NULL, 0);
	waitpid(pipex.child2, NULL, 0);
	childs_free(&pipex);
	pipex_free(&pipex);
	return (0);
}