/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:58:36 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/19 14:11:15 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECVE_H
# define FT_EXECVE_H
# include "../minishell.h"
# include <stdio.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <errno.h>
# include "../ft_parse/ft_parse.h"
# include "../ft_sig/ft_sig.h"

int	ft_execve(char **cmd, char **env, t_info *info);

#endif
