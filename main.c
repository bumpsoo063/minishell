#include "minishell.h"
#include <readline/readline.h>
#include <stdlib.h>
#include <errno.h>
#include "libft/libft.h"
#include "ft_parse/ft_parse.h"
#include "ft_init/ft_init.h"
#include "builtin/builtin.h"
#include <stdio.h>

static void	ft_clean_fd(t_info *info)
{
	int	ret;

	ret = dup2(STDOUT_FILENO, info->fd.out);
	if (ret < 0)
		ft_check_error();
	ret = dup2(STDIN_FILENO, info->fd.in);
	if (ret < 0)
		ft_check_error();
}

static int	ft_command(char **parse, int i)
{
	int	ret;

	ret = 1;
	if (ft_strncmp(parse[i], ECHO, ft_strlen(ECHO) + 1) == 0)
	{
		if (parse[i + 1] != 0 && ft_strncmp(parse[i + 1], "-n", 3) == 0)
			ret = ft_echo();
		else
			ret = ft_echo();
	}
	else if (ft_strncmp(parse[i], CD, ft_strlen(CD) + 1) == 0)
		ret = ft_cd();
	else if (ft_strncmp(parse[i], PWD, ft_strlen(PWD) + 1) == 0)
		return (1);
	else if (ft_strncmp(parse[i], EXPORT, ft_strlen(EXPORT) + 1) == 0)
		return (1);
	else if (ft_strncmp(parse[i], UNSET, ft_strlen(UNSET) + 1) == 0)
		return (1);
	else if (ft_strncmp(parse[i], ENV, ft_strlen(ENV) + 1) == 0)
		return (1);
	else if (ft_strncmp(parse[i], EXIT, ft_strlen(EXIT) + 1) == 0)
		return (1);
	return (ret);
}

static int	ft_red(char **parse)
{
	int	i;

	i = 0;
	while (parse[i] != 0 && ft_strncmp(parse[i], PIPE, 2) != 0)
	{
		if (ft_strncmp(parse[i], INPUT, 2) == 0)
			ft_lt(parse[++i]);
		else if (ft_strncmp(parse[i], OUTPUT, 2) == 0)
			ft_gt(parse[++i]);
		else if (ft_strncmp(parse[i], D_OUTPUT, 3) == 0)
			ft_gt(parse[++i], 1);
		else if (ft_strncmp(parse[i], D_INPUT, 3) == 0)
			ft_dlt(parse[++i]);
		else
			++i;
	}
	return (i);
}

static int	ft_process(char **parse)
{
	int	i;

	i = 0;
	while (parse[i] != 0)
	{
		
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
		for (int i = 0; g_info.parse[i] != 0; i++)
			printf("%s\n", g_info.parse[i]);
		if (ft_parse_syntax(g_info.parse) == 0)
		{
			write(2, PARSE_ERROR, ft_strlen(PARSE_ERROR));
			continue ;
		}
		// 파이프 전의 모든 리다이렉션 처리
		ft_red(g_info.parse);
		// 명령어 실행(파이프 있으면 파이프로?)
		ft_clean_fd(&g_info);
		ft_parse_free(g_info.parse);
		free(input);
	}
}
