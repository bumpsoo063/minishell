/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:05:45 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/02 14:17:13 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include <unistd.h>

void	ft_check_error(void);

// string.h -> libft.h>
// strdup -> ft_strdup
// strncmp -> ft_strncmp
static void	ft_check_env(char *str, char **env)
{
	char const	*del = strchr(str, '=');
	const int	len = del - str;
	char		**ep;
	char		**temp;

	ep = env;
	while (*ep != 0)
	{
		if (strncmp(*ep, str, len) == 0 && (*ep)[len] == '=')
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

static bool	ft_check_str(char *str)
{
	char	*temp;

	if (str == 0 || *str == 0 || *str == '=')
		return (false);
	temp = strchr(str, '=');
	if (temp != 0)
		if (*(temp - 1) != 0 && *(temp + 1) != 0)
			return (true);
	return (false);
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
		ret[i] = strdup(env[i]);
		ft_check_error();
		i++;
	}
	ret[i] = strdup(str);
	ret[i + 1] = 0;
	i = 0;
	while (env[i] != 0)
		free(env[i++]);
	free(env[i]);
	free(env);
	return (ret);
}

char	**ft_export(char *str, char **env)
{
	char	**ret;

	if (ft_check_str(str) == false)
		return (0);
	ft_check_env(str, env);
	return (ft_dup(str, env));
}
