/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:40:17 by melkholy          #+#    #+#             */
/*   Updated: 2022/09/12 23:56:46 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe_process(int num, char **cmds_path, char *envp[], int **pipes)
{
	int	count;

	count = -1;
	while (++count < 2)
	{
		if (num != count)
			close(pipes[count][0]);
		if (num + 1 != count)
			close(pipes[count][1]);
	}
	dup2(pipes[num][0], 0);
	close(pipes[num][0]);
	dup2(pipes[num + 1][1], 1);
	close(pipes[num + 1][1]);
	if (*cmds_path == NULL)
		ft_putstr_fd("NULL", 2);
	if (cmds_path)
		execve(cmds_path[0], cmds_path, envp);
	else
		return ;
}

int	ft_infile_fd(char *argv[], int **pipes)
{
	int	infile;
	int	status;

	infile = 0;
	status = 0;
	if (access(argv[1], F_OK | R_OK))
	{
		if (access(argv[1], F_OK))
			status = 1;
		ft_printf("%s: %s\n", strerror(errno), argv[1]);
	}
	else
	{
		infile = open(argv[1], O_RDONLY);
		dup2(infile, pipes[0][0]);
		close(infile);
	}
	return (status);
}

void	ft_outfile_fd(char *argv[], int **pipes)
{
	int	outfile;

	outfile = 0;
	if (!access(argv[4], F_OK | W_OK))
		outfile = open(argv[4], O_WRONLY | O_TRUNC);
	else if (!access(argv[4], F_OK))
	{
		ft_printf("%s: %s\n", strerror(errno), argv[4]);
		ft_free_pipes(pipes);
		exit(1);
	}
	else
		outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0666);
	dup2(outfile, pipes[0][1]);
	close(outfile);
}

int	ft_fork_proc(char *argv[], char *envp[], int **pipefds, int *pid)
{
	char	**cmds_path;
	int		count;
	int		status;

	count = -1;
	status = 0;
	while (++count < 2)
	{
		cmds_path = ft_check_path(argv[count + 2], envp);
		pid[count] = fork();
		if (count && pid[count] == 0)
			ft_last_proc(count, cmds_path, envp, pipefds);
		else if (pid[count] == 0)
			ft_pipe_process(count, cmds_path, envp, pipefds);
		else if (pid[count] < 0)
			perror("Creating a new process failed");
		if (cmds_path)
			ft_free_pth(cmds_path);
		else if (!cmds_path && count)
			status = 1;
	}
	ft_close_pipes(pipefds, count);
	return (status);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		*pid;
	int		**pipes;
	int		count;
	int		procs;
	int		status;

	count = -1;
	status = 0;
	if (argc != 5)
		exit(1);
	procs = argc - 3;
	pipes = ft_create_pipes(procs);
	status = ft_infile_fd(argv, pipes);
	ft_outfile_fd(argv, pipes);
	pid = ft_create_pid(2);
	if (ft_fork_proc(argv, envp, pipes, pid))
		status = 127;
	while (++count < procs)
		waitpid(pid[count], NULL, 0);
	ft_free_pipes(pipes);
	// unlink("./temp.txt");
	free(pid);
	return (status);
}
