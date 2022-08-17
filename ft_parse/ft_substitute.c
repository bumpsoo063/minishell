/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substitute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:25:24 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/17 20:25:19 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_parse.h"
#include "../minishell.h"
#include <stdbool.h>
#include <stdio.h>

static char	*ft_word(char *str, char **key)
{
	char	*head;
	int	i;
	bool	f;

	i = 0;
	if (*(++str) == Brace_O)
	{
		str++;
		f = true;
	}
	head = str;
	if (*str == '?')
	{
		str++;
		*key = ft_substr(head, 0, ++i);
		return (str);
	}
	while (*str != 0 && (ft_isalpha(*str) || *str == '_'))
	{
		str++;
		i++;
	}
	*key = ft_substr(head, 0, i);
	ft_check_error();
	if (*str == Brace_C && f == true)
		str++;
	return (str);
}

static char	*ft_union(char *left, char *key, char *right, t_info *info)
{
	char	*value;
	char	*ret;
	char	*temp;

	if (*key == '?')
		value = ft_itoa(info->exit);
	else
		value = ft_search_env(key, info->env);
	ret = ft_strjoin(left, value);
	temp = ret;
	ret = ft_strjoin(ret, right);
	free(temp);
	free(left);
	free(key);
	free(right);
	free(value);
	return (ret);
}

char	*ft_substitute(char *str, char **env, t_info *info)
{
	char	*left;
	char	*key;
	char	*right;
	char	*temp;

	env = 0;
	temp = ft_strchr(str, Dollar);
	while (temp != 0)
	{
		if (temp == str)
			left = ft_strdup("");
		else
			left = ft_substr(str, 0, temp - str);
		ft_check_error();
		temp = ft_word(temp, &key);
		if (*temp == 0)
			right = ft_strdup("");
		else
			right = ft_strdup(temp);
		ft_check_error();
		temp = ft_union(left, key, right, info);
		free(str);
		str = temp;
		temp = ft_strchr(str, Dollar);
	}
	return (str);
}
