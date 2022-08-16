/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:09:02 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/12 20:48:56 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execve.h"
#include <sys/types.h>
#include <sys/wait.h>

static int	ft_process(char	**path, char **str, char **env)
{
	pid_t	pid;
	int		i;
	char	*cmd;
	int		ret;

	pid = fork();
	if (pid < 0)
		// return 값 고민
		return (1);
	if (pid == 0)
	{
		i = 0;
		while (path[i])
		{
			cmd = ft_strjoin(path[i++], str[0]);
			execve(cmd[0], str, NULL);
		}
		exit(1);
	}
	wait(&ret);
	return (ret);
}

static int	ft_free(char **str, char **path)
{
	int	i;

	i = 0;
	if (path)
	{
		while (path[i])
			free(path[i++]);
		free(path);
	}
	if (str)
	{
		i = 0;

		while (str[i])
			free(str[i++]);
		free(str);
	}
	return (0);
}

int	ft_execve(char **cmd, char **env)
{
	char	**path;
	int		ret;
	char	*tmp;

	
	tmp = ft_substitute(ft_strdup("$PATH"), env);
	path = ft_split(tmp, ':');
	free(tmp);
	if (!path)
		return (0);
	ret = ft_process(path, cmd);
	// cmd free 여부 상의
	ft_free(cmd, path);
	return (ret);
}

/*
int	main(int ac, char **av, char **env)
{
	ft_execve("cat", env);
}
*/

