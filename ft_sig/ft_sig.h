#ifndef FT_SIG_H
#define FT_SIG_H
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "../minishell.h"

void	ft_save_init(t_term *org_term);
void	ft_set_term();
void	ft_reset_term(t_term *org_term);
int	is_whitespace(char *line);
void	ft_sigint(int signal);
void	ft_set_signal();
void	ft_set_child(int offset);
void	ft_child_term(t_info *info);

#endif
