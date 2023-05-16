/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:31:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/21 21:48:27 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	init_argv_2_3_into_struct(t_prgm *vars)
{
	vars->cmd1 = vars->argv[2];
	vars->cmd2 = vars->argv[3];
}

char	*get_cmd1_path(t_prgm *vars)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(vars->cmd1, ' ');
	vars->cmd_options1 = tab;
	vars->cmd1_path = NULL;
	while (vars->env_paths[i] != NULL)
	{
		vars->cmd1_path = ft_strjoin(vars->env_paths[i], vars->cmd_options1[0]);
		if (access(vars->cmd1_path, X_OK) == 0)
		{
			vars->err_cmd1_nok = 0;
			return (vars->cmd1_path);
			break ;
		}
		free(vars->cmd1_path);
		i++;
	}
	vars->err_cmd1_nok = 10;
	return (NULL);
}

void	init_cmd1_into_struct_helper(t_prgm *vars)
{
	char	**temp;
	char	**temp2;
	char	*cmd1_w_options;
	char	*cmd1_full_path;
	int		i;

	i = 0;
	temp = ft_split(vars->cmd1, '/');
	while (temp[i] != NULL)
		i++;
	cmd1_w_options = ft_strdup(temp[i - 1]);
	temp2 = ft_split(vars->cmd1, ' ');
	cmd1_full_path = ft_strdup(temp2[0]);
	vars->cmd1 = cmd1_full_path;
	vars->cmd1_path = cmd1_full_path;
	vars->cmd_options1 = ft_split(cmd1_w_options, ' ');
	free(cmd1_w_options);
	free_table(temp);
	free_table(temp2);
}

void	init_cmd1_into_struct(t_prgm *vars)
{
	if (ft_strchr(vars->cmd1, '/'))
	{
		init_cmd1_into_struct_helper(vars);
		if (access(vars->cmd1, F_OK | X_OK) == 0)
			vars->err_cmd1_nok = 0;
		else if (access(vars->cmd1, F_OK | X_OK) != 0)
			vars->err_cmd1_nok = 10;
	}
	else
		get_cmd1_path(vars);
}
