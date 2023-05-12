/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:29:52 by melkholy          #+#    #+#             */
/*   Updated: 2022/09/12 23:24:16 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"

void	ft_pipe_process(int num, char **cmds_path, char *envp[], int **pipes);
void	ft_last_proc(int num, char **cmds_path, char *envp[], int **pipes);
int		ft_fork_proc(char *argv[], char *envp[], int **pipefds, int *pid);
char	**ft_cmd_space(char *cmd, char *envp[], char *str);
char	**ft_check_path(char *cmd, char *envp[]);
void	ft_outfile_fd(char *argv[], int **pipes);
void	ft_single_q(char *str, char **cmd_path);
int		ft_infile_fd(char *argv[], int **pipes);
void	ft_files_fd(char *argv[], int **pipes);
void	ft_close_pipes(int **pipes, int count);
char	*ft_get_path(char *cmd, char *envp[]);
char	*ft_add_path(char *cmd, char **path);
char	*ft_found_q(char *cmd, char **str);
int		**ft_create_pipes(int proc);
void	ft_free_pipes(int **pipes);
int		*ft_create_pid(int proc);
void	ft_free_pth(char **cmd);

#endif
