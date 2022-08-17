/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:07:29 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/17 16:53:54 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <errno.h>
#include <string.h>
#include "../minishell.h"

int	ft_cd(char *str, t_info *info)
{
	char	**buf;
	char	*tmp;

	buf = ft_calloc(sizeof(char *), 2);
	if (!buf)
		return (-1);
	buf[0] = ft_calloc(sizeof(char), 1025);
	if (chdir(str))
		return (-1);
	getcwd(buf[0], 1024);
	tmp = buf[0];
	buf[0] = ft_strjoin("OLDPWD=", buf[0]);
	free(tmp);
	info->env = ft_export(buf, info->env);	
	return (0);
}
