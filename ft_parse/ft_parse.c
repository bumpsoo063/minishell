/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:25:12 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/18 21:13:43 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_parse.h"
#include "../t_queue/t_queue.h"
#include "../libft/libft.h"
#include "ft_parse.h"

static t_q_str	*ft_q_str_quote(char **str, char ch, char **env, t_info *info)
{
	int		i;
	char	*temp;

	temp = ++(*str);
	i = 0;
	while (**str != 0 && **str != ch)
	{
		(*str)++;
		i++;
	}
	if (**str == ch)
		(*str)++;
	temp = ft_substr(temp, 0, i);
	ft_check_error();
	if (ch == D_Quote)
		return (t_q_str_new(ft_substitute(temp, env, info)));
	return (t_q_str_new(temp));
}

static t_q_str	*ft_q_str_put(char **str, char ch)
{
	int		i;
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
	return (t_q_str_new(temp));
}

static t_q_str	*ft_q_str_pipe(char **str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup("|");
	ft_check_error();
	(*str)++;
	return (t_q_str_new(temp));
}

static t_q_str	*ft_q_str_word(char **str, char **env, t_info *info)
{
	int		i;
	char	*temp;

	temp = *str;
	i = 0;
	while (**str != 0 && **str != Space && \
			**str != Input && **str != Output && **str != Pipe)
	{
		(*str)++;
		i++;
	}
	temp = ft_substr(temp, 0, i);
	ft_check_error();
	return (t_q_str_new(ft_substitute(temp, env, info)));
}

char	**ft_parse(char *str, char **env, t_info *info)
{
	t_q_str	*q;

	q = 0;
	while (*str != 0)
	{
		if (*str == Space)
			str++;
		else if (*str == D_Quote)
			t_q_str_push(&q, ft_q_str_quote(&str, D_Quote, env, info));
		else if (*str == Quote)
			t_q_str_push(&q, ft_q_str_quote(&str, Quote, env, info));
		else if (*str == Input)
			t_q_str_push(&q, ft_q_str_put(&str, Input));
		else if (*str == Output)
			t_q_str_push(&q, ft_q_str_put(&str, Output));
		else if (*str == Pipe)
			t_q_str_push(&q, ft_q_str_pipe(&str));
		else
			t_q_str_push(&q, ft_q_str_word(&str, env, info));
	}
	return (t_q_str_to_str(q));
}
