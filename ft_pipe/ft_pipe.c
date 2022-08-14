/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:05:31 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/12 21:08:31 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipe.h"

#define MAX_BUF 1024 

int	ft_pipe(char *cmd)
{
	pid_t	pid;
	int		fd[2];
	int		oldfd;
	
	if (pipe(fd) < 0)
		return (0);
	pid = fork();
	if (pid == 0)
	{
		//자식 프로세스(명령어실행)
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		//명령어 실행하는 곳 상의 필요(외부 함수 제외 빌트인 함수 에러처리 필요)
		ft_execve(cmd);
		//////////////////////////////
		exit(1);
	}
	// 부모 프로세스(결과값 stdin으로 변경)
	wait(0);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	return (fd[0]);
}

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
}
