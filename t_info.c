#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "ft_parse/ft_parse.h"

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

t_info	ft_init_info(int argc, char **argv, char **env)
{
	t_info	ret;

	argc = 0;
	argv = 0;
	ret.env = ft_init_env(env);
	ret.in = dup(STDIN_FILENO);
	ret.out = dup(STDOUT_FILENO);
	ret.exit = 0;
	if (ret.in < 0 || ret.out < 0)
		ft_check_error();
	return (ret);
}

void	ft_clean_fd(t_info *info)
{
	int	temp;

	temp = 0;
	if (isatty(STDOUT_FILENO) != 1)
		temp = dup2(info->out, STDOUT_FILENO);
	if (temp < 0)
		ft_check_error();
	if (isatty(STDIN_FILENO) != 1)
		temp = dup2(info->in, STDIN_FILENO);
	if (temp < 0)
		ft_check_error();
}

void	ft_clean_info(t_info *info, char *input)
{
	ft_parse_free(info->parse);
	free(input);
}
