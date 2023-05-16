/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:46:04 by mochan            #+#    #+#             */
/*   Updated: 2022/08/22 09:37:00 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	open_file1(t_prgm *vars)
{
	vars->path_file1 = vars->argv[1];
	vars->file1 = open(vars->path_file1, O_RDWR, 0777);
}

void	open_file2(t_prgm *vars)
{
	vars->path_file2 = vars->argv[4];
	vars->file2 = open(vars->path_file2, O_RDWR | O_CREAT | O_TRUNC, 0777);
}

void	open_both_files(t_prgm *vars)
{
	open_file1(vars);
	open_file2(vars);
}
