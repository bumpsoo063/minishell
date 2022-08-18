/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:16:13 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/18 17:23:24 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"


static	int	is_space(char str)
{
	if ((9 <= str && str <= 13) || str == 32)
		return (1);
	else
		return (0);
}

static int	ft_atol(const char *str, int *f)
{
	unsigned long			num;
	int						flag;
	int						cnt;

	num = 0;
	cnt = 0;
	flag = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9' && cnt++ <= 19)
		num = num * 10 + *str++ - '0';
	if (((num > LONG_MAX) || (cnt > 19)) && (flag == 1))
		*f = -1;
	else if (((num > LONG_MAX) || (cnt > 19)) && (flag == -1))
		*f = -1;
	return (flag * num);
}

static void	ft_num_print(char *str)
{
	write(2, "minishell: exit: ", 17); 
	write(2, str, ft_strlen(str)); 
	write(2, ": numeric argument required\n", 26);
}

static void	ft_check(char *str, int *f)
{
	while (*str != 0)
		if (!ft_isdigit(*str++))
			*f = -1;
}

int	ft_exit(char **str)
{
	int	i;
	int	f;
	int	ret;

	i = 0;
	f = 0;
	ret = 0;
	write(1, "exit\n", 5);
	while (str && str[i] != 0)
	{
		if (i >= 1)
		{
			(write(2, "minishell: exit: too many arguments\n", 37));
			return (1);
		}
		ft_check(str[i], &f);
		ret = ft_atol(str[i], &f);
		if (f)
		{
			ft_num_print(str[i]);
			ret = 255;
			break ;
		}
		i++;
	}
	exit(ret);
}
