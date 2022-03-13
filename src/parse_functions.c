/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:11:18 by demikael          #+#    #+#             */
/*   Updated: 2022/03/13 10:53:45 by demikael         ###   ########.fr       */
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

char	*make_path_comand(char *path, char **cmd)
{
	char	*path_front_slash;
	char	*complet_path;

	path_front_slash = ft_strjoin(path, "/");
	complet_path = ft_strjoin(path_front_slash, cmd[0]);
	free(path_front_slash);
	return (complet_path);
}

char	**cmd_valid(char **paths, char **cmd)
{
	char	*temp;
	char	*temp1;
	char	**temp_env;

	temp_env = paths;
	while (*paths)
	{
		temp = ft_strjoin(*paths++, "/");
		temp1 = ft_strjoin(temp, cmd[0]);
		if (access(temp1, F_OK) == 0)
		{
			free_ptr_ptr(temp_env);
			free(temp);
			free(cmd[0]);
			cmd[0] = temp1;
			return (cmd);
		}
		free(temp);
		free(temp1);
	}
	write(2, "comand not found: ", 18);
	write(2, cmd[0], ft_strlen(cmd[0]));
	free_ptr_ptr(temp_env);
	free_ptr_ptr(cmd);
	return (NULL);
}

char	**treat_comands(char **cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[i])
	{
		j = 0;
		while (cmd[i][j])
		{
			if (cmd[i][j] == 39)
			{
				if (cmd[i][j + 1] == '\0')
					break ;
				cmd[i] = new_comand(cmd[i]);
			}
			j++;
		}
		i++;
	}
	return (cmd);
}
