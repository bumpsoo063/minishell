#include "minishell.h"
#include "libft/libft.h"
#include "ft_parse/ft_parse.h"
#include "builtin/builtin.h"
#include "ft_sig/ft_sig.h"
#include <errno.h>
#include <readline/readline.h>
#include "ft_redirect/ft_redirect.h"

#include <string.h>

static void	ft_shift(char **parse, int p)
{
	int	i;

	i = 0;
	while (parse[i] != 0)
	{
		if (i >= p)
			parse[i] = parse[i + 1];
		if (parse[i] == 0)
			break ;
		++i;
	}
	free(parse[i + 1]);
	parse[i + 1] = 0;
}

static int	ft_process(t_info *info)
{
	char	**parse;

	parse = info->parse;
	while (*parse != 0)
	{
		if (ft_red(parse))
		{
			return (1);
		}
		if (*parse != 0)
		{
			if (ft_strncmp(*parse, PIPE, 2) == 0)
			{
				ft_shift(parse, 0);
			}
			else if (ft_command(parse, info))
				return (1);
		}
	}
	return (0);
}

static int	ft_preprocess(t_info *info,char *input)
{
	int	i;

	i =0;
	info->parse = ft_parse(input, info->env, info);
	while (info->parse[i] != 0)
	{
		if (info->parse[i][0] == 0)
			ft_shift(info->parse, i);
		else
			i++;
	}
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
	t_info	info;

	ft_save_init(&(info.org));
	ft_set_term();
	ft_set_signal();
	info = ft_init_info(argc, argv, env);
	while (1)
	{
		input = readline(PROM);
		errno = 0;
		if (!input)
			break ;
		if (*input != '\0')
		{	
			add_history(input);
			if (*input != '\0' && !is_whitespace(input))
			{
				ft_preprocess(&info, input);
				ft_clean_info(&info, input);
			}
			else
				free(input);
		}
	}
	ft_reset_term(&(info.org));
}
