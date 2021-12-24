// #include "pipex.h"


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
#include "../libraries/libft/src/libft.h"
#include <stdio.h>

int	main(int argc, char* argv[], char* envp[]) // envp var padrao de ambiente
{
	int i = 0;
	while(i < argc)
	{
		printf("argv[%i] %s\n" , i, argv[i]);
		i++;
	}
	printf("========================================\n");
	i = 0;
	while(envp[i])
	{
		printf("envp[%i] %s\n" , i, envp[i]);
		i++;
	}
	ft_strlen("10");
	return (0);
}
