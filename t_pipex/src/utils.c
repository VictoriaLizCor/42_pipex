/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:09:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/05 14:48:53 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_path(void)
{
	return ;
}

void	free_data(t_pipex data)
{
	ft_free(data.paths);
	ft_free(data.cmd_info[0].cmd);
	free(data.cmd_info[0].path);
	ft_free(data.cmd_info[1].cmd);
	free(data.cmd_info[1].path);
}
