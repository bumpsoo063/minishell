#include "minishell.h"
#include <readline/readline.h>
#include <stdlib.h>
#include <errno.h>
#include "libft/libft.h"
#include "ft_parse/ft_parse.h"
#include "builtin/builtin.h"
#include <stdio.h>

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

static int	ft_red2(char **parse, int *i)
{
	if (ft_strncmp(parse[*i], INPUT, 2) == 0)
	{
		// heredoc ㅊㅗ기화
		if (ft_lt(parse[++(*i)]) == 0)
			return (0);
	}
	else if (ft_strncmp(parse[*i], OUTPUT, 2) == 0)
	{
		if (ft_gt(parse[++(*i)]) == 0)
			return (0);
	}
	else if (ft_strncmp(parse[*i], D_OUTPUT, 3) == 0)
	{
		if (ft_gt(parse[++(*i)]) == 0)
			return (0);
	}
	else if (ft_strncmp(parse[*i], D_INPUT, 3) == 0)
	{
		// heredoc ㅊㅗ기화
		if (ft_dlt(parse[++(*i)]) == 0)
			return (0);
	}
	return (1);
}

static int	ft_red(char **parse)
{
	int	i;
	int	temp;

	i = 0;
	while (parse[i] != 0 && ft_strncmp(parse[i], PIPE, 2) != 0)
	{
		temp = i;
		if (ft_red2(parse, &i) == 0)
			return (0);
		if (i != temp)
		{
			ft_shift(parse, temp);
			ft_shift(parse, temp);
			i = temp;
		}
		else
			i++;
	}
	return (1);
}

static int	ft_process(char **parse)
{
	while (*parse != 0)
	{
		if (ft_red(parse) == 0)
			return (0);
		if (ft_command(parse) == 0)
			return (0);
		// unlink heredoc
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	char	*input;

	g_info = ft_init_info(argc, argv, env);
	while (1)
	{
		input = readline(PROM);
		errno = 0;
		if (input == 0)
			break ;
		add_history(input);
		g_info.parse = ft_parse(input, g_info.env);
		if (ft_parse_syntax(g_info.parse) == 0)
		{
			write(2, PARSE_ERROR, ft_strlen(PARSE_ERROR));
			ft_clean_info(&g_info, input);
			continue ;
		}
		if (ft_process(g_info.parse) == 0)
		{
			write(2, strerror(errno), ft_strlen(strerror(errno)));
			ft_clean_info(&g_info, input);
			continue ;
		}
		ft_clean_info(&g_info, input);
	}
}
