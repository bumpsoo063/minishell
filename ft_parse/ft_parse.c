/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:25:12 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/04 15:58:39 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_parse.h"
#include "../t_queue/t_queue.h"
#include "../libft/libft.h"
#include "ft_parse.h"

static t_queue	*ft_queue_quote(char **str, char ch, char **env)
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
		return (t_queue_new(ft_substitute(temp, env)));
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

static t_queue	*ft_queue_word(char **str, char **env)
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
	return (t_queue_new(ft_substitute(temp, env)));
}

char	**ft_parse(char *str, char **env)
{
	t_queue	*q;

	q = 0;
	while (*str != 0)
	{
		if (*str == SPACE)
			str++;
		else if (*str == D_QUOTE)
			t_queue_push(&q, ft_queue_quote(&str, D_QUOTE, env));
		else if (*str == QUOTE)
			t_queue_push(&q, ft_queue_quote(&str, QUOTE, env));
		else if (*str == INPUT)
			t_queue_push(&q, ft_queue_pipe(&str, INPUT));
		else if (*str == OUTPUT)
			t_queue_push(&q, ft_queue_pipe(&str, OUTPUT));
		else if (*str == PIPE)
			t_queue_push(&q, ft_queue_pipe(&str, PIPE));
		else
			t_queue_push(&q, ft_queue_word(&str, env));
	}
	return (t_queue_to_str(q));
}
