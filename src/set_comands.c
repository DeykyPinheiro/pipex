#include "pipex.h"

// void	complete_cmd(t_pipex *pipex, int offset_comand)
// {
	// pipex->cmd[offset_comand - 1] = ft_split(pipex->argv[offset_comand], ' ');
	// printf("to na set comands %d\n", offset_comand - 1);
	// int i = 0;
	// while (pipex->cmd[offset_comand - 1][i])
	// {
	// 	printf("[%d][%d]: %s\n", offset_comand - 1, i, pipex->cmd[offset_comand - 1][i]);
	// 	i++;
	// }
	// printf("SAi\n");
// }

void	set_comands(t_pipex *pipex)
{
	int offset_comand;

	offset_comand = offset_first_comand(pipex);
	pipex->cmd = (char ***)malloc(sizeof(char ***) * \
	(pipex->argc - offset_comand + 1));
	if(!pipex->cmd)
		return ;
	while (offset_comand < pipex->argc - 1)
	{
		valid_commands(pipex, offset_comand);
		offset_comand++;
	}
	// printf("[%d] comando\n", offset_comand - 1);
}
