/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:56:08 by melkholy          #+#    #+#             */
/*   Updated: 2022/09/12 22:19:48 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_pipe
{
	int		argc;
	char	**argv;
	char	**envp;
	int		**pipefd;
	int		*pid;
	char	*sh;
	int		procs;
}				t_pipe;

void	ft_pipe_process(int num, t_pipe *buff, char **cmds_path);
void	ft_last_proc(int num, t_pipe *buff, char **cmds_path);
char	**ft_cmd_space(char *cmd, t_pipe *buff, char *str);
char	*ft_add_path(char *cmd, char **path, char *shell);
t_pipe	*ft_set_buff(int argc, char **argv, char **envp);
char	**ft_check_path(char *cmd, t_pipe *buff);
char	**ft_check_doc(int index, t_pipe *buff);
void	ft_single_q(char *str, char **cmd_path);
void	ft_close_pipes(int **pipes, int count);
char	*ft_get_path(char *cmd, t_pipe *buff);
void	ft_free_pipes(int **pipes, int count);
char	*ft_found_q(char *cmd, char **str);
int		**ft_create_pipes(int proc);
void	ft_outfile_fd(t_pipe *buff);
int		ft_fork_proc(t_pipe *buff);
int		ft_infile_fd(t_pipe *buff);
void	ft_here_doc(t_pipe *buff);
int		ft_files_fd(t_pipe *buff);
int		*ft_create_pid(int proc);
void	ft_free_pth(char **cmd);

#endif
