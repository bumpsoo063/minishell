/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:09:02 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/05 15:37:18 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirect.h"

void	ft_execve(char *cmd)
{
	char	**path;
	int		i;
	char	**str;

	str = ft_calloc(sizeof(char*), 2);
	path = ft_calloc(sizeof(char*), 7);
	if (!path)
		return ;
	path[0] = "/usr/local/bin/";
	path[1] = "/usr/bin/";
	path[2] = "/bin/";
	path[3] = "/usr/sbin/";
	path[4] = "sbin/";
	path[5] = "/usr/local/munki";
	i = 0;
	while (i < 6)
	{
		str[0] = ft_strjoin(path[i++], cmd);
		if (!execve(str[0], str, NULL))
			break ;
	}
	free(str[0]);
	free(str);
	free(path);
}

int	main(int ac, char **av)
{
	
	char	**str;
	int		i;
	int		fd;

	i = 0;
	fd = open("log", O_WRONLY | O_CREAT);
	str = calloc(sizeof(char *), 2);
	str[0] = "/bin/ls";
	str[1] = 0;
	dup2(fd, STDOUT_FILENO);
	execve(str[0], str, NULL);
	
//	ft_execve(av[1]);
	return (0);
}
