/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:23:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/03 16:02:56 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
checked (R_OK for read permission, W_OK for write permission, 
 and X_OK for execute/search permission), or the existence test (F_OK).
*/
void	parent_process(int *fd, char **argv, char **env)
{
	char	**str;
	char	**cpy;

	dup2(fd[1], 1);
	close(fd[0]);
	ft_printf("\n");
	while (*argv)
	{
		ft_printf("%s\n", *argv);
		if (ft_strchr(*argv, ' '))
		{
			str = ft_split(*argv, ' ');
			cpy = str;
			while (*cpy)
			{
				ft_printf("\t\t %s\n", *cpy);
				cpy++;
			}
			ft_free(str);
		}
		argv++;
	}
	while (*env && !ft_strnstr(*env, "PATH=", ft_strlen(*env)))
		env++;
	ft_printf("\t\t %s\n", *env);
}

//int execve(const char *path, char *const argv[], char *const envp[]);
void	child_process(int *fd, char **argv, char **env)
{
	int		pid;
	char	**str;
	char	**cpy;

	pid = fork();
	if (pid < 0)
		ft_error("Fork failed");
	if (!pid)
	{
		dup2(fd[0], 0);
		close(fd[1]);
		if (ft_strchr(argv[2], ' '))
		{
			str = ft_split(argv[2], ' ');
			cpy = str;
			while (*cpy)
			{
				ft_printf("\t\t  %s\n", *cpy);
				cpy++;
			}
		}
		else
			str = argv + 2;
		if (execve(str[0], &argv[2], env) < 0)
			perror(str[0]);
		ft_printf("\t\t %s \n", str[0]);
		if (str != argv + 2)
			ft_free(str);
	}
	ft_printf("CHILD PROCESS\n\n\n");
}

int	main(int argc, char **argv, char **env)
{	
	pid_t		pid;
	int		status;
	int		fd[2];

	ft_printf("Input : %d\n", argc);
	if (argc != 5)
		ft_error("Invalid input");
	while (*env && !ft_strnstr(*env, "PATH=", ft_strlen(*env)))
		env++;
	ft_printf("\t\t %s\n", *env);
	if (pipe(fd) < 0)
		ft_error("Failed to create pipe");
	pid = fork();
	if (pid < 0)
		ft_error("Fork failed");
	if (!pid)
		child_process(fd, argv, env);
	else
	{
		while ((pid = wait(&status) != -1))
		{
			ft_printf("%d\n", errno);
			fprintf(stderr, "\n\nprocess %d exits with %d\n", pid, WEXITSTATUS(status));
			if (pid)
			{
				parent_process(fd, argv, env);
				break;
			}
			if ((errno != EINTR))
				perror("waitpid");
		}
	}
	return (0);
}
