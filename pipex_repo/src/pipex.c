/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:59:02 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/17 11:53:32 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_exe(t_pipex *d, char *argv, int idx)
{
	char	*path_tmp;
	char	*exe_path;
	char	*tmp_cmd;
	char	**p;

	p = d->paths;
	d->cmd[idx].exe = ft_split(argv, ' ');
	if (!*d->cmd[idx].exe)
		d->cmd[idx].path = ft_strdup("./");
	tmp_cmd = d->cmd[idx].exe[0];
	if (tmp_cmd && ft_strchr(tmp_cmd, '/') && access(tmp_cmd, X_OK) == -1)
		ft_error(strerror(errno), tmp_cmd, 1);
	while (*p && tmp_cmd)
	{
		path_tmp = ft_strjoin(*p, "/");
		if (ft_strnstr(tmp_cmd, path_tmp, ft_strlen(tmp_cmd)))
			tmp_cmd = tmp_cmd + ft_strlen(path_tmp);
		exe_path = ft_strjoin(path_tmp, tmp_cmd);
		if (access(exe_path, X_OK | F_OK) == 0)
			d->cmd[idx].path = ft_strdup(exe_path);
		free(path_tmp);
		free(exe_path);
		p++;
	}
}

void	openfile(t_pipex *data, char **argv, int oflag, int idx)
{
	data->file = open(argv[1 + 3 * idx], oflag, 0644);
	if (data->file < 0)
		ft_error(strerror(errno), argv[1 + 3 * idx], 1);
	dup2(data->file, idx);
}

void	cmd(t_pipex *data, char **argv, int idx)
{
	dup2(data->pipex[!idx], !idx);
	if (close(data->pipex[idx]) < 0)
		ft_error(strerror(errno), NULL, 1);
	if (close(data->file) < 0)
		ft_error(strerror(errno), argv[1 + 3 * idx], 1);
	if (close(data->pipex[!idx]) < 0)
		ft_error(strerror(errno), NULL, 1);
	cmd_exe(&*data, argv[2 + idx], idx);
	if (!data->cmd[idx].path)
		ft_error(data->cmd[idx].exe[0], "command not found", 1);
	execve(data->cmd[idx].path, data->cmd[idx].exe, 0);
	ft_error(strerror(errno), data->cmd[idx].exe[0], 1);
}

void	runpipe(t_pipex *data, char **argv, pid_t pid)
{
	int	status;

	if (pipe(data->pipex) < 0)
		ft_error("Failed to create pipe", NULL, pid);
	data->pid = fork();
	if (data->pid < 0)
		ft_error("Fork failed", NULL, 1);
	if (data->pid == 0)
	{
		openfile(&*data, argv, O_RDONLY, 0);
		cmd(&*data, argv, 0);
	}
	else
	{
		openfile(&*data, argv, O_CREAT | O_RDWR | O_TRUNC, 1);
		if (waitpid(-1, &status, WUNTRACED) && status)
			dup2(1, data->pipex[0]);
		cmd(&*data, argv, 1);
	}
}

int	main(int argc, char **argv, char **env)
{	
	t_pipex	data;
	pid_t	pid;

	ft_bzero(&data, sizeof(t_pipex));
	if (argc != 5)
		ft_error("Valid input", "\n./pipex infile cmd1 cmd2 outfile", 1);
	get_paths(env, &data);
	pid = fork();
	if (pid < 0)
		ft_error("Fork failed", NULL, 1);
	if (pid == 0)
		runpipe(&data, argv, pid);
	else
	{
		waitpid(-1, NULL, WUNTRACED);
		free_data(&data);
	}
	exit(0);
}
