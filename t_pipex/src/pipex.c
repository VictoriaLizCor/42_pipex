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
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd((*d)->cmd[idx].exe[0], 2);
		ft_putendl_fd(": command not found", 2);
	}
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
	int		file;

	file = open(argv[1 + 3 * idx], oflag, 0644);
	if (file < 0)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(" : ", 2);
		ft_putendl_fd(argv[1 + 3 * idx], 2);
		return ;
	}
	cmd_exe(&data, argv[2 + idx], idx);
	dup2(file, idx);
	dup2(data->pipex[!idx], !idx);
	close(data->pipex[idx]);
	if (access(data->cmd[idx].path, X_OK) == 0)
		execve(data->cmd[idx].path, data->cmd[idx].exe, 0);
	perror("Error");
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
	if (!data.pid)
		cmd(&data, argv, O_RDONLY, 0);
	else
	{
		waitpid(data.pid, &status, 0);
		cmd(&data, argv, O_CREAT | O_RDWR | O_TRUNC, 1);
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
