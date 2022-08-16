/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:09:15 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/16 15:21:04 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

int	ft_pwd(void)
{
	char	*buf;
	
	buf = ft_calloc(sizeof(char), 1024);
	if (!buf)
		return (0);
	getcwd(buf, 1024);
	printf("%s\n", buf);
	free(buf);
	return (1);
}
