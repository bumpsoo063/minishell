#ifndef MINISHELL_H
# define MINISHELL_H

enum	e_chars {
	QUOTE = 27,
	D_QUOTE = 22,
	INPUT = 60,
	OUTPUT = 62,
	PIPE = 124,
	EQUAL = 61,
	SPACE = 32,
	DOLLAR = 36,
	BRACE_O = 123,
	BRACE_C = 125,
};

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
	char	**old_env;
	char	**env;
	char	**parse;
}	t_info;

char	**ft_init_env(char **env);
char	**ft_parse(char *str, t_info *info);
void	ft_check_error(void);


#endif
