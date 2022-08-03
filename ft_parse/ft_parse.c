#include "../minishell.h"
#include "../t_queue/t_queue.h"
#include "../libft/libft.h"

static t_queue	*ft_queue_quote(char **str, char ch, t_info *info)
{
	int	i;
	char	*temp;

	temp = ++(*str);
	i = 1;
	while (**str != 0 && **str != ch)
	{
		(*str)++;
		i++;
	}
	temp = ft_substr(temp, 0, i);
	ft_check_error();
	if (ch == D_QUOTE)
		return (t_queue_new(ft_substitute(temp, info)));
	return (t_queue_new(temp));
}

static t_queue	*ft_queue_pipe(char **str, char ch)
{
	int	i;
	char	*temp;

	temp = *str;
	i = 0;
	while (**str != 0 && **str == ch)
	{
		(*str)++;
		i++;
	}
	temp = ft_substr(temp, 0, i);
	ft_check_error();
	return (t_queue_new(temp));
}

static t_queue	*ft_queue_dollar(char **str, t_info *info)
{
	int	i;
	char	*temp;

	i = 0;
	temp = *(str);
	while (*str != 0)
	{
		if (**str == '}' || **str == SPACE)
			break ;
		(*str)++;
		i++;
	}
	temp = ft_substr(temp, 0, i);
	ft_check_error();
	return (t_queue_new(ft_substitute(temp, info)));
}

static t_queue	*ft_queue_word(char **str, t_info *info)
{
	int	i;
	char 	*temp;
	
	temp = *str;
	i = 0;
	while (**str != 0 && **str != SPACE)
	{
		(*str)++;
		i++;
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
			t_queue_push(&q, ft_queue_quote(&str, D_QUOTE, info));
		else if (*str == QUOTE)
			t_queue_push(&q, ft_queue_quote(&str, QUOTE, info));
		else if (*str == INPUT)
			t_queue_push(&q, ft_queue_pipe(&str, INPUT));
		else if (*str == OUTPUT)
			t_queue_push(&q, ft_queue_pipe(&str, OUTPUT));
		else if (*str == PIPE)
			t_queue_push(&q, ft_queue_pipe(&str, PIPE));
		else
			t_queue_push(&q, ft_queue_word(&str, info));
	}
	return (ret);
}
