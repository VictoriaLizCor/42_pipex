/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:15:48 by melkholy          #+#    #+#             */
/*   Updated: 2022/09/10 15:17:07 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_single_q(char *str, char **cmd_path)
{
	int		count;

	count = 0;
	while (cmd_path[count])
		count ++;
	free(cmd_path[count - 1]);
	cmd_path[count - 1] = str;
}

char	*ft_found_q(char *cmd, char **str)
{
	char	*tmp;

	*str = ft_strdup(ft_strchr(cmd, 39));
	cmd = ft_strtrim(cmd, *str);
	tmp = ft_strjoin(cmd, " 42");
	free(cmd);
	cmd = tmp;
	tmp = ft_strtrim(*str, "'");
	free(*str);
	*str = tmp;
	return (cmd);
}
