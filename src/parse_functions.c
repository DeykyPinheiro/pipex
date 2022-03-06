/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:11:18 by demikael          #+#    #+#             */
/*   Updated: 2022/03/06 13:06:57 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	search_index_path(t_pipex *pipex)
{
	int	path_index;

	path_index = 0;
	while (pipex->envp[path_index] && \
	!ft_strnstr(pipex->envp[path_index], "PATH", 5))
		path_index++;
	return (path_index);
}

int	offset_first_comand(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->argc == 5)
		i = 2;
	return (i);
}

char	*make_cmd(t_pipex *pipex, int offset_cmd)
{
	char	**cmd;
	char	*aux;

	cmd = ft_split(pipex->argv[offset_cmd], ' ');
	aux = ft_strdup(cmd[0]);
	free_ptr_ptr(cmd);
	return (aux);
}

char *make_path_comand(t_pipex *pipex, char *path, int offset_cmd)
{
	char	*path_front_slash;
	char	*complet_path;
	char	*cmd;

	cmd = make_cmd(pipex, offset_cmd);
	path_front_slash = ft_strjoin(path, "/");
	complet_path = ft_strjoin(path_front_slash, cmd);
	free(path_front_slash);
	free(cmd);
	return (complet_path);
}

int valid_comands(t_pipex *pipex, int offset_comand)
{
	int		i;
	char	**paths;
	char	*complete_path;

	i = search_index_path(pipex);
	paths = ft_split(pipex->envp[i], ':');
	while (offset_comand < pipex->argc - 1)
	{
		i = -1;
		while (paths[++i])
		{
			complete_path = make_path_comand(pipex, paths[i], offset_comand);
			if (access(complete_path, X_OK | F_OK) == 0)
			{
				pipex->path_cmd[offset_comand - offset_first_comand(pipex)] =
				ft_strdup(complete_path);
				pipex->cmd[offset_comand - offset_first_comand(pipex)] =
				ft_split(pipex->argv[offset_comand], ' ');
				free(complete_path);
				break;
			}
			else if (paths[i + 1] == 0)
			{
				dprintf(2, "command not found\n");
				free_ptr_ptr(paths);
				ft_exit(pipex);
				free(complete_path);
				return (1);
			}
			else
				free(complete_path);
		}
		offset_comand++;
	}
	free_ptr_ptr(paths);
	return (0);
}


