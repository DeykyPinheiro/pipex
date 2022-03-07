/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:13:48 by demikael          #+#    #+#             */
/*   Updated: 2022/03/06 21:44:03 by demikael         ###   ########.fr       */
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

int	message_error(t_pipex *pipex, char *complete_path, char **paths, int offset)
{
	perror("");
	free_ptr_ptr(paths);
	ft_exit(pipex);
	free(complete_path);
	if (offset == 3)
		return (127);
	return (1);
}

int	offset_first_comand(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->argc == 5)
		i = 2;
	return (i);
}
