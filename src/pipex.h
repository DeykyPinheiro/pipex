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

typedef struct s_pipe
{
	int	infile;
	int	outfile;
	int	**chanel;
}	t_pipe;

# endif
