/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:05:31 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/18 18:14:59 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipe.h"
#include "../ft_execve/ft_execve.h"
#include <sys/wait.h>
#include "../ft_sig/ft_sig.h"

int	ft_pipe(char **cmd, t_info *info)
{
	pid_t	pid;
	int		fd[2];
	int		temp;
	
	ft_set_child(0);
	if (pipe(fd) < 0)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		ft_child_term(info);
		ft_set_child(1);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		temp = ft_exec(cmd, info);
		exit(temp);
	}
	wait(&temp);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	ft_set_child(2);
	ft_set_term();
	if (WIFSIGNALED(temp))
	{
		write(2, "\n", 1);
		return (128 + WTERMSIG(temp));
	}
	return (WEXITSTATUS(temp));
}
/*
int	main(void)
{
	char	*cmd1;
	char	*cmd2;
	int		oldfd;
	pid_t	pid;
	int		fd[2];

	oldfd = dup(STDIN_FILENO);
	cmd1 = "cat log";
	cmd2 = "> 5";
	ft_pipe(cmd1);

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_execve("echo 123");
		exit(1);
	}
	wait(0);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	ft_execve(cmd2);
	close(fd[0]);
	return (0);
}*/
