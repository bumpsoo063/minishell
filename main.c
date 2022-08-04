#include "minishell.h"
#include <readline/readline.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_info	info;

	argc = 0;
	argv = 0;
	info.env = ft_init_env(env);
	input = readline("minishell");
	while (input)
	{
		info.parse = ft_parse(input, info.env);
		for (int i = 0; info.parse[i] != 0; i++)
		{
			printf("%s\n", info.parse[i]);
		}
		add_history(input);
		free(input);
		input = readline("minishell");
	}
}
