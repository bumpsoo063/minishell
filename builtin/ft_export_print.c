/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:12:06 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/19 14:37:08 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	ft_order(char **temp)
{
	int		i;
	int		j;
	int		small;
	char	*tmp;

	i = 0;
	while (temp[i] != 0)
	{
		j = i;
		small = j;
		while (temp[++j] != 0)
		{
			if (ft_strncmp(temp[small], temp[j], ft_strlen(temp[j]) + 1) > 0)
				small = j;
		}
		tmp = temp[small];
		temp[small] = temp[i];
		temp[i] = tmp;
		i++;
	}
	i = 0;
	while (temp[i] != 0)
		printf("%s\n", temp[i++]);
}

static int	ft_export_size(char **env)
{
	int	i;

	i = 0;
	while (env[i] != 0)
		i++;
	return (i);
}

void	ft_export_print(char **env)
{
	char	**temp;
	int		i;
	int		size;

	size = ft_export_size(env);
	temp = malloc(sizeof(char *) * (size + 1));
	ft_check_error();
	i = 0;
	while (i < size)
	{
		temp[i] = env[i];
		i++;
	}
	temp[i] = 0;
	i = 0;
	ft_order(temp);
	free(temp);
}
