#include "pipex.h"

void	swap_input_for_channel1(t_chanel channels)
{
		dup2(channels.chanel2[0], STDIN_FILENO);
		dup2(channels.chanel1[1], STDOUT_FILENO);
}

void	swap_input_for_channel2(t_chanel channels)
{
		dup2(channels.chanel1[0], STDIN_FILENO);
		dup2(channels.chanel2[1], STDOUT_FILENO);
}

void	swap_input_for_master1(t_chanel channels)
{
		dup2(channels.chanel1[0], STDIN_FILENO);
		dup2(channels.master[1], STDOUT_FILENO);
}

void	swap_input_for_master2(t_chanel channels)
{
		dup2(channels.chanel2[0], STDIN_FILENO);
		dup2(channels.master[1], STDOUT_FILENO);
}
int	main(int argc, char *argv[])
{
	// apagar essa parter
	printf("argc: %i\n", argc);
	for ( int i = 0; i < argc; i++)
	{
		printf("argv[%i] => %s\n", i, argv[i]);
	}
	printf("====================================\n");
	// até aqui

	// char **test;
	// char *a = "tr a c";
	// test = ft_split(a, ' ');
	// for (int i = 0; test[i]; i++)
	// 	printf("%s\n", test[i]);

	t_chanel chanels;
	int	pid;
	int infile;
	int outfile;
	int i;

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_RDONLY | O_WRONLY);

	pipe(chanels.chanel1);
	pid = fork();
	if (pid == 0)
	{
		// comand(infile, fd, cat)
		printf("filho 1\n");
		printf("comando: %s\n", argv[2]);
		dup2(infile, STDIN_FILENO);
		dup2(chanels.chanel1[1], STDOUT_FILENO);
		close(chanels.chanel1[0]);
		close(chanels.chanel1[1]);
		execlp("cat", "cat", NULL);
	}
	waitpid(pid, NULL, 0);


	i = 3; // ja entra no 3
	printf("====================================\n");
	printf("inicio do loop: do comando %i até %d\n", i, argc - 3);
	while (i <= argc - 3)
	{
		printf("filho %d\n", i);
		printf("comando: %s\n", argv[i]);
		if ((i % 2 == 1 && i == argc - 3 )|| (i % 2 == 0 && i == argc - 3))
		{
			pipe(chanels.master);
		}
		else if (i % 2 != 0)
		{
			printf("pipe chanel 2\n");
			pipe(chanels.chanel2);
		}
		else if (i % 2 == 0)
		{
			printf("pipe chanel 1\n");
			pipe(chanels.chanel1);
		}

		pid = fork();
		if (pid == 0)
		{
			if (i % 2 == 1 && i == argc - 3)
			{
				printf("ultima execucao par i: %d\n", i);
				swap_input_for_master1(chanels);
				close(chanels.chanel1[0]);
				close(chanels.chanel1[1]);
				comands(argv[i]);
			}
			else if (i % 2 == 0 && i == argc - 3)
			{
				// printf("i: %d\n", i);
				printf("ultima execucao impar i: %d\n", i);
				swap_input_for_master2(chanels);
				close(chanels.chanel2[0]);
				close(chanels.chanel2[1]);
				comands(argv[i]);
			}
			else if (i % 2 == 0 && i != argc - 3)
			{
				swap_input_for_channel1(chanels);
				close(chanels.chanel2[0]);
				close(chanels.chanel2[1]);
				close(chanels.chanel1[0]);
				close(chanels.chanel1[1]);
				comands(argv[i]);
			}
			else if (i % 2 == 1 && i != argc - 3)
			{
				swap_input_for_channel2(chanels);
				close(chanels.chanel1[0]);
				close(chanels.chanel1[1]);
				close(chanels.chanel2[0]);
				close(chanels.chanel2[1]);
				comands(argv[i]);
			}
		}
		if (i % 2 == 1)
		{
			printf("fechei canal 1 i é impar\n");
			close(chanels.chanel1[0]);
			close(chanels.chanel1[1]);
		}
		else if (i % 2 == 0)
		{
			printf("fechei canal 2 i é par\n");
			close(chanels.chanel2[0]);
			close(chanels.chanel2[1]);
		}
		waitpid(pid, NULL, 0);
		printf("final do filho %d\n\n", i);
		i++;
	}
	printf("final do loop %d\n",i);
	printf("====================================\n");

	pid = fork();
	if (pid == 0)
	{
		printf("filho %d\n", i);
		dup2(chanels.master[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(chanels.master[0]);
		close(chanels.master[1]);
		execlp("grep", "grep", "line a", NULL);
	}
	close(chanels.master[0]);
	close(chanels.master[1]);
	close(infile);
	close(outfile);
	waitpid(pid, NULL, 0);
	printf("final\n");
	return (0);
}






// if (argc > 3 && argc <4)
// {
// }


