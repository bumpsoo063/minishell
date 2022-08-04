/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substitute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:25:24 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/04 14:04:28 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_parse.h"
#include "../minishell.h"


static char	*ft_word(char *str, char **key)
{
	char	*head;
	int	i;

	i = 0;
	++str;
	if (*str == BRACE_O)
		str++;
	head = str;
	while (*str != 0 && ft_isalpha(*str))
	{
		str++;
		i++;
	}
	*key = ft_substr(head, 0, i);
	ft_check_error();
	if (*str == BRACE_C)
		str++;
	return (str);
}

static char	*ft_union(char *left, char *key, char *right, char **env)
{
	char	*value;
	char	*ret;
	char	*temp;

	value = ft_search_env(key, env);
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

char	*ft_substitue(char *str, char **env)
{
	char	*left;
	char	*key;
	char	*right;
	char	*temp;

	temp = ft_strchr(str, DOLLAR);
	while (temp)
	{
		left = ft_substr(str, 0, temp - str - 1);
		ft_check_error();
		temp = ft_word(temp, &key);
		right = ft_strdup(temp);
		ft_check_error();
		temp = ft_union(left, key, right, env);
		free(str);
		str = temp;
		temp = ft_strchr(str, DOLLAR);
	}
	return (str);
}
