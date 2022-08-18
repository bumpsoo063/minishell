/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:43:43 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/18 21:35:50 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REDIRECT_H
# define FT_REDIRECT_H
# define FILE_NAME "/tmp/.minishell_heredoc"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include "../libft/libft.h"
# include "../minishell.h"

int	ft_gt(char *path, int offset);
int	ft_lt(char *path);
int	ft_dlt(char *end, t_info *info);
int	ft_rm_heredoc(void);
int	ft_red(char **parse, t_info *info);

#endif
