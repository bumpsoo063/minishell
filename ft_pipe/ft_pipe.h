/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:45:10 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/17 18:00:38 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPE_H
# define FT_PIPE_H
# define MAX_BUF 1024 

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../ft_redirect/ft_redirect.h"
# include "../libft/libft.h"
# include "../minishell.h"

int	ft_pipe(char **cmd, t_info *info);

#endif
