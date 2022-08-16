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
	char	**cmd;
	int		ret;

	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		cmd = ft_calloc(sizeof(char *), 3);
		cmd[1] = str[1];
		i = 0;
		while (path[i])
		{
			cmd[0] = ft_strjoin(path[i++], str[0]);
			execve(cmd[0], cmd, NULL);
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
	char	**str;
	int		ret;
	char	*tmp;

	
	tmp = ft_substitute(ft_strdup("$PATH"), env);
	path = ft_split(tmp, ':');
	free(tmp);
	if (!path)
		return (0);
	str = ft_split(cmd, ' ');
	ret = ft_process(path, str);
	ft_free(str, path);
	return (ret);
}

/*
int	main(int ac, char **av, char **env)
{
	ft_execve("cat", env);
}
*/

