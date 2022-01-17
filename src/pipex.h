#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <unistd.h>


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#include "../libraries/libft/src/libft.h"
#include <stdio.h>

typedef struct s_pipex
{
	int	argc;
	char	**argv;
	char	**envp;
	int	infile;
	int	outfile;
	char **path_comands;
	char ***cmd;
}	t_pipex;

void	set_default_pipe(t_pipex *pipe, int argc, char **argv, char **envp);
int		offset_first_comand(t_pipex *pipex);
int		search_index_path(t_pipex *pipex);
void	valid_commands(t_pipex *pipex, int offset_comand);
void	set_comands(t_pipex *pipex);
// void	complete_cmd(t_pipex *pipex, int offset_comand);

# endif
