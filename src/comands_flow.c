/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands_flow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 08:17:11 by demikael          #+#    #+#             */
/*   Updated: 2022/03/06 12:52:16 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_comands(t_pipex *pipex)
{
	int		fd[2];
	pid_t	pid;
	int		infile;
	int		outfile;
	int		i;

	infile = open(pipex->argv[offset_first_comand(pipex) - 1], O_RDONLY, 0777);
	if (infile == -1)
	{
		perror("");
		ft_exit(pipex);
		return (1);
	}
	outfile = open(pipex->argv[pipex->argc - 1], \
	O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		ft_exit(pipex);
		return (1);
	}
	i = 0;
	while (pipex->cmd[i])
	{
		if (pipe(fd) < 0)
			return (1);
		if ((pid = fork()) == -1)
		{
			perror("Error in fork\n");
			return (1);
		}
		else if (pid == 0)
		{
			dup2(infile, STDIN_FILENO);
			if (pipex->cmd[i + 1] != NULL)
				dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			if (execve(pipex->path_cmd[i], pipex->cmd[i], NULL) == -1)
			{
				ft_exit(pipex);
				return (1);
			}
			exit (1);
		}
		else
		{
			close(fd[1]);
			infile = fd[0];
			i++;
		}
		dup2(outfile, STDOUT_FILENO);
	}
	ft_exit(pipex);
	return (0);
}
