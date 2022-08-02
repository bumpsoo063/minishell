#include <stdio.h>
#include <stdlib.h>

// int main(int argc, char **argv, char **env)
// extern char **environ
void	ft_env(char **env)
{
	int		i;

	i = 0;
	while (env[i] != 0)
	{
		printf("%s\n", env[i]);
		++i;
	}
}
