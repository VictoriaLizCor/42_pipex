/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:35:17 by mochan            #+#    #+#             */
/*   Updated: 2022/08/22 00:12:30 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	sum_error_codes_1st_half_pipe(t_prgm *vars)
{
	vars->err_1st_half_pipe = vars->err_file1_existence_nok
		+ vars->err_file1_r_right_nok
		+ vars->err_file1_path_access_nok
		+ vars->err_cmd1_nok;
}

void	sum_error_codes_2nd_half_pipe(t_prgm *vars)
{
	vars->err_2nd_half_pipe = vars->err_file2_existence_nok
		+ vars->err_file2_w_right_nok
		+ vars->err_file2_path_access_nok
		+ vars->err_cmd2_nok;
}

void	priorization_error_code_1st_half_pipe(t_prgm *vars)
{
	check_existence_file1(vars);
	check_r_right_file1(vars);
	sum_error_codes_1st_half_pipe(vars);
	if (vars->err_1st_half_pipe > 0 && vars->err_1st_half_pipe < 99)
	{
		ft_printf("command not found : %s\n", vars->cmd_options1[0]);
	}
	if (vars->err_1st_half_pipe < 9999 && vars->err_1st_half_pipe > 99)
	{
		ft_printf("no such file or directory : %s\n", vars->path_file1);
	}
	if (vars->err_1st_half_pipe > 9999)
	{
		ft_printf("permission denied : %s\n", vars->path_file1);
	}
}

void	priorization_error_code_2nd_half_pipe(t_prgm *vars)
{
	check_w_right_file2(vars);
	sum_error_codes_2nd_half_pipe(vars);
	if (vars->err_2nd_half_pipe > 0 && vars->err_2nd_half_pipe < 99)
	{
		ft_printf("command not found : %s\n", vars->cmd_options2[0]);
	}
	if (vars->err_2nd_half_pipe < 9999 && vars->err_2nd_half_pipe > 99)
	{
		ft_printf("No such file or directory : %s\n", vars->path_file2);
	}
	if (vars->err_2nd_half_pipe > 9999)
	{
		ft_printf("permission denied : %s\n", vars->path_file2);
	}
}

void	error_exit(t_prgm *vars)
{
	if (vars->err_1st_half_pipe > 0 || vars->err_2nd_half_pipe > 0)
		exit (0);
}
