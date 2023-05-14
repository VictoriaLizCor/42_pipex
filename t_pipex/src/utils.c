/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:09:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/14 20:04:45 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_paths(char **env, t_pipex *d)
{
	char	**e_cpy;

	e_cpy = env;
	while (*e_cpy && !ft_strnstr(*e_cpy, "PATH=", ft_strlen(*e_cpy)))
		e_cpy++;
	d->paths = ft_split(*e_cpy + 5, ':');
}

void	free_data(t_pipex *data)
{
	if (data->paths)
		ft_free(data->paths);
	if (data->cmd[0].exe)
		ft_free(data->cmd[0].exe);
	if (data->cmd[0].path)
		free(data->cmd[0].path);
	if (data->cmd[1].exe)
		ft_free(data->cmd[1].exe);
	if (data->cmd[1].path)
		free(data->cmd[1].path);
}
