#ifndef MINISHELL_H
# define MINISHELL_H
# include "const.h"

typedef struct s_info
{
	char	**env;
	char	**parse;
	int	in;
	int	out;
	int	exit;
}	t_info;

void	ft_check_error(void);
t_info	ft_init_info(int argc, char **argv, char **env);
void	ft_clean_fd(t_info *info);
void	ft_clean_info(t_info *info, char *input);
int	ft_exec(char **cmd ,t_info *info);
int	ft_command(char **parse, t_info *info);

t_info	g_info;

#endif
