/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:05:31 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/19 14:08:48 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipe.h"

static int	ft_wait(int *fd, t_info *info)
{
	int	ret;

	wait(&ret);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	ft_set_child(2);
	ft_set_term(info);
	if (WIFSIGNALED(ret))
	{
		write(1, "\n", 1);
		return (128 + WTERMSIG(ret));
	}
	return (WEXITSTATUS(ret));
}

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
	return (ft_wait(fd, info));
}
