/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipex.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lilizarr <lilizarr@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/25 11:23:56 by lilizarr		  #+#	#+#			 */
/*   Updated: 2023/05/05 12:27:23 by lilizarr		 ###   ########.fr	   */
/*																			*/
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
		(*d)->cmd[idx].path = "./";
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
		if (!idx)
		{
			if (close(data->file) < 0)
				ft_error(strerror(errno), "lo");
		}
	}
	if (close(data->pipex[idx]) < 0)
		ft_error(strerror(errno), "**");
	cmd_exe(&data, argv[2 + idx], idx);
	if (access(data->cmd[idx].path, X_OK) == 0)
	{
		execve(data->cmd[idx].path, data->cmd[idx].exe, 0);
		ft_error(strerror(errno), data->cmd[idx].exe[0]);
	}
	return ;
}

int	main(int argc, char **argv, char **env)
{	
	int		status;
	t_pipex	data;

	ft_bzero(&data, sizeof(t_pipex));
	if (argc != 5)
		ft_error("Invalid input", "");
	get_paths(env, &data);
	if (pipe(data.pipex) < 0)
		ft_error("Failed to create pipe", "");
	data.pid = fork();
	if (data.pid < 0)
		ft_error("Fork failed", "");
	if (data.pid > 0)
	{
		cmd(&data, argv, O_RDONLY, 0);
		exit(0);
	}
	else
	{
		waitpid(data.pid, &status, 0);
		// ft_printf("status: %d\n", status);
		cmd(&data, argv, O_CREAT | O_RDWR | O_TRUNC, 1);
		if (close(data.file) < 0)
			ft_error(strerror(errno), "lo");
	}
	exit(0);
}
	// if (execve(data.cmd[0].path, data.cmd[0].exe, env) < 0)
	// 	perror(strerror(errno));

	// cmd_exe(&data, argv[2], 0);
	// cmd_exe(&data, argv[3], 1);
	// ft_printf("1-> %s\n", data.cmd[0].cmd[0]);
	// ft_printf("1-> %s\n", data.cmd[0].path);
	// ft_printf("2-> %s\n", data.cmd[1].cmd[0]);
	// ft_printf("2-> %s\n", data.cmd[1].path);
