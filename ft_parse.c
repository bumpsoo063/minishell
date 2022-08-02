#include "minishell.h"

static int	*ft_find(char *str, char ch)
{
	int	i;
	char	*head;

	head = str;
	i = 0;
	while (*str != 0 && *str != ch)
	{
		str++;
		i++;
	}
	
}

static int	ft_count(char *str)
{

}

// if $ -> search through info->env, info->old_env
char**	ft_parse(char *str, t_info *info)
{
	char	*head;
	char	**ret;
	int	count;

	head = str;
	count = 0;
	while (*str != 0)
	{
		if (*str == SPACE)
			;
		else if (*str == D_QUOTE)
			ft_find(str, D_QUOTE);
		else if (*str == QUOTE)
			;
		else if (*str == INPUT)
			;
		else if (*str == OUTPUT)
			;
		else if (*str == PIPE)
			;
		str++;
	}
	return (ret);
}
