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
	data->cmd_info[idx].cmd = ft_split(argv, ' ');
	tmp_cmd = data->cmd_info[idx].cmd[0];
	while (*p && tmp_cmd)
	{
		path_tmp = ft_strjoin(*p, "/");
		exe_path = ft_strjoin(path_tmp, tmp_cmd);
		free(path_tmp);
		if (access(exe_path, X_OK) == 0)
			data->cmd_info[idx].path = ft_strdup(exe_path);
		free(exe_path);
		p++;
	}
	if (!data->cmd_info[idx].path)
		ft_error(tmp_cmd, ": command not found");
}

/*
checked (R_OK for read permission, W_OK for write permission, 
 and X_OK for execute/search permission), or the existence test (F_OK).
*/
// void	parent_process(int *fd, char **argv, char **env)
// {
// 	char	**str;
// 	char	**cpy;

// 	dup2(fd[1], 1);
// 	close(fd[0]);
// 	ft_printf("\n");
// 	while (*argv)
// 	{
// 		ft_printf("%s\n", *argv);
// 		if (ft_strchr(*argv, ' '))
// 		{
// 			str = ft_split(*argv, ' ');
// 			cpy = str;
// 			while (*cpy)
// 			{
// 				ft_printf("\t\t %s\n", *cpy);
// 				cpy++;
// 			}
// 			ft_free(str);
// 		}
// 		argv++;
// 	}
// }

// //int execve(const char *path, char *const argv[], char *const envp[]);
// void	child_process(t_pipex *data, char *argv, int idx)
// {
// 	int		pid;
// 	char	**str;
// 	char	**cpy;

// 	pid = fork();
// 	if (pid < 0)
// 		ft_error("Fork failed");
// 	if (!pid)
// 	{
// 		dup2(fd[0], 0);
// 		close(fd[1]);

// 		if (execve(str[0], &argv[2], env) < 0)
// 			perror(str[0]);
// 		ft_printf("\t\t %s \n", str[0]);
// 		if (str != argv + 2)
// 			ft_free(str);
// 	}
// 	ft_printf("CHILD PROCESS\n\n\n");
// }

char	**get_paths(char **env)
{
	while (*env && !ft_strnstr(*env, "PATH=", ft_strlen(*env)))
		env++;
	return (ft_split(*env + 5, ':'));
}

int	main(int argc, char **argv, char **env)
{	
	pid_t	pid;
	int		fd[2];
	t_pipex	data;

	ft_bzero(&data, sizeof(t_pipex));
	if (argc != 5)
		ft_error("Invalid input", "");
	data.paths = get_paths(env);
	cmd_exe(&data, argv[2], 0);
	cmd_exe(&data, argv[3], 1);
	ft_printf("1-> %s\n", data.cmd_info[0].path);
	// if (pipe(fd) < 0)
	// 	ft_error("Failed to create pipe");
	// pid = fork();
	// if (pid < 0)
	// 	ft_error("Fork failed");
	// if (!pid)
	// 	child_process(&data, fd, argv[2]);
	// parent_process(&data, fd, argv[3]);
	// free_data(data);
	return (0);
}

	// cmd_exe(&data, argv[2], 0);
	// cmd_exe(&data, argv[3], 1);
	// ft_printf("1-> %s\n", data.cmd_info[0].cmd[0]);
	// ft_printf("1-> %s\n", data.cmd_info[0].path);
	// ft_printf("2-> %s\n", data.cmd_info[1].cmd[0]);
	// ft_printf("2-> %s\n", data.cmd_info[1].path);
