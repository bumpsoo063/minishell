#include "minishell.h"
#include <readline/readline.h>
#include <stdlib.h>
#include <errno.h>
#include "libft/libft.h"
#include "ft_parse/ft_parse.h"
#include "ft_init/ft_init.h"

#include <stdio.h>

static int	ft_check_pipe(char **parse)
{
	int	i;

	i = 0;
	while (parse[i] != 0)
	{
		if (parse[i][0] == Pipe)
		{
			if (i == 0)
				return (1);
			else
			{
				if (parse[i - 1][0] == Pipe)
					return (1);
			}
		}
		i++;
	}
	return (0);
}

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
		if (ft_check_pipe(g_info.parse) != 0)
		{
			write(2, PIPE_ERROR, ft_strlen(PIPE_ERROR));
			continue ;
		}
		g_info.re = ft_init_re(g_info.parse);
		// g_info.parse -> should be freed
		// re either
	}
}
