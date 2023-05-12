/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:54:52 by melkholy          #+#    #+#             */
/*   Updated: 2022/09/12 21:51:32 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_infile_fd(t_pipe *buff)
{
	int	infile;
	int	status;

	infile = 0;
	status = 0;
	if (access(buff->argv[1], F_OK | R_OK))
	{
		if (access(buff->argv[1], F_OK))
			status = 1;
		ft_printf("%s: %s: %s\n", buff->sh, strerror(errno), buff->argv[1]);
	}
	else
	{
		infile = open(buff->argv[1], O_RDONLY);
		dup2(infile, buff->pipefd[0][0]);
		close(infile);
	}
	return (status);
}

void	ft_outfile_fd(t_pipe *buff)
{
	int	outfile;
	int	argc;

	outfile = 0;
	argc = buff->argc;
	if (!access(buff->argv[argc - 1], F_OK | W_OK))
		outfile = open(buff->argv[argc - 1], O_WRONLY | O_TRUNC);
	else if (!access(buff->argv[argc - 1], F_OK))
	{
		ft_printf("%s: %s: %s\n", \
				buff->sh, strerror(errno), buff->argv[argc - 1]);
		ft_free_pipes(buff->pipefd, buff->procs);
		free(buff);
		exit(1);
	}
	else
		outfile = open(buff->argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(outfile, buff->pipefd[0][1]);
	close(outfile);
}

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
