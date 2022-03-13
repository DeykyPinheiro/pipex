/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:53:50 by demikael          #+#    #+#             */
/*   Updated: 2022/03/13 11:20:57 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		index;
	char	**cmd;

	index = 0;
	if (argc == 5)
	{
		ft_bzero(&pipex, sizeof(t_pipex));
		set_default_pipe(&pipex, argc, argv, envp);
		while (++index <= argc - 3)
		{
			cmd = set_comands(argv[index + 1], envp);
			if (cmd)
				run_comands(&pipex, cmd, index);
			else
			{
				if (index == 2)
					ft_exit(&pipex, cmd, index);
			}
		}
		close(pipex.infile);
		close(pipex.outfile);
	}
	return (0);
}
