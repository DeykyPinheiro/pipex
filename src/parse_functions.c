/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:11:18 by demikael          #+#    #+#             */
/*   Updated: 2022/03/06 18:24:52 by demikael         ###   ########.fr       */
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

char	*make_cmd(t_pipex *pipex, int offset_cmd)
{
	char	**cmd;
	char	*aux;

	cmd = ft_split(pipex->argv[offset_cmd], ' ');
	aux = ft_strdup(cmd[0]);
	free_ptr_ptr(cmd);
	return (aux);
}

char	*make_path_comand(t_pipex *pipex, char *path, int offset_cmd)
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

void	set_comand_valid(t_pipex *pipex, int offset_comand, char *complete_path)
{
	pipex->path_cmd[offset_comand - offset_first_comand(pipex)] = \
	ft_strdup(complete_path);
	pipex->cmd[offset_comand - offset_first_comand(pipex)] = \
	ft_split(pipex->argv[offset_comand], ' ');
	free(complete_path);
}

int	valid_comands(t_pipex *pipex, int offset)
{
	int		i;
	char	**paths;
	char	*complete_path;

	paths = ft_split(pipex->envp[search_index_path(pipex)], ':');
	while (offset < pipex->argc - 1)
	{
		i = -1;
		while (paths[++i])
		{
			complete_path = make_path_comand(pipex, paths[i], offset);
			if (access(complete_path, X_OK | F_OK) == 0)
			{
				set_comand_valid(pipex, offset, complete_path);
				break ;
			}
			else if (paths[i + 1] == 0)
				return (message_error(pipex, complete_path, paths, offset));
			else
				free(complete_path);
		}
		offset++;
	}
	free_ptr_ptr(paths);
	return (0);
}
