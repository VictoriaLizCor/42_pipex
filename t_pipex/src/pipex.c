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

void	cmd_exe(t_pipex *data, char *argv, int idx)
{
	char	*path_tmp;
	char	*exe_path;
	char	*tmp_cmd;
	char	**p;

	p = data->paths;
	data->cmd[idx].exe = ft_split(argv, ' ');
	tmp_cmd = data->cmd[idx].exe[0];
	while (*p && tmp_cmd)
	{
		path_tmp = ft_strjoin(*p, "/");
		exe_path = ft_strjoin(path_tmp, tmp_cmd);
		if (access(exe_path, X_OK | F_OK) == 0)
			data->cmd[idx].path = ft_strdup(exe_path);
		free(path_tmp);
		free(exe_path);
		p++;
	}
	// if (!data->cmd[idx].path)
	// 	ft_error(tmp_cmd, ": command not found");
}

char	**get_paths(char **env)
{
	char	**e_cpy;

	e_cpy = env;
	while (*e_cpy && !ft_strnstr(*e_cpy, "PATH=", ft_strlen(*e_cpy)))
		e_cpy++;
	return (ft_split(*e_cpy + 5, ':'));
}

void	cmd1(t_cmd *cmd, int *pipex, char *file_name)
{
	int		file;

	file = open(file_name, O_RDONLY, 0644);
	if (file < 0)
		ft_error(strerror(errno),"");
	dup2(file, 0);
	dup2(pipex[1], 1);
	close(pipex[0]);
	execve(cmd->path, cmd->exe, 0);
	perror(file_name);
}

void	cmd2(t_pipex *data, int *pipex, char *file_name)
{
	int		file;

	file = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (file == -1)
		ft_putstr_fd(file_name, 1);
	dup2(file, 1);
	dup2(pipex[0], 0);
	close(pipex[1]);
	execve(data->cmd[1].path, data->cmd[1].exe, 0);
	free_data(*data);
}

int	main(int argc, char **argv, char **env)
{	
	int		status;
	int		pipex[2];
	t_pipex	data;

	ft_bzero(&data, sizeof(t_pipex));
	if (argc != 5)
		ft_error("Invalid input", "");
	data.paths = get_paths(env);
	cmd_exe(&data, argv[2], 0);
	ft_printf("1-> %s\n", data.cmd[0].path);
	cmd_exe(&data, argv[3], 1);
	ft_printf("2-> %s\n", data.cmd[1].path);
	if (pipe(pipex) < 0)
		ft_error("Failed to create pipe", "");
	data.pid = fork();
	if (data.pid < 0)
		ft_error("Fork failed", "");
	if (!data.pid)
		cmd1(&data.cmd[0], pipex, argv[1]);
	else
	{
		waitpid(data.pid, &status, 0);
		ft_printf("\n%d\n", status);
		if (status == 0)
			cmd2(&data, pipex, argv[4]);
		strerror(errno);
	}
	return (0);
}
	// if (execve(data.cmd[0].path, data.cmd[0].exe, env) < 0)
	// 	perror(strerror(errno));

	// cmd_exe(&data, argv[2], 0);
	// cmd_exe(&data, argv[3], 1);
	// ft_printf("1-> %s\n", data.cmd[0].cmd[0]);
	// ft_printf("1-> %s\n", data.cmd[0].path);
	// ft_printf("2-> %s\n", data.cmd[1].cmd[0]);
	// ft_printf("2-> %s\n", data.cmd[1].path);
