#include "libft/libft.h"
#include "builtin/builtin.h"
#include "const.h"
#include "minishell.h"


static int	ft_command2(char **parse, int i)
{
	if (ft_strncmp(parse[i], ECHO, ft_strlen(ECHO) + 1) == 0)
	{
		if (parse[i + 1] != 0 && ft_strncmp(parse[i + 1], "-n", 3) == 0)
			return ft_echo();
		else
			return ft_echo();
	}
	else if (ft_strncmp(parse[i], CD, ft_strlen(CD) + 1) == 0)
		return ft_cd();
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
	return (1);
}

int	ft_command(char **parse)
{
	int	i;
	int	ii;
	char	**cmd;

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
	return ft_command2(cmd);
}
