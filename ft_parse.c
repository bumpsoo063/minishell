#include "minishell.h"
#include "t_queue/t_queue.h"
#include "libft/libft.h"

static t_queue	*ft_queue(char **str, char ch)
{
	int	i;
	char	*temp;
	char	*ret;

	temp = *str;
	i = 0;
	while (**str != 0 && **str != ch)
	{
		if (ch != D_QUOTE && ch!= QUOTE)
			if (**str == SPACE)
				break;
		(*str)++;
		i++;
	}
	ret = ft_substr(temp, 0, i);
	ft_check_error();
	return (t_queue_new(ret));
}

static char	*ft_substitute(char *str, t_info *info)
{
	char	*temp;

	temp = str + 1;
}

static t_queue	*ft_queue_dollar(char **str, t_info *info)
{
	int	i;
	char	*temp;

	i = 0;
	temp = *++str;
	if (*(*str + 1) == '{')
	{
		while (**str != 0 && **str != '}')
		{
			(*str)++;
			i++;
		}
	}
	else
	{
		while (**str != 0 && **str != SPACE)
		{
			(*str)++;
			i++;
		}
	}
	temp = ft_substr(temp, 0, i);
	ft_check_error();
	return (t_queue_new(ft_substitute(temp, info)));
}

// if $ -> search through info->env, info->old_env
char	**ft_parse(char *str, t_info *info)
{
	char	**ret;
	t_queue	*q;

	q = 0;
	while (*str != 0)
	{
		if (*str == SPACE)
			str++;
		else if (*str == D_QUOTE)
			t_queue_push(&q, ft_queue(&str, D_QUOTE));
		else if (*str == QUOTE)
			t_queue_push(&q, ft_queue(&str, QUOTE));
		else if (*str == INPUT)
			t_queue_push(&q, ft_queue(&str, INPUT));
		else if (*str == OUTPUT)
			t_queue_push(&q, ft_queue(&str, OUTPUT));
		else if (*str == PIPE)
			t_queue_push(&q, ft_queue(&str, PIPE));
		else if (*str == DOLLAR)
			t_queue_push(&q, ft_queue_dollar(&str, info));
	}
	return (ret);
}
