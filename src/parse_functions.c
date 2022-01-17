#include "pipex.h"

int	search_index_path(t_pipex *pipex)
{
	// printf("estou na seach_path\n");
	int	path_index;

	path_index = 0;
	while (pipex->envp[path_index] && \
	!ft_strnstr(pipex->envp[path_index],"PATH", 5))
		path_index++;
	return (path_index);
}

int	offset_first_comand(t_pipex *pipex)
{
	int i;

	i = 0;
	if (pipex->argc == 5)
		i = 2;
	return (i);
}

char *make_cmd(t_pipex *pipex, int offset_cmd)
{
	char **cmd;

	cmd = ft_split(pipex->argv[offset_cmd], ' ');
	// printf("make_cmd : %s\n", *cmd);
	return(*cmd);
}

char *make_path_comand(t_pipex *pipex, char *path, int offset_cmd)
{
	char	*path_front_slash;
	char	*complet_path;
	char	*cmd;

	// construir comando
	// cmd = pipex->argv[offset_cmd]
	cmd = make_cmd(pipex, offset_cmd);

	path_front_slash = ft_strjoin(path, "/");
	complet_path = ft_strjoin(path_front_slash, cmd);
	// printf("completo: %s\n", complet_path);
	return (complet_path);
}

void valid_commands(t_pipex *pipex, int offset_comand)
{
	int		i;
	char	**paths;
	char	*complete_path;

	// offset_comand = offset_first_comand(pipex);
	i = search_index_path(pipex);
	paths = ft_split(pipex->envp[i], ':');
	// printf("[%d] - %s\n", i, pipex->envp[i]);
	i = -1;
	// pipex->cmd = (char ***)malloc(sizeof(char ***) * \
	// (pipex->argc - offset_comand + 1));
	// if(!pipex->cmd)
	// 	return ;
	// printf("tratar aprostofo dentro do make_cmd\n");
	while (paths[++i])
	{
		complete_path = make_path_comand(pipex, paths[i], offset_comand);
		// printf("caminho completo: %s\n", complete_path);
		if (access(complete_path, X_OK | F_OK) == 0)
		{
			pipex->cmd[0] = &complete_path;
			// complete_cmd(pipex, offset_comand);
			// printf("offset_cmd: %d\n", offset_comand - 1);
			pipex->cmd[offset_comand - 1] = ft_split(pipex->argv[offset_comand], ' ');
			// printf("estou dentro do cmd: %s\n", *pipex->cmd[0]);
			// set_comands(pipex, offset_comand);
			break;
		}
		else
		{
			// printf("[%d] - invalido\n", i);
		}
		free(complete_path);
		// printf("[%d] %s\n", i, paths[i]);
	}
	free(paths);
	// i = -1;
	// while (pipex->cmd[offset_comand - 1][++i])
		// printf("dentro do negocio [%d][%d] %s\n", offset_comand - 1, i, pipex->cmd[offset_comand - 1][i]);
// printf("teminei o valid_paths\n");
}
// PATH


