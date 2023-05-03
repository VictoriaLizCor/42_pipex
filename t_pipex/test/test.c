/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:19:28 by lilizarr          #+#    #+#             */
/*   Updated: 2023/05/03 09:44:15 by lilizarr         ###   ########.fr       */
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

void	runpipe(int pfd[], char **cmd1, char **cmd2)
{
	int	pid;

	switch (pid = fork()) {

	case 0: /* child */
		dup2(pfd[0], 0);
		close(pfd[1]);	/* the child does not need this end of the pipe */
		execvp(cmd2[0], cmd2);
		perror(cmd2[0]);

	default: /* parent */
		dup2(pfd[1], 1);
		close(pfd[0]);	/* the parent does not need this end of the pipe */
		execvp(cmd1[0], cmd1);
		perror(cmd1[0]);

	case -1:
		perror("fork");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int	pid, status;
	int	fd[2];
	char *cmd1[] = { "/bin/ls", "-al", "/", 0 };
	char *cmd2[] = { "/usr/bin/tr", "a-z", "A-Z", 0 };
	pipe(fd);

	switch (pid = fork()) {
		case 0: /* child */
			runpipe(fd, cmd1, cmd2);
			exit(0);
		default: /* parent */
			while ((pid = wait(&status)) != -1)
				fprintf(stderr, "\n\nprocess %d exits with %d\n", pid, WEXITSTATUS(status));
			break;
		case -1:
			perror("fork");
			exit(1);
	}
	exit(0);
}
