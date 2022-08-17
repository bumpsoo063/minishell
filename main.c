#include "minishell.h"
#include "libft/libft.h"
#include "ft_parse/ft_parse.h"
#include "builtin/builtin.h"
#include "ft_sig/ft_sig.h"
#include <errno.h>
#include <readline/readline.h>
#include "ft_redirect/ft_redirect.h"

#include <string.h>

static int	ft_process(t_info *info)
{
	char	**parse;

	parse = info->parse;
	while (*parse != 0)
	{
		if (ft_red(parse))
		{
			return (write(2, strerror(errno), ft_strlen(strerror(errno))));
		}
		if (ft_command(parse, info))
		{
			return (write(2, strerror(errno), ft_strlen(strerror(errno))));
		}
		ft_rm_heredoc();
	}
	return (0);
}

static int	ft_preprocess(t_info *info,char *input)
{
	info->parse = ft_parse(input, info->env, info);
	if (ft_parse_syntax(info->parse))
	{
		write(2, PARSE_ERROR, ft_strlen(PARSE_ERROR));
		return (1);
	}
	return (ft_process(info));
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
			ft_preprocess(&g_info, input);
		}
		ft_clean_info(&g_info, input);
		free(input);
	}
	ft_reset_term(&origin);
}
