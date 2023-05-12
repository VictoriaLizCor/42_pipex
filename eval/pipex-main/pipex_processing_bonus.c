/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_processing_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:51:41 by melkholy          #+#    #+#             */
/*   Updated: 2022/09/12 23:58:11 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_add_path(char *cmd, char **path, char *shell)
{
	int		count;
	char	*cmd_path;

	count = -1;
	cmd_path = NULL;
	while (path[++count])
	{
		cmd_path = ft_strjoin(path[count], cmd);
		if (!access(cmd_path, F_OK | X_OK))
			break ;
		free(cmd_path);
		cmd_path = NULL;
	}
	count = -1;
	while (path[++count])
		free(path[count]);
	free(path);
	if (!cmd_path)
	{
		ft_printf("%s: command not found: %s\n", shell, cmd);
		return (NULL);
	}
	return (cmd_path);
}

char	*ft_get_path(char *cmd, t_pipe *buff)
{
	int		count;
	char	*str;
	char	**path;

	count = -1;
	str = NULL;
	while (buff->envp[++count])
		if (ft_strnstr(buff->envp[count], "PATH=", 5))
			str = ft_strtrim(ft_strnstr(buff->envp[count], "PATH=", 5), \
					"PATH=");
	if (str)
		path = ft_split(str, ':');
	else
		return (NULL);
	if (str)
		free(str);
	count = -1;
	while (path[++count])
	{
		str = path[count];
		path[count] = ft_strjoin(path[count], "/");
		free(str);
	}
	return (ft_add_path(cmd, path, buff->sh));
}

char	**ft_check_path(char *cmd, t_pipe *buff)
{
	char	**cmd_path;
	char	*tmp;
	char	*str;

	str = NULL;
	if (ft_strchr(cmd, 39))
		cmd = ft_found_q(cmd, &str);
	if (ft_strchr(cmd, ' '))
	{
		cmd_path = ft_cmd_space(cmd, buff, str);
		if (str)
			ft_single_q(str, cmd_path);
	}
	else
	{
		tmp = ft_get_path(cmd, buff);
		cmd_path = ft_split(tmp, '\0');
		free(tmp);
		if (str)
			ft_single_q(str, cmd_path);
	}
	return (cmd_path);
}

void	ft_last_proc(int num, t_pipe *buff, char **cmds_path)
{
	int	count;

	count = -1;
	while (++count < buff->procs)
	{
		if (num != count)
			close(buff->pipefd[count][0]);
		if (count)
			close(buff->pipefd[count][1]);
	}
	dup2(buff->pipefd[num][0], 0);
	close(buff->pipefd[num][0]);
	dup2(buff->pipefd[0][1], 1);
	close(buff->pipefd[0][1]);
	if (cmds_path)
		execve(cmds_path[0], cmds_path, buff->envp);
	else
		return ;
}

void	ft_pipe_process(int num, t_pipe *buff, char **cmds_path)
{
	int	count;

	count = -1;
	while (++count < buff->procs)
	{
		if (num != count)
			close(buff->pipefd[count][0]);
		if (num + 1 != count)
			close(buff->pipefd[count][1]);
	}
	dup2(buff->pipefd[num][0], 0);
	close(buff->pipefd[num][0]);
	dup2(buff->pipefd[num + 1][1], 1);
	close(buff->pipefd[num + 1][1]);
	if (cmds_path)
		execve(cmds_path[0], cmds_path, buff->envp);
	else
		return ;
}
