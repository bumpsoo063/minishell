#include "../minishell.h"
#include "../libft/libft.h"

static char	*ft_value(char *key, char *env)
{
	char	*ret;

	if (ft_strncmp(key, env, ft_strlen(key) == 0))
	{
		ret = ft_strdup(ft_strchr(env, EQUAL) + 1);
		ft_check_error();
	}
	return (ret);
}

char	*ft_search_env(char *key, t_info *info)
{
	char	*value;
	int	i;

	i = 0;
	value = 0;
	while (info->env[i] != 0)
	{
		value = ft_value(key, info->env[i]);
		if (value)
			return (value);
		i++;
	}
	i = 0;
	while (info->old_env[i] != 0)
	{
		value = ft_value(key, info->old_env[i]);
		if (value)
			return (value);
		i++;
	}
	return (0);
}
