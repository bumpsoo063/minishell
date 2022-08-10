/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:09:02 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/10 21:49:01 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirect.h"

int	ft_execve(char *cmd)
{
	char	**path;
	int		i;
	char	**str;
	char	*tmp;
	int		flag;

	str = ft_calloc(sizeof(char*), 2);
	path = ft_calloc(sizeof(char*), 7);
	flag = 0;
	if (!path)
		return (flag);
	path[0] = "/usr/local/bin/";
	path[1] = "/usr/bin/";
	path[2] = "/bin/";
	path[3] = "/usr/sbin/";
	path[4] = "sbin/";
	path[5] = "/usr/local/munki";
	i = 0;
	while (!flag && i < 6)
	{
		str = ft_split(cmd, ' ');
		tmp = str[0];
		printf("%s\n", tmp);
		str[0] = ft_strjoin(path[i++], str[0]);
		printf("%s\n", tmp);
		if (!execve(str[0], str, NULL))
			flag = 1;
		free(tmp);
	}
	free(str[0]);
	free(str[1]);
	free(str);
	free(path);
	return (flag);
}

int	main(int ac, char **av)
{
	ft_execve(av[1]);
	return (0);
}
