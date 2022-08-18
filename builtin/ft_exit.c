/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:16:13 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/17 17:05:03 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

int	ft_exit(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	if (i > 1)
	{
		printf("too many arguments\n");
		return (1);
	}
	else
	{
		printf("exit\n");
		if (i == 0)
			exit(0);
		else
			exit(ft_atoi(str[0]));
	}
}
