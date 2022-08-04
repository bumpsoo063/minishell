/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:25:19 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/04 17:31:08 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"
#include "../libft/libft.h"
#include "../minishell.h"

static char	*ft_value(char *key, char *env)
{
	char	*ret;

	ret = 0;
	if (ft_strncmp(key, env, ft_strlen(key)) == 0)
	{
		if (*(env + ft_strlen(key)) == EQUAL)
		{
			ret = ft_strdup(env + ft_strlen(key) + 1);
			ft_check_error();
		}
	}
	return (ret);
}

char	*ft_search_env(char *key, char **env)
{
	char	*value;
	int	i;

	i = 0;
	value = 0;
	while (env[i] != 0)
	{
		value = ft_value(key, env[i]);
		if (value != 0)
			return (value);
		i++;
	}
	i = 0;
	return (0);
}
