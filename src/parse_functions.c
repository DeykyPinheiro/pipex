/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:11:18 by demikael          #+#    #+#             */
/*   Updated: 2022/03/13 11:21:48 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
