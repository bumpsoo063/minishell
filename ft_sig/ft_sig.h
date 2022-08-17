#ifndef FT_SIG_H
#define FT_SIG_H
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

typedef struct termios t_term;

void	ft_save_init(t_term *org_term);
void	ft_set_term(t_term *new_term);
void	ft_reset_term(t_term *org_term);
int	is_whitespace(char *line);
void	ft_sigint(int signal);
void	ft_set_signal();

#endif
