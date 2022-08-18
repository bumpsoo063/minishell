/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:05:45 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/18 21:12:02 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "../minishell.h"
#include "../libft/libft.h"
#include "builtin.h"

static void	ft_check_env(char *str, char **env)
{
	char const	*del = ft_strchr(str, Equal);
	const int	len = del - str;
	char		**ep;
	char		**temp;

	ep = env;
	while (*ep != 0)
	{
		if (ft_strncmp(*ep, str, len) == 0 && (*ep)[len] == Equal)
		{
			temp = ep;
			free(*temp);
			while (*temp != 0)
			{
				*temp = *(temp + 1);
				temp++;
			}
		}
		else
			ep++;
	}
}

static int	ft_check_str(char *str)
{
	char	*temp;

	if (str == 0 || *str == 0 || *str == Equal)
		return (1);
	temp = ft_strchr(str, Equal);
	if (temp != 0)
		if (*(temp - 1) != 0 && *(temp + 1) != 0)
			return (0);
	return (1);
}

static char	**ft_dup(char *str, char **env)
{
	char	**ret;
	int		i;

	i = 0;
	while (env[i] != 0)
		i++;
	ret = malloc(sizeof(char *) * (i + 2));
	ft_check_error();
	i = 0;
	while (env[i] != 0)
	{
		ret[i] = ft_strdup(env[i]);
		ft_check_error();
		i++;
	}
	ret[i] = ft_strdup(str);
	ret[i + 1] = 0;
	i = 0;
	while (env[i] != 0)
		free(env[i++]);
	free(env);
	return (ret);
}

int	ft_export(char **str, t_info *info)
{
	int		i;
	char	**env;

	i = 0;
	env = info->env;
	if (str == 0)
	{
		while (env[i] != 0)
			i++;
		ft_export_print(env, i);
		info->env = env;
		return (0);
	}
	while (str[i] != 0)
	{
		if (ft_check_str(str[i]))
			return (1);
		ft_check_env(str[i], env);
		env = ft_dup(str[i], env);
		i++;
	}
	info->env = env;
	return (0);
}
