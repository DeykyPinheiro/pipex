#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

// #include <sys/stat.h>
// #include <sys/types.h>
// #include <sys/errno.h>

// dup duplicar o fd e usa o fd mais baixo sem uso
// dup2 dubpla o fd e usa o fd especificado

// meu contador até 10
// int main()
// {
// 	int	id;
// 	int	num;

// 	id = fork();
// 	if(id != 0)
// 	{
// 		num = 1;
// 	}
// 	else
// 	{
// 		num = 6;
// 		// wait();
// 	}
// 	for (int i = num; i < num + 5; i++)
// 	{
// 	printf("%i\n", i);
// 	}
// 	// if (id != 0)
// 	// printf("=====\n");
// }

// diferencia o que é pai e o que é filho
// int	main(int argc, char *argv[])
// {
// 	int id;

// 	id = fork();
// 	if (id == 0)
// 	{
// 		printf("hello world from child process id: %i\n", id);
// 	}
// 	else
// 	{
// 		printf("hello world from main process maid: %i\n", id);
// 	}
// 	return (0);
// }

// mostra que imprime 2^n sendo n o numero de forks
// int	main(int argc, char *argv[])
// {
// 	fork();
// 	fork();
// 	fork();
// 	fork();
// 	printf("this is a teste\n");
// }

// // imprime tres
// int	main(int argc, char *argv[])
// {
// 	int id;
// 	id = fork();
// 	if (id != 0)
// 	{
// 		printf("processo filho em baixo\n");
// 		fork();
// 	}
// 	printf("hello world\n");
// }

// mostra como imprimir de 1 a 10 com fork
// int	main(int argc, char *argv[])
// {
// 	int id;

// 	id = fork();
// 	int n;
// 	if (id == 0)
// 	{
// 		n = 1;
// 	}
// 	else
// 	{
// 		n = 6;
// 	}
// 	if (id != 0)
// 		wait();
// 	for (int i = n; i < n + 5; i++)
// 	{
// 		printf("%i\n", i);
// 		fflush(stdout);
// 	}
// 	if (id == 0)
// 	{
// 		printf("=====================\n");
// 	}
// 	return (0);
// }

// // imprimindo processo id
// int	main(int argc, char *argv[])
// {
// 	int	id;
// 	int	res;
// 	id = fork();
// 	if (id == 0)
// 	{
// 		sleep(1);
// 	}
// 	printf("Current id: %d, Parent id: %d\n", getpid(), getppid());
// 	res = wait(NULL);
// 	if ( res == -1)
// 	{
// 		printf("no children to wait for\n");
// 	}
// 	else
// 	{
// 		printf("%d finished execution\n", res);
// 	}
// 	return (0);
// }

// // calling fork multiple time [não terminado, voltar quando precisar]
// int	main(int argc, char *argv[])
// {
// 	int id1;
// 	int id2;

// 	id1 = fork();
// 	id2 = fork();
// 	return (0);
// }


// // communication between processes
// int	main(int argc, char *argv[])
// {
// 	int fd[2];
// 	int id;

// 	if(pipe(fd) == -1)
// 	{
// 		printf("a error ocorred with opening the pipe\n");
// 		return (1);
// 	}
// 	id = fork();
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		int x;
// 		printf("input a number: \n");
// 		scanf("%d", &x);
// 		if (write(fd[1], &x, sizeof(int)) == -1)
// 		{
// 			printf("an error ocorred with writing to the pipe");
// 			return (2);
// 		}
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		int y;
// 		if (read(fd[0], &y, sizeof(int)) == -1)
// 		{
// 			printf("an error ocorred with reading to the pipe");
// 			return (2);
// 		}
// 		close(fd[0]);
// 		printf("got child processes %d\n", y);
// 	}

// 	return (0);
// }


// int	main(int argc, char *argv[])
// {
// 	if (mkfifo("myfifo1", 0777) == -1)
// 	{
// 		if (errno != EEXIST)
// 		{
// 			printf("could not create file\n");
// 			return (1);
// 		}
// 	}
// 	printf("opening\n");
// 	int fd = open("myfifo1", O_WRONLY);
// 	printf("opened\n");
// 	int x = 'Z';
// 	if (write(fd, &x, sizeof(x)) == -1)
// 	{
// 		return (2);
// 	}
// 	printf("written\n");
// 	close(fd);
// 	printf("Closed fd\n");
// 	return (0);
// }

// two way communication betwen process (using pipes)
// int	main(int argc, char *argv[])
// {
// 	// 5 => 4 * 5 = 20 => 20
// 	int p1[2];
// 	if (pipe(p1) == -1)
// 	{
// 		return (1);
// 	}
// 	int pid = fork();
// 	if (pid == -1)
// 	{
// 		return (2);
// 	}
// 	if (pid == 0)
// 	{
// 		printf("child process\n");
// 		int x;
// 		if (read(p1[0], &x, sizeof(x)) == -1)
// 		{
// 			return (3);
// 		}
// 		printf("recevid %d\n", x);
// 		x *= 4;
// 		if (write(p1[1], &x, sizeof(x)) == -1)
// 		{
// 			return (4);
// 		}
// 		printf("wrote %d\n", x);
// 	}
// 	else
// 	{

// 	}

// 	return (0);
// }


// int	main(int argc, char *argv[])
// {
// 	printf("argc: %i\n", argc);
// 	for ( int i = 0; i < argc; i++)
// 	{
// 		printf("argv[%i] => %s\n", i, argv[i]);
// 	}
// 	printf("====================================\n");
// 	int fd[2];

// 	if( pipe(fd) == -1)
// 	{
// 		return (1);
// 	}

// 	int pid1 = fork();
// 	if (pid1 < 0)
// 	{
// 		return (2);
// 	}

// 	// process child
// 	if (pid1 == 0)
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("ping", "ping", "-c", "5", "google.com", NULL);
// 	}

// 	int pid2;
// 	pid2 = fork();
// 	if (pid2 < 0)
// 	{
// 		return (3);
// 	}

// 	// second child, grep
// 	if (pid2 == 0)
// 	{
// 		dup2(argv[2], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("grep", "grep", "rtt", NULL);
// 	}

// 	close(fd[0]);
// 	close(fd[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
// }

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

	int	fd[2];
	int	pid1;
	int	pid2;
	int file1;
	int file2;

	pipe(fd); // verificar depois
	pid1 = fork();
	if (pid1 == 0)
	{
		// 1 = tela;
		// antes escrevia na tela, agora no file1
	file1 = open(argv[1], O_RDONLY); // realizar validacao depois
		dup2(file1, STDIN_FILENO); // fd[0] tbm pode
		// antes escrevia na tela, agora escreve no fd[1]
		dup2(fd[1], STDOUT_FILENO); // mudando a saida para
		// 1 = fd[1];
		close(fd[0]);
		close(fd[1]);
		execlp("ls", "ls", NULL);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		// leio do ultimo processo
	file2 = open(argv[3], O_RDONLY | O_WRONLY);
		dup2(fd[0], STDIN_FILENO);
		dup2(file2, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "a.out", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	close(file1);
	close(file2);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
