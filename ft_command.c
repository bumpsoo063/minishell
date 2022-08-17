#include "libft/libft.h"
#include "builtin/builtin.h"
#include "const.h"
#include "minishell.h"

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

static int	ft_command2(char **parse)
{
	if (ft_strncmp(*parse, ECHO, ft_strlen(ECHO) + 1) == 0)
	{
		if (*parse != 0 && ft_strncmp(*parse, "-n", 3) == 0)
			return ft_echo();
		else
			return ft_echo();
	}
	else if (ft_strncmp(*parse, CD, ft_strlen(CD) + 1) == 0)
		return ft_cd();
	else if (ft_strncmp(*parse, PWD, ft_strlen(PWD) + 1) == 0)
		return (ft_pwd());
	else if (ft_strncmp(*parse, EXPORT, ft_strlen(EXPORT) + 1) == 0)
		return (ft_export());
	else if (ft_strncmp(*parse, UNSET, ft_strlen(UNSET) + 1) == 0)
		return (ft_unset());
	else if (ft_strncmp(*parse, ENV, ft_strlen(ENV) + 1) == 0)
		return (ft_env());
	else if (ft_strncmp(*parse, EXIT, ft_strlen(EXIT) + 1) == 0)
		return (ft_exit());
	else
		return (ft_execve());
}

int	ft_command(char **parse)
{
	int	i;
	int	ii;
	char	**cmd;

	i = 0;
	while (parse[i] != 0 && ft_strncmp(parse[i], PIPE, 2) == 0)
		i++;
	cmd = malloc(sizeof(char *) * (i + 1));
	ft_check_error();
	cmd[i] = 0;
	ii = 0;
	while (ii < i)
	{
		cmd[ii] = parse[ii];
		++ii;
	}
	while (i-- >= 0)
		ft_shift(parse, 0);
	if (parse[i] != 0)
		ft_pipe(cmd);
	return ft_command2(cmd);
}
