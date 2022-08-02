#include <string.h>
#include <stdlib.h>

#include <stdio.h>
#include <unistd.h>

void	ft_check_error();
// string.h -> libft.h>
// strdup -> ft_strdup
// strncmp -> ft_strncmp
static void	ft_check_env(char *str, char **env)
{
	char const	*del = strchr(str, '=');
	const	int	len = del - str;
	char		**ep;
	char		**temp;

	ep = env;
	while (*ep != 0)
	{
		if (strncmp(*ep, str, len) == 0 && (*ep)[len] == '=')
		{
			temp = ep;
			while (*temp != 0)
			{
				*temp = *(temp + 1);
				temp++;
			}
		}
		else
			ep++;
	}
}

// need some code to check whether str contains '='
char	**ft_export(char *str, char **env)
{
	int	i;
	char	**ret;

	i = 0;
	ft_check_env(str, env);
	while (env[i] != 0)
		i++;
	ret = malloc(sizeof(char*) * (i + 2));
	ft_check_error();
	i = 0;
	while (env[i] != 0)
	{
		ret[i] = strdup(env[i]);
		ft_check_error();
		i++;
	}
	ret[i] = strdup(str);
	ret[i + 1] = 0;
	i = 0;
	while (env[i] != 0)
		free(env[i++]);
	free(env[i]);
	return (ret);
}
