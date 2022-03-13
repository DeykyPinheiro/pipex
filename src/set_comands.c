/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_comands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:01:14 by demikael          #+#    #+#             */
/*   Updated: 2022/03/13 10:57:08 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**set_comands(char *comands, char *envp[])
{
	char	**cmd;
	char	**env;

	space_treat_comands(comands);
	cmd = ft_split(comands, ' ');
	reverse_space_treat_comands(cmd);
	cmd = treat_comands(cmd);
	while (ft_strncmp("PATH=", *envp, 4) && *envp++)
		;
	env = ft_split(*envp, ':');
	return (cmd_valid(env, cmd));
}
