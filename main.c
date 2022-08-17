#include "minishell.h"
#include "libft/libft.h"
#include "ft_parse/ft_parse.h"
#include "builtin/builtin.h"
#include "ft_sig/ft_sig.h"
#include <errno.h>
#include <readline/readline.h>

#include <string.h>

static int	ft_process(t_info *info)
{
	char	**parse;

	parse = info->parse;
	while (*parse != 0)
	{
		if (ft_red(parse) == 0)
		{
			// ㅇㅔ러 출력
			// ft_clean_info
			return (0);
		}
		if (ft_command(parse) == 0)
		{

			// ㅇㅔ러 출력
			// ft_clean_info
			return (0);
		}
		// unlink heredoc
	}
}

static int	ft_preprocess(t_info *info,char *input)
{
	info->parse = ft_parse(input, info->env);
	if (ft_parse_syntax(info->parse) == 0)
	{
		write(2, PARSE_ERROR, ft_strlen(PARSE_ERROR));
		ft_clean_info(&g_info, input);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_term	origin;
	t_term	new;

	ft_save_init(&origin);
	ft_set_term(&new);
	ft_set_signal();
	g_info = ft_init_info(argc, argv, env);
	while (1)
	{
		input = readline(PROM);
		errno = 0;
		if (!input)
			break ;
		if (*input != '\0')
			add_history(input);
		if (*input != '\0' && !is_whitespace(input))
		{
			if (ft_preprocess(&g_info, input) == 0)
				continue ;
		}
		ft_clean_info(&g_info, input);
		free(input);
	}
	ft_reset_term(&origin);
}
