/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:09:02 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/19 14:11:27 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execve.h"

static char	*ft_slash(char *path, char *str)
{
	char	*ret;
	char	*tmp;

	ret = ft_strjoin(path, "/");
	tmp = ret;
	ret = ft_strjoin(ret, str);
	free(tmp);
	return (ret);
}

static void	ft_child_process(char **path, char **str, t_info *info)
{
	int		i;
	char	*cmd;

	i = 0;
	if (path == 0)
		execve(str[0], str, info->env);
	else
	{
		while (path[i])
		{
			cmd = ft_slash(path[i++], str[0]);
			execve(cmd, str, info->env);
		}
	}
}

static int	ft_process(char	**path, char **str, t_info *info)
{
	pid_t	pid;
	int		ret;

	ft_set_child(0);
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		ft_child_term(info);
		ft_set_child(1);
		ft_child_process(path, str, info);
		if (errno == 13)
			exit(126);
		exit(127);
	}
	wait(&ret);
	ft_set_child(2);
	ft_set_term(info);
	if (WIFSIGNALED(ret))
	{
		write(1, "\n", 1);
		return (128 + WTERMSIG(ret));
	}
	return (WEXITSTATUS(ret));
}

static int	ft_free(char **path)
{
	int	i;

	i = 0;
	if (path)
	{
		while (path[i])
			free(path[i++]);
		free(path);
	}
	return (0);
}

int	ft_execve(char **cmd, char **env, t_info *info)
{
	char	**path;
	int		ret;
	char	*tmp;

	if (ft_strchr(cmd[0], '/'))
	{
		ret = ft_process(0, cmd, info);
		return (ret);
	}
	tmp = ft_substitute(ft_strdup("$PATH"), env, info);
	path = ft_split(tmp, ':');
	free(tmp);
	if (!path)
		return (1);
	ret = ft_process(path, cmd, info);
	ft_free(path);
	return (ret);
}
