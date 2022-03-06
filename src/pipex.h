/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:56:12 by demikael          #+#    #+#             */
/*   Updated: 2022/03/06 12:57:57 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include "../libraries/libft/src/libft.h"
# include <stdio.h>

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		infile;
	int		outfile;
	char	**path_cmd;
	char	***cmd;
}	t_pipex;

void	set_default_pipe(t_pipex *pipe, int argc, char **argv, char **envp);
int		offset_first_comand(t_pipex *pipex);
int		search_index_path(t_pipex *pipex);
int		valid_comands(t_pipex *pipex, int offset_comand);
int		set_comands(t_pipex *pipex);
int		exec_comands(t_pipex *pipex);
void	free_ptr_ptr(char **ptr);
void	ft_exit(t_pipex *pipex);

#endif
