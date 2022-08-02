#include <string.h>
#include <stdlib.h>

// string.h -> libft.h>
// strncmp -> ft_strncmp
void	ft_unset(char *str, char **env)
{
	const size_t	len = strlen(str);
	char	**ep;
	char	**temp;

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
