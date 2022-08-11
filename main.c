#include "minishell.h"
#include <readline/readline.h>
#include <stdlib.h>
#include <errno.h>
#include "libft/libft.h"
#include "ft_parse/ft_parse.h"
#include "ft_init/ft_init.h"
#include "t_queue/t_queue.h"

#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	char	*input;

	argc = 0;
	argv = 0;
	g_info.env = ft_init_env(env);
	while (1)
	{
		input = readline(PROM);
		errno = 0;
		if (input == 0)
			break ;
		add_history(input);
		g_info.parse = ft_parse(input, g_info.env);
		for (int i = 0; g_info.parse[i] != 0; i++)
			printf("%s\n", g_info.parse[i]);
		if (ft_parse_syntax(g_info.parse) != 0)
		{
			write(2, PARSE_ERROR, ft_strlen(PARSE_ERROR));
			continue ;
		}
		g_info.re = ft_init_re(g_info.parse);
		// fd, buf 초기화
		// 실행
		ft_parse_free(g_info.parse);
		t_q_re_free(&g_info.re);
		free(input);
		// system("leaks minishell");
	}
}
