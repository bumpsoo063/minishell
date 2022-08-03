/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:18:04 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/02 19:03:59 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../minishell.h"

// string.h -> libft.h>
// strncmp -> ft_strncmp
void	ft_unset(char *str, char **env)
{
	const size_t	len = strlen(str);
	char			**ep;
	char			**temp;

	ep = env;
	while (*ep != 0)
	{
		if (strncmp(*ep, str, len) == 0 && (*ep)[len] == EQUAL)
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
