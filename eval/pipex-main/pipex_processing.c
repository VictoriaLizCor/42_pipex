/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:21:26 by melkholy          #+#    #+#             */
/*   Updated: 2022/09/12 23:47:18 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_add_path(char *cmd, char **path)
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
		ft_printf("command not found: %s\n", cmd);
		return (NULL);
	}
	return (cmd_path);
}

char	*ft_get_path(char *cmd, char *envp[])
{
	int		count;
	char	*str;
	char	**path;

	count = -1;
	str = NULL;
	while (envp[++count])
		if (ft_strnstr(envp[count], "PATH=", 5))
			str = ft_strtrim(ft_strnstr(envp[count], "PATH=", 5), "PATH=");
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
	return (ft_add_path(cmd, path));
}

char	**ft_cmd_space(char *cmd, char *envp[], char *str)
{
	char	**cmd_path;
	char	*tmp;

	cmd_path = ft_split(cmd, ' ');
	tmp = ft_get_path(cmd_path[0], envp);
	if (tmp)
	{
		free(cmd_path[0]);
		cmd_path[0] = tmp;
	}
	else
	{
		ft_free_pth(cmd_path);
		return (NULL);
	}
	if (str)
		free(cmd);
	return (cmd_path);
}

char	**ft_check_path(char *cmd, char *envp[])
{
	char	**cmd_path;
	char	*tmp;
	char	*str;

	str = NULL;
	if (ft_strchr(cmd, 39))
		cmd = ft_found_q(cmd, &str);
	if (ft_strchr(cmd, ' '))
	{
		cmd_path = ft_cmd_space(cmd, envp, str);
		if (str)
			ft_single_q(str, cmd_path);
	}
	else
	{
		tmp = ft_get_path(cmd, envp);
		if (tmp == NULL)
			ft_putstr_fd("NULL", 2);
		ft_putstr_fd(tmp, 2);
		ft_putstr_fd("\n", 2);
		cmd_path = ft_split(tmp, '\0');
		free(tmp);
		if (str)
			ft_single_q(str, cmd_path);
	}
	if (cmd == NULL)
		ft_putstr_fd("NULL", 2);
	ft_putstr_fd(*cmd_path, 2);
	ft_putstr_fd("\n", 2);
	return (cmd_path);
}

void	ft_last_proc(int num, char **cmds_path, char *envp[], int **pipes)
{
	int	count;

	count = -1;
	while (++count < 2)
	{
		if (num != count)
			close(pipes[count][0]);
		if (count)
			close(pipes[count][1]);
	}
	dup2(pipes[num][0], 0);
	close(pipes[num][0]);
	dup2(pipes[0][1], 1);
	close(pipes[0][1]);
	execve(cmds_path[0], cmds_path, envp);
}
