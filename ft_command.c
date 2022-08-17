#include "libft/libft.h"
#include "builtin/builtin.h"
#include "const.h"
#include "minishell.h"
#include "ft_execve/ft_execve.h"
#include "ft_pipe/ft_pipe.h"
#include <sys/wait.h>

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

int	ft_exec(char **cmd, t_info *info)
{
	if (ft_strncmp(*cmd, ECHO, ft_strlen(ECHO) + 1) == 0)
	{
		if (*cmd != 0 && ft_strncmp(*(cmd + 1), "-n", 3) == 0)
			return ft_echo(&cmd[2], 0);
		else
			return ft_echo(&cmd[1], 1);
	}
	else if (ft_strncmp(*cmd, CD, ft_strlen(CD) + 1) == 0)
		return ft_cd(cmd[1], info);
	else if (ft_strncmp(*cmd, PWD, ft_strlen(PWD) + 1) == 0)
		return (ft_pwd());
	else if (ft_strncmp(*cmd, EXPORT, ft_strlen(EXPORT) + 1) == 0)
		return (ft_export(&cmd[1], info));
	else if (ft_strncmp(*cmd, UNSET, ft_strlen(UNSET) + 1) == 0)
		return (ft_unset(&cmd[1], info->env));
	else if (ft_strncmp(*cmd, ENV, ft_strlen(ENV) + 1) == 0)
		return (ft_env(info->env));
	else if (ft_strncmp(*cmd, EXIT, ft_strlen(EXIT) + 1) == 0)
		return (ft_exit(&cmd[1]));
	else
		return (ft_execve(cmd, info->env, info));
}

static int	ft_print(char **cmd, t_info *info, int result)
{
	info->exit = result;
	if (result == 127)
	{
		write(2, "minishell: ", 11);
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, ": ", 2);
		if (ft_strchr(cmd[0], '/'))
			write(2, NOFILE, ft_strlen(NOFILE));
		else
			write(2, NOCOMM, ft_strlen(NOCOMM));
		write(2, "\n", 1);
	}
	free(cmd);
	return (info->exit);
}

int	ft_command(char **parse, t_info *info)
{
	int	i;
	int	ii;
	char	**cmd;

	i = 0;
	while (parse[i] != 0 && ft_strncmp(parse[i], PIPE, 2) != 0)
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
	if (parse[i] != 0)
		ii = ft_pipe(cmd, info);
	else
		ii = ft_exec(cmd, info);
	while (i-- >= 0)
		ft_shift(parse, 0);
	return (ft_print(cmd, info, ii));
}
