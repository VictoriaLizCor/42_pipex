/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:32:33 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/08 15:50:01 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_cmd
{
	char	**exe;
	char	*path;
}	t_cmd;

typedef struct s_pipex
{
	pid_t	pid;
	int		pipex[2];
	char	**paths;
	t_cmd	cmd[2];
}	t_pipex;

void	free_data(t_pipex data);
#endif