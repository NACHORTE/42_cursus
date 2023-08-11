/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:54:40 by iortega-          #+#    #+#             */
/*   Updated: 2023/08/11 12:45:35 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error_msg(void)
{
	write(2, &"Something went wrong.\n", 22);
	return (1);
}

int	pipe_init(t_pipex *pipex, char **argv, int *err)
{
	*err = 0;
	if (pipe(pipex->port) < 0)
	{
		perror(NULL);
		return (1);
	}
	pipex->outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex->outfile < 0)
	{
		perror(NULL);
		return (1);
	}
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		perror(NULL);
		*err = 1;
		return (0);
	}
	return (0);
}

int	child_init(t_pipex *pipex, char **envp, int err)
{
	int	status;

	if (err == 0)
	{
		pipex->child1 = fork();
		if (pipex->child1 == 0)
			call_child1(*pipex, envp);
	}
	pipex->child2 = fork();
	if (pipex->child2 == 0)
		call_child2(*pipex, envp);
	close_pipes(pipex);
	if (err == 0)
		waitpid(pipex->child1, NULL, 0);
	waitpid(pipex->child2, &status, 0);
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;
	int		err;

	if (argc != 5)
		return (error_msg());
	if (pipe_init(&pipex, argv, &err))
		return (errno);
	pipex.path = get_path(envp);
	if (!divide_command(&pipex, argv))
	{
		pipex_free(&pipex);
		return (error_msg());
	}
	status = child_init(&pipex, envp, err);
	childs_free(&pipex);
	pipex_free(&pipex);
	return ((status & 0xFF00) >> 8);
}
