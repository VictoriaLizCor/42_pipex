/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:09:10 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/17 10:04:44 by lilizarr         ###   ########.fr       */
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
	int	i;

	i = 0;
	if (data->paths)
		ft_free(data->paths);
	while (i <= 1)
	{
		if (data->cmd[i].exe)
			ft_free(data->cmd[i].exe);
		if (data->cmd[i].path)
			free(data->cmd[i].path);
		i++;
	}
}
