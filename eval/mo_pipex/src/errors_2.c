/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:53:28 by mochan            #+#    #+#             */
/*   Updated: 2022/08/21 18:54:07 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_number_of_arguments(t_prgm *vars)
{
	if (vars->argc > 5)
	{
		ft_printf("Too many arguments (pipex requires 4 arguments).\n");
		exit (1);
	}
	else if (vars->argc < 5)
	{
		ft_printf("Too few arguments (pipex requires 4 arguments).\n");
		exit (2);
	}
}

void	check_both_cmds(t_prgm *vars)
{
	if (vars->b_cmd2_nok == 1 && vars->b_cmd1_nok == 1)
	{
		ft_printf("command not found: %s\n", vars->cmd1_path);
		ft_printf("command not found: %s\n", vars->cmd_options2[0]);
		free_table(vars->env_paths);
		free_table(vars->cmd_options1);
		free_table(vars->cmd_options2);
		exit (1);
	}
	else if (vars->b_cmd2_nok == 0 && vars->b_cmd1_nok == 1)
	{
		ft_printf("command not found: %s\n", vars->cmd1_path);
		free_table(vars->env_paths);
		free_table(vars->cmd_options1);
		exit (1);
	}
	else if (vars->b_cmd2_nok == 1 && vars->b_cmd1_nok == 0)
	{
		ft_printf("command not found: %s\n", vars->cmd_options2[0]);
		free_table(vars->env_paths);
		free_table(vars->cmd_options2);
		exit (1);
	}
}
