/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:23:40 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/18 21:33:36 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sig.h"
#include <sys/signal.h>
#include <unistd.h>

void	ft_set_term(t_info *info)
{
	t_term	new;

	tcgetattr(info->in, &new);
	new.c_lflag &= ~(ECHOCTL);
	tcsetattr(info->in, TCSANOW, &new);
}

void	ft_child_term(t_info *info)
{
	t_term	new;

	tcgetattr(info->in, &new);
	new.c_lflag |= (ECHOCTL);
	tcsetattr(info->in, TCSANOW, &new);
}

void	ft_sigint(int signal)
{
	signal = 0;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	ft_set_child(int offset)
{
	if (offset == 0)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (offset == 1)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (offset == 2)
		ft_set_signal();
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	ft_set_signal(void)
{
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, SIG_IGN);
}
