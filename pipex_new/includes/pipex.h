/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:23 by iortega-          #+#    #+#             */
/*   Updated: 2023/07/16 19:24:31 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	pid_t	child1;
	pid_t	child2;
	int		port[2];
	char	**path;
	char	**cmd1;
	char	**cmd2;
	char	*cmd_path1;
	char	*cmd_path2;
}t_pipex;

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	close_pipes(t_pipex *pipex);
void	free_doublearray(char **array);
void	pipex_free(t_pipex *pipex);
void	childs_free(t_pipex *pipex);
void	call_child1(t_pipex pipex, char **envp);
void	call_child2(t_pipex pipex, char **envp);
void	childs_free(t_pipex *pipex);
char	**get_path(char **envp);
char	*get_cmd_path(char **paths, char *cmd);
int		divide_command(t_pipex *pipex, char **argv);
int		error_msg(void);
int		pipe_init(t_pipex *pipex, char **argv);

#endif