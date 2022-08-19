/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:18:04 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/19 15:11:28 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	ft_unset_err(char *str, int i)
{
	if (i)
	{
		write(2, "minishell: ", 11);
		write(2, "unset: ", 7);
		write(2, str, ft_strlen(str));
		write(2, ": not a valid identifier\n", 26);
		return (1);
	}
	return (0);
}

static int	ft_unset_check(char *str)
{
	while (str && *str)
	{
		if (!(ft_isalpha(*str) || *str == '_'))
			return (ft_unset_err(str, 1));
		str++;
	}
	return (0);
}

int	ft_unset_help(char *str, char **env)
{
	const size_t	len = ft_strlen(str);
	char			**ep;
	char			**temp;

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
	return (0);
}

int	ft_unset(char **str, char **env)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	if (str == 0)
		return (1);
	while (str[i] != 0)
	{
		if (ft_unset_check(str[i]))
		{
			ret = 1;
			i++;
			continue ;
		}
		ft_unset_help(str[i], env);
		i++;
	}
	return (ret);
}
