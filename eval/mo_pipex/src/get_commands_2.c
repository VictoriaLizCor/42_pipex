/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:44:15 by mochan            #+#    #+#             */
/*   Updated: 2022/08/21 21:51:17 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*get_cmd2_path(t_prgm *vars)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(vars->cmd2, ' ');
	vars->cmd_options2 = tab;
	vars->cmd2_path = NULL;
	while (vars->env_paths[i] != NULL)
	{
		vars->cmd2_path = ft_strjoin(vars->env_paths[i], vars->cmd_options2[0]);
		if (access(vars->cmd2_path, X_OK) == 0)
		{
			vars->err_cmd2_nok = 0;
			return (vars->cmd2_path);
			break ;
		}
		free(vars->cmd2_path);
		i++;
	}
	vars->err_cmd2_nok = 10;
	return (NULL);
}

void	init_cmd2_into_struct_helper(t_prgm *vars)
{
	char	**temp;
	char	**temp2;
	char	*cmd2_w_options;
	char	*cmd2_full_path;
	int		i;

	i = 0;
	temp = ft_split(vars->cmd2, '/');
	while (temp[i] != NULL)
		i++;
	cmd2_w_options = ft_strdup(temp[i - 1]);
	temp2 = ft_split(vars->cmd2, ' ');
	cmd2_full_path = ft_strdup(temp2[0]);
	vars->cmd2 = cmd2_full_path;
	vars->cmd2_path = cmd2_full_path;
	vars->cmd_options2 = ft_split(cmd2_w_options, ' ');
	free(cmd2_w_options);
	free_table(temp);
	free_table(temp2);
}

void	init_cmd2_into_struct(t_prgm *vars)
{
	if (ft_strchr(vars->cmd2, '/'))
	{
		init_cmd2_into_struct_helper(vars);
		if (access(vars->cmd2, F_OK | X_OK) == 0)
			vars->err_cmd2_nok = 0;
		else if (access(vars->cmd2, F_OK | X_OK) != 0)
			vars->err_cmd2_nok = 10;
	}
	else
		get_cmd2_path(vars);
}
