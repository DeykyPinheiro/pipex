#include "pipex.h"


// /*
// ** pipex.c - multipipes support
// */

// #include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>

// /*
//  * loop over commands by sharing
//  * pipes.
//  */
// static void pipeline(char ***cmd)
// {


// 	int fd[2];
// 	pid_t pid;
// 	int outfile;
// 	int fdd = 0;				/* Backup */
// 	int i;
// 	outfile = open("output_file.txt", O_RDONLY | O_WRONLY);

// 	i =0;
// 	while (*cmd != NULL)
// 	{
// 		printf("cmd: %s\n", **cmd);
// 		printf("filho %i\n",i);
// 		pipe(fd);				/* Sharing bidiflow */
// 		if ((pid = fork()) == -1)
// 		{
// 			perror("fork");
// 			exit(1);
// 		}
// 		else if (pid == 0)
// 		{
// 			dup2(fdd, STDIN_FILENO);
// 			if (*(cmd + 1) != NULL) {
// 				dup2(fd[1], 1);
// 			}
// 			close(fd[0]);
// 			execvp((*cmd)[0], *cmd);
// 			// exit(1);
// 		}
// 		else
// 		{
// 			wait(NULL); 		/* Collect childs */
// 			close(fd[1]);
// 			fdd = fd[0]; // aqui é fd temporario
// 			cmd++;
// 			i++;
// 		}
// 		dup2(outfile, STDOUT_FILENO);
// 	}
// }

// /*
//  * Compute multi-pipeline based
//  * on a command list.
//  */
// int main(int argc, char *argv[])
// {
// 	char *ls[] = {"ls", "-al", NULL}; // **
// 	char *rev[] = {"rev", NULL}; // **
// 	char *nl[] = {"nl", NULL}; // **
// 	char *cat[] = {"cat", "-e", NULL}; // **
// 	char **cmd[] = {ls, rev, nl, cat, NULL}; // ***

// 	printf("argc: %i\n", argc);
// 	for ( int i = 0; i < argc; i++)
// 	{
// 		printf("argv[%i] => %s\n", i, argv[i]);
// 	}
// 	printf("====================================\n");

// 	pipeline(cmd);
// 	return (0);
// }

// #include "pipex.h"

int	main(int argc, char* argv[], char* envp[]) // envp var padrao de ambiente
{
	(void)argc;
	(void)argv;
	(void)envp;

	// programa comeca aqui
	t_pipex	pipex;

	ft_bzero(&pipex, sizeof(t_pipex));
	set_default_pipe(&pipex, argc, argv, envp);

	//TESTES

	// mostra todos os comandos dento do argv
	// int i = 0;
	// while(i < pipex.argc)
	// {
	// 	printf("argv[%i] %s\n" , i, pipex.argv[i]);
	// 	i++;
	// }
	// printf("========================================\n");

	// mostra todos os caminhos
	// int j = 0;
	// while(pipex.envp[j])
	// {
	// 	printf("envp[%i] %s\n" , j, pipex.envp[j]);
	// 	j++;
	// }

	// printf("o tamanho final é : %d\n", pipex.argc);
	if (argc == 5)
	{
		printf("caminho de execucao dos comandos\n");
		set_comands(&pipex);


		// //mostrando comos os comandos ficaram dentro do cmd
		// j = 1;
		// while (pipex.cmd[j])
		// {
		// 	printf("path: %s\n", *pipex.cmd[0]);
		// 	i = 0;
		// 	while (pipex.cmd[j][i])
		// 	{
		// 	// printf("valor de j: %d\n", j);
		// 		printf("[%d][%d] %s\n", j, i, pipex.cmd[j][i]);
		// 		i++;
		// 	}
		// 	j++;
		// }
	}
	else
	{
		printf("numero de parametros errados\n");
	}


	printf("\n======================================================\n");
	printf("fim de execucao\n");
	return (0);
}

