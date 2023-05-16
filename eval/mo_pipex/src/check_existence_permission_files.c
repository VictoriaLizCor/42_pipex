/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existence_permission_files.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:44:45 by mochan            #+#    #+#             */
/*   Updated: 2022/08/21 23:33:19 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	check_existence_file1(t_prgm *vars)
{
	if (access(vars->argv[1], F_OK) == -1)
		vars -> err_file1_existence_nok = 1000;
	else
		vars -> err_file1_existence_nok = 0;
}

void	check_r_right_file1(t_prgm *vars)
{
	if (access(vars->argv[1], F_OK) == 0 && access(vars->argv[1], R_OK) == -1)
		vars->err_file1_r_right_nok = 10000;
	else
		vars->err_file1_r_right_nok = 0;
}

void	check_existence_file2(t_prgm *vars)
{
	if (access(vars->argv[4], F_OK) == -1)
		vars->err_file2_existence_nok = 1000;
	else
		vars->err_file2_existence_nok = 0;
}

void	check_w_right_file2(t_prgm *vars)
{
	if (access(vars->argv[4], F_OK) == 0 && access(vars->argv[4], W_OK) == -1)
		vars->err_file2_w_right_nok = 10000;
	else
		vars->err_file2_w_right_nok = 0;
}
