/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:05:31 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/10 18:45:02 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipe.h"

#define MAX_BUF 1024 

int	main(int ac, char **av)
{
	int		fd[2];
	pid_t	pid;
	char	buf[1024];

	if (pipe(fd) < 0)
	{
		printf("Error\n");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		printf("Error\n");
		return (1);
	}
	// 자식프로세스
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		ft_execve(av[1]);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[1]);
		read(fd[0], buf, MAX_BUF);
		printf("%s\n", buf);
	}
	return (0);
}
