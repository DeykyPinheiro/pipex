/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demikael <pinheiromikael96@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:13:48 by demikael          #+#    #+#             */
/*   Updated: 2022/03/13 10:53:14 by demikael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_ptr_ptr(char **ptr)
{
	char	**temp;

	temp = ptr;
	while (*ptr)
		free (*ptr++);
	free (temp);
}

void	ft_exit(t_pipex *pipex, char **cmd, int index)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (cmd)
		free_ptr_ptr(cmd);
	if (index == 1)
		exit (0);
	else if (index == 2)
		exit (127);
	else
		exit (0);
}

void	space_treat_comands(char *comands)
{
	int	i;

	i = 0;
	while (comands[i])
	{
		if (comands[i] == 39)
		{
			i++;
			if (comands[i] == 39)
				i++;
			while (comands[i] != 39 && comands[i] != '\0')
			{
				if (comands[i] == ' ')
					comands[i] = 1;
				i++;
			}
		}
		i++;
	}
}

void	reverse_space_treat_comands(char **comands)
{
	int	i;
	int	j;

	i = 0;
	while (comands[i])
	{
		j = 0;
		while (comands[i][j])
		{
			if (comands[i][j] == 1)
			{
				comands[i][j] = ' ';
			}
			j++;
		}
		i++;
	}
}

char	*new_comand(char *cmd)
{
	char	*new_comand;
	int		i;
	int		j;

	new_comand = ft_calloc((ft_strlen(cmd) - 1), sizeof(char *));
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i] == 39)
		{
			i++;
			while (cmd[i + 1] != '\0')
			{
				new_comand[j] = cmd[i];
				i++;
				j++;
			}
		}
		i++;
	}
	new_comand[j] = '\0';
	free(cmd);
	return (new_comand);
}
