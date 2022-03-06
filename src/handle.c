/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:13:48 by demikael          #+#    #+#             */
/*   Updated: 2022/03/06 13:15:01 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_ptr_ptr(char **ptr)
{
	char	**aux;

	aux = ptr;
	while (*ptr)
		free (*ptr++);
	free (aux);
}

void	ft_exit(t_pipex *pipex)
{
	int	i;
	int	j;

	i = -1;
	free_ptr_ptr(pipex->path_cmd);
	while (pipex->cmd[++i])
	{
		j = -1;
		while (pipex->cmd[i][++j])
			free(pipex->cmd[i][j]);
		free(pipex->cmd[i]);
	}
	free(pipex->cmd);
}
