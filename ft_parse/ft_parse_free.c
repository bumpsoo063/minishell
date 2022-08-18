/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:14:01 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/18 21:14:02 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_parse_free(char **parse)
{
	int	i;

	i = 0;
	if (parse)
	{
		while (parse[i] != 0)
		{
			free(parse[i]);
			i++;
		}
		free(parse);
	}
}
