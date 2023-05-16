/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:27:05 by mochan            #+#    #+#             */
/*   Updated: 2022/08/19 15:12:05 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_path_in_envp(t_prgm vars)
{
	char	*path_name;
	char	*path_env;
	char	*test;
	int		len_path_env;

	path_name = "PATH=";
	path_env = NULL;
	test = NULL;
	len_path_env = 0;
	while (*(vars.envp))
	{
		test = ft_strnstr(*(vars.envp), path_name, 5);
		if (test)
		{
			path_env = *(vars.envp);
			len_path_env = ft_strlen(path_env);
			break ;
		}
		else
			(*(vars.envp))++;
	}
	path_env = ft_substr(path_env, 5, len_path_env);
	return (path_env);
}

void	split_path(t_prgm *vars, char *s)
{
	char	*temp;
	char	*temp2;
	int		i;

	if (!s)
	{
		ft_printf("Error : No string to split.");
		exit (1);
	}
	vars->env_paths = ft_split(s, ':');
	i = 0;
	while (vars->env_paths[i] != NULL)
	{
		temp = vars->env_paths[i];
		temp2 = ft_strjoin(temp, "/");
		vars->env_paths[i] = ft_strdup(temp2);
		free(temp);
		free(temp2);
		i++;
	}
	free(s);
}
