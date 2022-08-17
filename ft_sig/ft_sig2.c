#include "ft_sig.h"


int	is_whitespace(char *line)
{
	while (*line)
	{
		if (*line != 32 && !(*line >= 0 & *line <= 13))
			return(0);
		line++;
	}
	return (1);
}
