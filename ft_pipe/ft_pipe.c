/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:05:31 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/12 05:49:52 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipe.h"

#define MAX_BUF 1024 

int	main(void)
{
	int		fd[2];
	char	buf[1024];
	int		oldfd;
	pid_t	pid;
	char	*cmd1;
	char	*cmd2;

	cmd1 = "cat log";
	cmd2 = "wc";
	if (pipe(fd) < 0)
		return (0);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_execve(cmd1);
		exit(1);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
		if (!ft_execve(cmd2))
			printf("error!!!\n");
	}
	return (0);
}
