/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:10:36 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/03 22:38:29 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_echo.h"

char	*ft_echo(char *str, int offset)
{
	char	*ret;
	char	*tmp;

	ret = ft_strdup(str);
	if (offset)
	{
		tmp = ret;
		ret = ft_strjoin(ret, "\n");
		free(tmp);
	}
	return (ret);
}
