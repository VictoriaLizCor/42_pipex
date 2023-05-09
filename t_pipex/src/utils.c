/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:09:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/09 14:57:11 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_data(t_pipex data)
{
	ft_free(data.paths);
	ft_free(data.cmd[0].exe);
	free(data.cmd[0].path);
	ft_free(data.cmd[1].exe);
	free(data.cmd[1].path);
}
