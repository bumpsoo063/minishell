/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:05:31 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/17 22:46:30 by bechoi           ###   ########.fr       */
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
	
	signal(SIGINT, SIG_IGN);
	if (pipe(fd) < 0)
	{
		
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		//자식 프로세스(명령어실행)
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		//명령어 실행하는 곳 상의 필요(외부 함수 제외 빌트인 함수 에러처리 필요)
		exit(ft_exec(cmd, info));
		//////////////////////////////
	}
	// 부모 프로세스(결과값 stdin으로 변경)
	wait(&temp);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	signal(SIGINT, ft_sigint);
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
