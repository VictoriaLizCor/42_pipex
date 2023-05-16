/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 23:06:06 by mochan            #+#    #+#             */
/*   Updated: 2022/08/19 12:40:24 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	parent_process(t_prgm vars, int *fildes, int chi1, int chi2)
{
	free_stuff(&vars);
	close(fildes[0]);
	close(fildes[1]);
	close(vars.file1);
	close(vars.file2);
	waitpid(chi1, NULL, 0);
	waitpid(chi2, NULL, 0);
	return (0);
}
