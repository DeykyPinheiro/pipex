#include "pipex.h"

void	set_default_pipe(t_pipex *pipe, int argc, char **argv, char **envp)
{
	pipe->argc = argc;
	pipe->argv = argv;
	pipe->envp = envp;
}
