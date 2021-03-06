/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:56:12 by demikael          #+#    #+#             */
/*   Updated: 2022/03/13 11:23:12 by demikael         ###   ########.fr       */
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
# include "../libraries/utils/src/utils.h"
# include <stdio.h>

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		infile;
	int		outfile;
	char	**cmd;
	int		i;
	char	**path_cmd;
}	t_pipex;

void	set_default_pipe(t_pipex *pipe, int argc, char **argv, char **envp);
char	**set_comands(char *comands, char *envp[]);
void	free_ptr_ptr(char **ptr);
void	ft_exit(t_pipex *pipex, char **cmd, int index);
char	**cmd_valid(char **paths, char **cmd);
int		run_comands(t_pipex *pipex, char **cmd, int index);
void	reverse_space_treat_comands(char **comands);
char	**treat_comands(char **cmd);
char	*new_comand(char *cmd);
void	child_process(t_pipex *pipex, char **cmd, int index, int fd[]);
void	space_treat_comands(char *comands);
#endif
