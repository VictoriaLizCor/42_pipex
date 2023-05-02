/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:23:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/02 17:39:38 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	**str;
	char	**cpy;
	pid_t	pid;
	int		fd[2], nbytes;
	char	string[] = "Hello, world!\n";
	char	readbuffer[80];

	if (argc != 5)
		ft_error("Invalid input");
	if (pipe(fd) < 0)
		ft_error("Failed to create pipe");
	pid = fork();
	if (pid == -1)
		ft_error("Fork failed");
	if(pid == 0)
	{
		/* Child process closes up input side of pipe */
		close(fd[0]);
		/* Send "string" through the output side of pipe */
		write(fd[1], string, (ft_strlen(string) + 1));
	}
	else
	{
		/* Parent process closes up output side of pipe */
		close(fd[1]);

		/* Read in a string from the pipe */
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		printf("Received string: %s", readbuffer);
	}
	ft_printf("Input : %d\n", argc);
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
	return (0);
}
