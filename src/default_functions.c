/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 08:16:25 by demikael          #+#    #+#             */
/*   Updated: 2022/03/13 11:00:41 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_default_pipe(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->infile = open(pipex->argv[1], O_RDONLY);
	pipex->outfile = open(pipex->argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipex->infile == -1 || pipex->outfile == -1)
	{
		close(pipex->infile);
		close(pipex->outfile);
		exit (1);
	}
}
