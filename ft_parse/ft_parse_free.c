#include <stdlib.h>

void	ft_parse_free(char **parse)
{
	int	i;

	i = 0;
	while (parse[i] != 0)
	{
		free(parse[i]);
		i++;
	}
	free(parse);
}
