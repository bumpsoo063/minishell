/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:18:04 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/17 17:54:07 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include "../minishell.h"
#include "../const.h"

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

	i = 0;
	if (str == 0)
		return (1);
	while (str[i] != 0)
	{
		ft_unset_help(str[i], env);
		i++;
	}
	return (0);
}
