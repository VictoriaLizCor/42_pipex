/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:59:02 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/11 10:06:23 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_exe(t_pipex **d, char *argv, int idx)
{
	char	*path_tmp;
	char	*exe_path;
	char	*tmp_cmd;
	char	**p;

	p = (*d)->paths;
	(*d)->cmd[idx].exe = ft_split(argv, ' ');
	tmp_cmd = (*d)->cmd[idx].exe[0];
	if (!tmp_cmd)
		(*d)->cmd[idx].path = ft_strdup("./");
	while (*p && tmp_cmd)
	{
		path_tmp = ft_strjoin(*p, "/");
		exe_path = ft_strjoin(path_tmp, tmp_cmd);
		if (access(exe_path, X_OK | F_OK) == 0)
			(*d)->cmd[idx].path = ft_strdup(exe_path);
		free(path_tmp);
		free(exe_path);
		p++;
	}
	if (!(*d)->cmd[idx].path)
		ft_error((*d)->cmd[idx].exe[0], "command not found");
}

void	get_paths(char **env, t_pipex *d)
{
	char	**e_cpy;

	e_cpy = env;
	while (*e_cpy && !ft_strnstr(*e_cpy, "PATH=", ft_strlen(*e_cpy)))
		e_cpy++;
	d->paths = ft_split(*e_cpy + 5, ':');
}

void	cmd(t_pipex *data, char **argv, int oflag, int idx)
{
	int	backup;

	backup = idx;
	data->file = open(argv[1 + 3 * idx], oflag, 0644);
	if (data->file < 0)
		ft_error(strerror(errno), argv[1 + 3 * idx]);
	else
	{
		dup2(data->pipex[!idx], !idx);
		dup2(data->file, idx);
		if (close(data->file) < 0)
			ft_error(strerror(errno), argv[1 + 3 * idx]);
	}
	if (close(data->pipex[idx]) < 0)
		ft_error(strerror(errno), "");
	cmd_exe(&data, argv[2 + idx], idx);
	execve(data->cmd[idx].path, data->cmd[idx].exe, 0);
	ft_error(strerror(errno), data->cmd[idx].exe[0]);
}

void	runpipe(t_pipex *data, char **argv)
{
	int		status;
	int		pipe_pid;

	pipe_pid = fork();
	if (pipe_pid < 0)
		ft_error("Fork failed", "");
	if (pipe_pid > 0)
		cmd(&*data, argv, O_RDONLY, 0);
	else
	{
		waitpid(pipe_pid, &status, WUNTRACED);
		cmd(&*data, argv, O_CREAT | O_RDWR | O_TRUNC, 1);
	}
}

int	main(int argc, char **argv, char **env)
{	
	int		status;
	t_pipex	data;
	int		pid;

	ft_bzero(&data, sizeof(t_pipex));
	if (argc != 5)
		ft_error("Invalid input", "");
	get_paths(env, &data);
	if (pipe(data.pipex) < 0)
		ft_error("Failed to create pipe", "");
	pid = fork();
	if (pid < 0)
		ft_error("Fork failed", "");
	if (pid > 0)
		runpipe(&data, argv);
	else
	{
		waitpid(pid, &status, WUNTRACED);
		exit(0);
	}
	return (0);
}
