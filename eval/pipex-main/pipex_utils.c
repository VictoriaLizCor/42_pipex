/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:23:44 by melkholy          #+#    #+#             */
/*   Updated: 2022/09/10 15:21:22 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**ft_create_pipes(int proc)
{
	int	**pipes;
	int	*pip;
	int	count;

	pipes = (int **)ft_calloc(proc, sizeof(int *));
	if (!pipes)
		return (NULL);
	count = 0;
	while (count < proc)
	{
		pip = (int *)ft_calloc(2, sizeof(int));
		if (!pip)
			return (NULL);
		if (pipe(pip) < 0)
			perror("Pipe creation failed");
		pipes[count] = pip;
		count ++;
	}
	return (pipes);
}

int	*ft_create_pid(int proc)
{
	int	*pid;

	pid = (int *)ft_calloc(proc, sizeof(int));
	if (!pid)
		return (NULL);
	return (pid);
}

void	ft_free_pth(char **cmd)
{
	int	count;

	count = 0;
	while (cmd[count])
	{
		free(cmd[count]);
		count ++;
	}
	free(cmd);
}

void	ft_free_pipes(int **pipes)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		free(pipes[count]);
		count ++;
	}
	free(pipes);
}

void	ft_close_pipes(int **pipes, int count)
{
	while (--count >= 0)
	{
		close(pipes[count][0]);
		close(pipes[count][1]);
	}
}
