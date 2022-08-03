/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:17:29 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/02 14:55:06 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// strlen -> ft_strlen
void	ft_check_error(void)
{
	if (errno > 0)
	{
		write(2, strerror(errno), strlen(strerror(errno)));
		exit(1);
	}
}
