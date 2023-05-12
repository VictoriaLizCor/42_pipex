/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:40:17 by melkholy          #+#    #+#             */
/*   Updated: 2022/12/03 18:57:05 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_files_fd(t_pipe *buff)
{
	int	status;

	status = 0;
	if (!ft_strncmp(buff->argv[1], "here_doc", 8))
	{
		ft_here_doc(buff);
		unlink("./temp.txt");
		return (status);
	}
	status = ft_infile_fd(buff);
	ft_outfile_fd(buff);
	return (status);
}

int	ft_fork_proc(t_pipe *buff)
{
	char	**cmds_path;
	int		status;
	int		count;

	count = -1;
	status = 0;
	buff->pid = ft_create_pid(buff->procs);
	while (++count < buff->procs)
	{
		cmds_path = ft_check_doc(count, buff);
		buff->pid[count] = fork();
		if (count + 1 == buff->procs && buff->pid[count] == 0)
			ft_last_proc(count, buff, cmds_path);
		else if (buff->pid[count] == 0)
			ft_pipe_process(count, buff, cmds_path);
		else if (buff->pid[count] < 0)
			perror("Creating a new process failed");
		if (cmds_path)
			ft_free_pth(cmds_path);
		else if (!cmds_path && count + 1 == buff->procs)
			status = 1;
	}
	ft_close_pipes(buff->pipefd, count);
	return (status);
}

t_pipe	*ft_set_buff(int argc, char **argv, char **envp)
{
	t_pipe	*buff;
	int		count;
	char	*str;

	str = NULL;
	count = 0;
	buff = (t_pipe *)ft_calloc(1, sizeof(t_pipe));
	buff->argc = argc;
	buff->argv = argv;
	buff->envp = envp;
	while (envp[++count])
		if (ft_strnstr(envp[count], "SHELL=", 6))
			str = ft_strtrim(ft_strnstr(envp[count], "SHELL=", 6), "SHELL=");
	buff->sh = ft_strdup(ft_strrchr(str, '/') + 1);
	free(str);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		buff->procs = argc - 4;
	else
		buff->procs = argc - 3;
	return (buff);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		count;
	int		status;
	t_pipe	*buff;

	count = -1;
	status = 0;
	buff = ft_set_buff(argc, argv, envp);
	if (buff->procs < 2)
	{
		free(buff);
		exit(1);
	}
	buff->pipefd = ft_create_pipes(buff->procs);
	status = ft_files_fd(buff);
	if (ft_fork_proc(buff))
		status = 127;
	while (++count < buff->procs)
		waitpid(buff->pid[count], NULL, 0);
	ft_free_pipes(buff->pipefd, buff->procs);
	free(buff->pid);
	free(buff->sh);
	free(buff);
	return (status);
}
