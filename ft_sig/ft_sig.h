/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:19:09 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/18 21:33:46 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIG_H
# define FT_SIG_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "../minishell.h"

void	ft_set_term(t_info *info);
int		is_whitespace(char *line);
void	ft_sigint(int signal);
void	ft_set_signal(void);
void	ft_set_child(int offset);
void	ft_child_term(t_info *info);

#endif
