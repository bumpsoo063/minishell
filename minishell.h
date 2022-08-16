#ifndef MINISHELL_H
# define MINISHELL_H
# include "const.h"
# include "t_queue/t_queue.h"

typedef struct	s_fd
{
	int	out;
	int	in;
}	t_fd;

// ex: bash$ export PATH=$PATH:/home/bumpsoo/local
// parse ->
// 	"export"
// 	"PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/home/bumpsoo/local"
// ex2: bash$ <main.c 
// 	"<"
// 	"main.c"
typedef struct s_info
{
	char	**env;
	char	**parse;
	t_fd	fd;
}	t_info;

void	ft_check_error(void);

t_info	g_info;

#endif
