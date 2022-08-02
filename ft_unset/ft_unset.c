#include <string.h>

static int	ft_unset_len(char *str)
{
	int	ret;

	ret = 0;
	while (*str != 0)
	{
		if (*str == '=')
			break;
		str++;
		ret++;
	}
	return (ret);
}

// int main(int argc, char **argv, char **env);
void	ft_unset(char *str, char **env)
{
	int	i;

	i = 0;
	while (env[i] != 0)
	{
		if (strncmp(env[i], str, ft_unset_len(str)))
		{
		}
	}
}
