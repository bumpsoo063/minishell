/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:58:22 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/02 14:17:46 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_check_error.c"

// string -> libft
// strdup -> ft_strdup
char	**ft_init_env(char **env)
{
	char	**ret;
	int		i;

	i = 0;
	while (env[i] != 0)
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	ft_check_error();
	i = 0;
	while (env[i] != 0)
	{
		ret[i] = strdup(env[i]);
		ft_check_error();
		i++;
	}
	ret[i] = 0;
	return (ret);
}
