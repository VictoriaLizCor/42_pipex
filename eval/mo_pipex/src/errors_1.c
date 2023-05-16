/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:57:05 by mochan            #+#    #+#             */
/*   Updated: 2022/08/18 17:04:29 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	check_path_file1(t_prgm *vars)
{
	if (access(vars->path_file1, F_OK | R_OK) != 0)
		vars->err_file1_path_access_nok = 100;
	else
		vars->err_file1_path_access_nok = 0;
}

char	*extract_path_file2_wo_cmd(t_prgm *vars)
{
	int		char_before_cmd2;

	char_before_cmd2 = 0;
	if (ft_strchr(vars->path_file2, '/'))
	{
		while (vars->path_file2[char_before_cmd2] != '\0')
			char_before_cmd2++;
		while (vars->path_file2[char_before_cmd2] != '/')
			char_before_cmd2--;
		char_before_cmd2++;
		copy_path_to_struct(vars, char_before_cmd2);
		return (vars->path_file2_short);
	}
	else
		return (NULL);
}

void	check_path_file2(t_prgm *vars)
{
	char	*str;

	if (ft_strchr(vars->path_file2, '/'))
	{
		str = extract_path_file2_wo_cmd(vars);
		if (access(vars->path_file2_short, F_OK | X_OK) != 0)
			vars->err_file2_path_access_nok = 100;
		else
			vars->err_file2_path_access_nok = 0;
	}
}
