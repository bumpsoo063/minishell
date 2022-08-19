/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:05:45 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/19 14:32:05 by bechoi           ###   ########.fr       */
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

static int	ft_export_err(char *str, int i)
{
	if (i)
	{
		write(2, "minishell: ", 11);
		write(2, "export: ", 8);
		write(2, str, ft_strlen(str));
		write(2, ": not a valid identifier\n", 26);
		return (1);
	}
	return (0);
}

static int	ft_check_str(char *str)
{
	int		ret;

	ret = 0;
	while (*str)
	{
		if ((ft_isalpha(*str) || *str == '_'))
		{
			if (*(str + 1) == Equal)
			{
				break ;
			}
		}
		else
		{
			ret = 1;
			break ;
		}
		str++;
	}
	if (*str == 0)
		ret = 1;
	return (ft_export_err(str, ret));
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
	int		ret;

	i = 0;
	ret = 0;
	env = info->env;
	if (str == 0 || str[i] == 0)
		ft_export_print(env);
	while (str && str[i] != 0)
	{
		if (ft_check_str(str[i]) == 1)
		{
			ret = 1;
			i++;
			continue ;
		}
		ft_check_env(str[i], env);
		env = ft_dup(str[i], env);
		i++;
	}
	info->env = env;
	return (ret);
}
