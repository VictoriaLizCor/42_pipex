/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helper_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:34:17 by melkholy          #+#    #+#             */
/*   Updated: 2022/09/12 22:15:40 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_cmd_space(char *cmd, t_pipe *buff, char *str)
{
	char	**cmd_path;
	char	*tmp;

	cmd_path = ft_split(cmd, ' ');
	tmp = ft_get_path(cmd_path[0], buff);
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

void	ft_single_q(char *str, char **cmd_path)
{
	int		count;

	count = 0;
	while (cmd_path[count])
		count ++;
	free(cmd_path[count - 1]);
	cmd_path[count - 1] = str;
}

char	*ft_found_q(char *cmd, char **str)
{
	char	*tmp;

	*str = ft_strdup(ft_strchr(cmd, 39));
	cmd = ft_strtrim(cmd, *str);
	tmp = ft_strjoin(cmd, " 42");
	free(cmd);
	cmd = tmp;
	tmp = ft_strtrim(*str, "'");
	free(*str);
	*str = tmp;
	return (cmd);
}

void	ft_free_pipes(int **pipes, int pipe)
{
	int	count;

	count = 0;
	while (count < pipe)
	{
		free(pipes[count]);
		count ++;
	}
	free(pipes);
}

void	ft_close_pipes(int **pipes, int count)
{
	while (--count >= 0)
	{
		close(pipes[count][0]);
		close(pipes[count][1]);
	}
}
