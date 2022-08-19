/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_info.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:06:15 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/19 15:12:40 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_parse/ft_parse.h"
#include "builtin/builtin.h"

static char	**ft_init_env(char **env)
{
	char	**ret;
	int		i;

	i = 0;
	while (env[i] != 0)
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	ft_check_error();
	i = 0;
	while (env[i] != 0)
	{
		ret[i] = ft_strdup(env[i]);
		ft_check_error();
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static void	ft_shlvl(t_info *info)
{
	char	**tmp;
	int		i;
	char	*toa;

	tmp = ft_calloc(sizeof(char *), 2);
	toa = ft_strdup("SHLVL");
	tmp[0] = ft_search_env(toa, info->env);
	free(toa);
	i = ft_atoi(tmp[0]) + 1;
	free(tmp[0]);
	toa = ft_itoa(i);
	tmp[0] = ft_strjoin("SHLVL=", toa);
	free(toa);
	ft_export(tmp, info);
	free(tmp[0]);
	free(tmp);
}

t_info	ft_init_info(int argc, char **argv, char **env)
{
	t_info	ret;

	if (argc != 1)
	{
		write(2, "minishell: argument error\n", 27);
		exit(1);
	}
	argv = 0;
	ret.env = ft_init_env(env);
	ret.in = dup(STDIN_FILENO);
	ret.out = dup(STDOUT_FILENO);
	ret.exit = 0;
	if (ret.in < 0 || ret.out < 0)
		ft_check_error();
	ft_shlvl(&ret);
	return (ret);
}

void	ft_clean_fd(t_info *info)
{
	int	temp;

	temp = 0;
	if (isatty(STDOUT_FILENO) != 1)
	{
		close(STDOUT_FILENO);
		temp = dup2(info->out, STDOUT_FILENO);
	}
	if (isatty(STDIN_FILENO) != 1)
	{
		close(STDIN_FILENO);
		temp = dup2(info->in, STDIN_FILENO);
	}
}

void	ft_clean_info(t_info *info, char *input)
{
	ft_parse_free(info->parse);
	ft_clean_fd(info);
	if (input)
		free(input);
}
