#include "pipex.h"



void	free_ptr_ptr(char **ptr)
{
	char	**aux;

	aux = ptr;
	while (*ptr)
		free (*ptr++);
	free (aux);
}

void	ft_exit(t_pipex *pipex)
{
	int i;
	int j;

	i = -1;
	free_ptr_ptr(pipex->path_cmd);
	while(pipex->cmd[++i]){
		j = -1;
		while(pipex->cmd[i][++j])
			free(pipex->cmd[i][j]);
		free(pipex->cmd[i]);
	}
	free(pipex->cmd);

}

