/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:23:40 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/18 20:36:16 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sig.h"
#include <sys/signal.h>
#include <unistd.h>

void	ft_save_init(t_term *org_term)
{
	tcgetattr(STDIN_FILENO, org_term);
}

void	ft_set_term()
{
	t_term	new;

	tcgetattr(STDIN_FILENO, &new);
	new.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
}

void	ft_child_term(t_info *info)
{
	t_term	new;

	tcgetattr(info->in, &new);
	new.c_lflag |= (ECHOCTL);
	tcsetattr(info->in, TCSANOW, &new);
}

void	ft_reset_term(t_term *org_term)
{
	tcsetattr(STDIN_FILENO, TCSANOW, org_term);
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

void	ft_set_signal()
{
	signal(SIGINT, ft_sigint);
	signal(SIGQUIT, SIG_IGN);
}
/*
int	main(void)
{
	char		*line;
	t_term	org_term;
	t_term	new_term;

	ft_save_init(&org_term);
	ft_set_term(&new_term);
	ft_set_signal();
	while (1)
	{
		line = readline("minishell $ ");
		if (!line)
			exit(-1);
		if (*line != '\0')
			add_history(line);
		if (*line != '\0' && !is_whitespace(line))
		{
			printf("%s\n", line);
		}
		free(line);
	}
	ft_reset_term(&org_term);
	return (0);
}*/
