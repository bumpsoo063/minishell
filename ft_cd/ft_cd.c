/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:07:29 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/05 16:21:30 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"
#include "../libft/libft.h"
#include <errno.h>
#include <string.h>

char	*ft_cd(char *str)
{
	char	*ret;
	char	*tmp;

	if (chdir(str))
	{
		ret = ft_strdup("cd: No such file or directory: ");
		tmp = ret;
		ret = ft_strjoin(ret, str);
		free(tmp);
		tmp = ret;
		ret = ft_strjoin(ret, "\n");
		free(tmp);
		return (ret);
	}
	return (0);
}
