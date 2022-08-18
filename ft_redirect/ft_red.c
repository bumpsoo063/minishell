/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:21:11 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/18 21:23:02 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../const.h"
#include "ft_redirect.h"

int	ft_rm_heredoc(void)
{
	return (unlink(FILE_NAME));
}

static int	ft_red2(char **parse, int *i)
{
	if (ft_strncmp(parse[*i], INPUT, 2) == 0)
	{
		ft_rm_heredoc();
		if (ft_lt(parse[++(*i)]))
			return (1);
	}
	else if (ft_strncmp(parse[*i], OUTPUT, 2) == 0)
	{
		if (ft_gt(parse[++(*i)], 0))
			return (1);
	}
	else if (ft_strncmp(parse[*i], D_OUTPUT, 3) == 0)
	{
		if (ft_gt(parse[++(*i)], 1))
			return (1);
	}
	else if (ft_strncmp(parse[*i], D_INPUT, 3) == 0)
	{
		ft_rm_heredoc();
		if (ft_dlt(parse[++(*i)]))
			return (1);
	}
	return (0);
}

int	ft_red(char **parse)
{
	int	i;
	int	temp;

	i = 0;
	while (parse[i] != 0 && ft_strncmp(parse[i], PIPE, 2) != 0)
	{
		temp = i;
		if (ft_red2(parse, &i))
			return (1);
		if (i != temp)
		{
			ft_shift(parse, temp);
			ft_shift(parse, temp);
			i = temp;
		}
		else
			i++;
	}
	return (0);
}
