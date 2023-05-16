/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:39:32 by mochan            #+#    #+#             */
/*   Updated: 2022/08/20 19:42:14 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	exit_if_failed_malloc_path_file2_short(char *s)
{
	if (!s)
	{
		ft_printf("Failed to malloc: path_file2_wo_cmd2.\n");
		exit (0);
	}
}
