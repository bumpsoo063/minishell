#include "minishell.h"
#include <readline/readline.h>
#include <stdlib.h>
#include <errno.h>

#include <stdio.h>
int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_info	info;

	argc = 0;
	argv = 0;
	info.env = ft_init_env(env);
	input = readline("minishell $ ");
	// 이유는 모르겠지만 readline을 호출할 때 errno이 2로 바뀌어서 초기화를 해줘야함
	errno = 0;
	info.parse = ft_parse(input, info.env);
	for (int i = 0; info.parse[i] != 0; i++)
	{
		printf("%s\n", info.parse[i]);
	}
}
