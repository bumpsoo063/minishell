/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:12:06 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/19 14:19:53 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static char	**ft_order(char **temp)
{
	int	i;
	int	j;
	int	small;

	i = 0;
	while (temp[i] != 0)
	{
		j = i;
		small = j;
		while (temp[j] != 0 && temp[j + 1] != 0)
		{
			if (ft_strncmp(temp[j], temp[j + 1], ft_strlen(temp[j]) + 1 < 0))
			{
				small = j;
			}
			j++;
		}
		temp[i] = temp[small];
		i++;
	}
	return (temp);
}

void	ft_export_print(char **env, int size)
{
	char	**temp;
	int		i;

	temp = malloc(sizeof(char *) * (size + 1));
	ft_check_error();
	i = 0;
	while (i < size)
	{
		temp[i] = env[i];
		i++;
	}
	temp[i] = 0;
	temp = ft_order(temp);
	i = 0;
	while (temp[i] != 0)
	{
		printf("%s\n", temp[i++]);
	}
	free(temp);
}
