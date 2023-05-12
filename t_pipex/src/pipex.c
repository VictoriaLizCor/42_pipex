/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:59:02 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/12 16:38:25 by lilizarr         ###   ########.fr       */
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
		ft_putendl_fd(*p, 2);
		path_tmp = ft_strjoin(*p, "/");
		exe_path = ft_strjoin(path_tmp, tmp_cmd);
		if (access(exe_path, X_OK | F_OK) == 0)
			(*d)->cmd[idx].path = ft_strdup(exe_path);
		free(path_tmp);
		free(exe_path);
		p++;
	}
	if (!(*d)->cmd[idx].path)
		ft_error((*d)->cmd[idx].exe[0], "command not found", (*d)->pid);
}

void	openfile(t_pipex *data, char **argv, int oflag, int idx)
{
	data->file = open(argv[1 + 3 * idx], oflag, 0644);
	if (data->file < 0)
		ft_error(strerror(errno), argv[1 + 3 * idx], data->pid);
}

void	cmd(t_pipex *data, char **argv, int idx)
{
	int		ret;
	char	buf;

	if (idx)
	{
		ret = read(data->pipex[!idx], &buf, 1);
		ft_putstr_fd("ret:", 2);
		ft_putendl_fd(ft_itoa(ret), 2);
		ft_putendl_fd(&buf, 2);
	}
	dup2(data->file, idx);
	dup2(data->pipex[!idx], !idx);
	if (close(data->file) < 0)
		ft_error(strerror(errno), argv[1 + 3 * idx], data->pid);
	if (close(data->pipex[!idx]) < 0 || close(data->pipex[idx]) < 0)
		ft_error(strerror(errno), NULL, data->pid);
	cmd_exe(&data, argv[2 + idx], idx);
	execve(data->cmd[idx].path, data->cmd[idx].exe, 0);
	ft_error(strerror(errno), data->cmd[idx].exe[0], data->pid);
}

	// dup2(data->pipex[!idx], !idx);
		// if (pipe(data.pipex) < 0)
		// ft_error("Failed to create pipe", "");
void	runpipe(t_pipex *data, char **argv, pid_t pid)
{
	int		status = 0;

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
		waitpid(data->pid, &status, WUNTRACED);
		openfile(&*data, argv, O_CREAT | O_RDWR | O_TRUNC, 1);
		ft_putstr_fd("status:", 2);
		ft_putendl_fd(ft_itoa(status), 2);
		ft_putendl_fd("cmd1 done", 2);
		cmd(&*data, argv, 1);
	}
}

int	main(int argc, char **argv, char **env)
{	
	t_pipex	data;
	pid_t	pid;
	int		status = 0;

	ft_bzero(&data, sizeof(t_pipex));
	if (argc != 5)
		ft_error("command format", "\n./pipex infile cmd1 cmd2 outfile", 1);
	get_paths(env, &data);
	// if (pipe(data.pipex) < 0)
	// 	ft_error("Failed to create pipe", "");
	pid = fork();
	if (pid < 0)
		ft_error("Fork failed", NULL, 1);
	if (pid == 0)
		runpipe(&data, argv, pid);
	else
	{
		waitpid(pid, &status, WUNTRACED);
		// waitpid(pid, NULL, 0);
		ft_putstr_fd("mains status:", 2);
		ft_putendl_fd(ft_itoa(status), 2);
		ft_putendl_fd("parent", 2);
		exit(0);
	}
	exit(0);
}

// if (close(data.pipex[0]) < 0 || close(data.pipex[1]) < 0)
// 			ft_error(strerror(errno), "");
// waitpid(pipe_pid, &status, WUNTRACED);