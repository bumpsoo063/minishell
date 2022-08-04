#include "minishell.h"
#include <readline/readline.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_info	info;

	info.env = ft_init_env(env);
	input = readline("minishell");
	while (input)
	{
		input = readline("minishell");
		info.parse = ft_parse(input, &info);
		add_history(input);
		free(input);
	}
}
