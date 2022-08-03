/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:43:34 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/04 04:09:41 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirect.h"

void	*ft_gt(char *path, char *str, int offset)
{
	int	fd;
	
	if (offset)
		fd = open(path, O_CREAT | O_APPEND);
	else
		fd = open(path, O_CREAT | O_TRUNC);
	write(fd, str, ft_strlen(str));	
}

char	*ft_lt(char *path)
{
	char	*ret;

}

char	*ft_redirect(char *str)
{

}
