/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:32:48 by melkholy          #+#    #+#             */
/*   Updated: 2022/09/12 22:03:07 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_here_doc(t_pipe *buff)
{
	char	*str;
	char	*delimiter;
	int		nofile;
	int		outf;

	delimiter = ft_strjoin(buff->argv[2], "\n");
	nofile = open("temp.txt", O_RDWR | O_CREAT | O_APPEND, 0666);
	write(1, "pipe heredoc> ", 14);
	str = get_next_line(0);
	while (ft_strncmp(str, delimiter, ft_strlen(delimiter)))
	{
		write(nofile, str, ft_strlen(str));
		free(str);
		write(1, "pipe heredoc> ", 14);
		str = get_next_line(0);
	}
	free(str);
	free(delimiter);
	close(nofile);
	nofile = open("temp.txt", O_RDONLY);
	dup2(nofile, buff->pipefd[0][0]);
	close(nofile);
	outf = open(buff->argv[buff->argc - 1], O_RDWR | O_CREAT | O_APPEND, 0666);
	dup2(outf, buff->pipefd[0][1]);
	close(outf);
}

char	**ft_check_doc(int index, t_pipe *buff)
{
	if (!ft_strncmp(buff->argv[1], "here_doc", 8))
		return (ft_check_path(buff->argv[index + 3], buff));
	else
		return (ft_check_path(buff->argv[index + 2], buff));
}
