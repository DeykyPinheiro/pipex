/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 08:16:25 by demikael          #+#    #+#             */
/*   Updated: 2022/03/06 08:16:56 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_default_pipe(t_pipex *pipe, int argc, char **argv, char **envp)
{
	pipe->argc = argc;
	pipe->argv = argv;
	pipe->envp = envp;
}
