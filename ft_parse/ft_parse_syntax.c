#include "../const.h"

static int	ft_check_pipe(char **parse)
{
	int	i;

	i = 0;
	while (parse[i] != 0)
	{
		if (parse[i][0] == Pipe)
		{
			if (i == 0)
				return (1);
			else
				if (parse[i - 1][0] == Pipe)
					return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_check_re(char **parse, char re)
{
	int	i;

	i = 1;
	while (parse[i] != 0)
	{
		if (parse[i][0] == re)
			if (parse[i - 1][0] == re)
				return (1);
		i++;
	}
	if (parse[i - 1][0] == re)
		return (1);
	return (0);
}

int	ft_parse_syntax(char **parse)
{
	if (ft_check_pipe(parse))
		return (1);
	else if (ft_check_re(parse, Output))
		return (1);
	else if (ft_check_re(parse, Input))
		return (1);
	else
		return (0);
}
