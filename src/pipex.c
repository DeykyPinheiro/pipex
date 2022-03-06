/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:53:50 by demikael          #+#    #+#             */
/*   Updated: 2022/03/06 12:55:51 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	ft_bzero(&pipex, sizeof(t_pipex));
	set_default_pipe(&pipex, argc, argv, envp);
	if (argc == 5)
	{
		if (set_comands(&pipex))
			return (1);
		if (exec_comands(&pipex))
			return (1);
	}
	return (0);
}
