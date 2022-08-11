#ifndef MINISHELL_H
# define MINISHELL_H
# include "const.h"
# include "t_queue/t_queue.h"

// env -> 새롭게 export 한 변수들
// old_env -> 프로그램 시작시 받아오는 변수들
// 두 개 다 사용할 경우 info넘겨서 사용해야할듯?
// parse = 파싱 후 문자열의 배열
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
	t_q_re	*re;
}	t_info;

void	ft_check_error(void);

t_info	g_info;

#endif
