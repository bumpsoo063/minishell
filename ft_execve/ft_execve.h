/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:58:36 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/17 17:57:08 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECVE_H
# define FT_EXECVE_H
# include "../minishell.h"
# include <stdio.h>
# include "../libft/libft.h"
# include <unistd.h>

int	ft_execve(char **cmd, char **env, t_info *info);

#endif
