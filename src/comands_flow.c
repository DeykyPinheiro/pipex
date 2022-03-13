/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 08:17:11 by demikael          #+#    #+#             */
/*   Updated: 2022/03/13 11:03:10 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *pipex, char **cmd, int index, int fd[])
{
	dup2(pipex->infile, STDIN_FILENO);
	close(fd[0]);
	if (index == 1)
		dup2(fd[1], STDOUT_FILENO);
	if (index == 2)
		dup2(pipex->outfile, STDOUT_FILENO);
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		free_ptr_ptr(cmd);
		exit(1);
	}
}

int	run_comands(t_pipex *pipex, char **cmd, int index)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
		child_process(pipex, cmd, index, fd);
	pipex->infile = fd[0];
	close(fd[1]);
	free_ptr_ptr(cmd);
	return (0);
}
