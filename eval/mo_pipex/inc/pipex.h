/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:08:17 by mochan            #+#    #+#             */
/*   Updated: 2022/08/22 10:14:04 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ########################################################################## */
/* INCLUDES */

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

/* ########################################################################## */
/* STRUCTURES */

typedef struct s_prgm
{
	int		argc;
	char	**argv;
	char	**envp;
	int		file1;
	int		file2;
	char	*path_in_envp;
	char	**env_paths;
	char	*cmd1;
	char	*cmd2;
	char	*path_file1;
	char	*path_file2;
	char	*path_file2_short;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**cmd_options1;
	char	**cmd_options2;
	int		b_cmd1_nok;
	int		b_cmd2_nok;
	int		err_file1_existence_nok;
	int		err_file2_existence_nok;
	int		err_file1_r_right_nok;
	int		err_file2_w_right_nok;
	int		err_file1_path_access_nok;
	int		err_file2_path_access_nok;
	int		err_cmd1_nok;
	int		err_cmd2_nok;
	int		err_1st_half_pipe;
	int		err_2nd_half_pipe;
}				t_prgm;

/* ########################################################################## */
/* CONSTANTS */

/* ########################################################################## */
/* FUNCTIONS */

/* errors_1.c */
void	check_path_file1(t_prgm *vars);
char	*extract_path_file2_wo_cmd(t_prgm *vars);
void	check_path_file2(t_prgm *vars);

/* errors_2.c */
void	error_number_of_arguments(t_prgm *vars);
void	check_both_cmds(t_prgm *vars);

/* errors_3.c */
void	exit_if_failed_malloc_path_file2_short(char *s);

/* error_management.c */
void	sum_error_codes_1st_half_pipe(t_prgm *vars);
void	sum_error_codes_2nd_half_pipe(t_prgm *vars);
void	priorization_error_code_1st_half_pipe(t_prgm *vars);
void	priorization_error_code_2nd_half_pipe(t_prgm *vars);
void	error_exit(t_prgm *vars);

/* check_existence_permission_files.c */
void	check_existence_file1(t_prgm *vars);
void	check_existence_file2(t_prgm *vars);
void	check_r_right_file1(t_prgm *vars);
void	check_w_right_file2(t_prgm *vars);

/* child_processes.c */
void	child_process_cmd1(int infile, int *fildes, t_prgm *vars);
void	child_process_cmd2(int outfile, int *fildes, t_prgm *vars);

/* open_files.c */
void	open_file1(t_prgm *vars);
void	open_file2(t_prgm *vars);
void	open_both_files(t_prgm *vars);

/* piping_n_forking.c */
int		error_msg_failed_pipe(int n);
int		error_msg_fork_child1_failed(int n);
int		error_msg_fork_child2_failed(int n);
int		pipe_and_fork(t_prgm *vars, int *fildes);

/* get_paths.c */
char	*find_path_in_envp(t_prgm vars);
void	split_path(t_prgm *vars, char *s);

/* get_commands_1.c */
char	*get_cmd1_path(t_prgm *vars);
void	init_argv_2_3_into_struct(t_prgm *vars);
void	init_cmd1_into_struct(t_prgm *vars);
void	init_cmd1_into_struct_helper(t_prgm *vars);

/* get_commands_2.c */
char	*get_cmd2_path(t_prgm *vars);
void	init_cmd2_into_struct_helper(t_prgm *vars);
void	init_cmd2_into_struct(t_prgm *vars);

/* parent_process.c */
int		parent_process(t_prgm vars, int *fildes, int chi1, int chi2);

/* utils.c */
void	free_table(char **table);
void	free_stuff(t_prgm *vars);
void	copy_path_to_struct(t_prgm *vars, int n);
char	*copy_cmd_name_only(char *s);

#endif