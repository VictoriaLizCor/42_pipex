/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:11:35 by mochan            #+#    #+#             */
/*   Updated: 2022/08/20 16:14:09 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process_cmd1(int infile, int *fildes, t_prgm *vars)
{
	dup2(infile, STDIN_FILENO);
	dup2(fildes[1], STDOUT_FILENO);
	close(fildes[0]);
	close(fildes[1]);
	execve(vars->cmd1_path, vars->cmd_options1, vars->envp);
}

void	child_process_cmd2(int outfile, int *fildes, t_prgm *vars)
{
	dup2(fildes[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fildes[1]);
	close(fildes[0]);
	execve(vars->cmd2_path, vars->cmd_options2, vars->envp);
}
