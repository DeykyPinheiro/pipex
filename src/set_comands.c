/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_comands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:01:14 by demikael          #+#    #+#             */
/*   Updated: 2022/03/06 18:25:43 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	set_comands(t_pipex *pipex)
{
	int	offset_comand;
	int	n;

	offset_comand = offset_first_comand(pipex);
	pipex->path_cmd = ft_calloc(sizeof(char *), pipex->argc - offset_comand);
	if (!pipex->path_cmd)
		return (1);
	pipex->cmd = ft_calloc(sizeof(char **), (pipex->argc - offset_comand));
	if (!pipex->cmd)
	{
		return (1);
	}
	n = valid_comands(pipex, offset_comand);
	if (n == 1)
		return (1);
	if (n == 127)
		return (127);
	return (0);
}
