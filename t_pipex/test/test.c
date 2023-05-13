/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:19:28 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/13 11:30:39 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdarg.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

void	runpipe(int pfd[], char **cmd1, char **cmd2, char **env)
{
	int	pid;
	int	status;

	switch (pid = fork()) {

	case 0: /* child */
		dup2(pfd[0], STDIN_FILENO);
		close(pfd[1]);	/* the child does not need this end of the pipe */
		execve(cmd2[0], cmd2, 0);
		perror(cmd2[0]);
	default: /* parent */
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[0]);	/* the parent does not need this end of the pipe */
		execve(cmd1[0], cmd1, 0);
		perror(cmd1[0]);
	case -1:
		perror("fork");
		exit(1);
	
}
}

int	main(int argc, char **argv, char **env)
{
	int	pid, status;
	int	fd[2];
	char *str;
	char *cmd1[] = { "/bin/cat", argv[1], 0 };
	char *cmd2[] = { "/usr/bin/tr", "a-z", "A-Z", 0 };
	// char *cmd2[] = { "/bin/zsh", "zsh -c l", 0};
	pipe(fd);
	switch (pid = fork()) {
		case 0: /* child */
			runpipe(fd, cmd1, cmd2, env);
			exit(0);
		default: /* parent */
			break;
		case -1:
			perror("fork");
			exit(1);
	}
	exit(0);
}
