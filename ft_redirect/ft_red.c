#include "../libft/libft.h"
#include "../const.h"

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

static int	ft_red2(char **parse, int *i)
{
	if (ft_strncmp(parse[*i], INPUT, 2) == 0)
	{
		// heredoc ㅊㅗ기화
		if (ft_lt(parse[++(*i)]) == 0)
			return (0);
	}
	else if (ft_strncmp(parse[*i], OUTPUT, 2) == 0)
	{
		if (ft_gt(parse[++(*i)]) == 0)
			return (0);
	}
	else if (ft_strncmp(parse[*i], D_OUTPUT, 3) == 0)
	{
		if (ft_gt(parse[++(*i)]) == 0)
			return (0);
	}
	else if (ft_strncmp(parse[*i], D_INPUT, 3) == 0)
	{
		// heredoc ㅊㅗ기화
		if (ft_dlt(parse[++(*i)]) == 0)
			return (0);
	}
	return (1);
}

int	ft_red(char **parse)
{
	int	i;
	int	temp;

	i = 0;
	while (parse[i] != 0 && ft_strncmp(parse[i], PIPE, 2) != 0)
	{
		temp = i;
		if (ft_red2(parse, &i) == 0)
			return (0);
		if (i != temp)
		{
			ft_shift(parse, temp);
			ft_shift(parse, temp);
			i = temp;
		}
		else
			i++;
	}
	return (1);
}

