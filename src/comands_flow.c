/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 08:17:11 by demikael          #+#    #+#             */
/*   Updated: 2022/03/06 17:33:16 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(t_pipex *pipex)
{
	pipex->infile = \
	open(pipex->argv[offset_first_comand(pipex) - 1], O_RDONLY, 0777);
	if (pipex->infile == -1)
	{
		perror("");
		ft_exit(pipex);
		return (1);
	}
	pipex->outfile = open(pipex->argv[pipex->argc - 1], \
	O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->outfile == -1)
	{
		ft_exit(pipex);
		return (1);
	}
	return (0);
}

int	child_process(t_pipex *pipex, int fd[], int i)
{
	dup2(pipex->infile, STDIN_FILENO);
	if (pipex->cmd[i + 1] != NULL)
		dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	if (execve(pipex->path_cmd[i], pipex->cmd[i], NULL) == -1)
	{
		ft_exit(pipex);
		return (1);
	}
	return (0);
}

void	close_process(t_pipex *pipex, int fd[])
{
	close(fd[1]);
	pipex->infile = fd[0];
	pipex->i++;
}

int	exec_comands(t_pipex *pipex)
{
	int		fd[2];
	pid_t	pid;

	if (open_file(pipex))
		return (1);
	pipex->i = 0;
	while (pipex->cmd[pipex->i])
	{
		if (pipe(fd) < 0)
			return (1);
		pid = fork();
		if (pid == -1)
		{
			perror("");
			return (1);
		}
		else if (pid == 0)
			child_process(pipex, fd, pipex->i);
		else
			close_process(pipex, fd);
		dup2(pipex->outfile, STDOUT_FILENO);
	}
	ft_exit(pipex);
	return (0);
}
