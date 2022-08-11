/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_q_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:29:35 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/09 15:41:15 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_queue.h"
#include "../minishell.h"

t_q_str	*t_q_str_new(char *str)
{
	t_q_str	*q;

	q = malloc(sizeof(t_q_str));
	ft_check_error();
	q->str = str;
	q->next = 0;
	return (q);
}

void	t_q_str_push(t_q_str **head, t_q_str *q)
{
	t_q_str	*temp;

	if (*head == 0)
		*head = q;
	else
	{
		temp = *head;
		while (temp != 0 && temp->next != 0)
			temp = temp->next;
		temp->next = q;
	}
}

char	*t_q_str_pop(t_q_str **head)
{
	t_q_str	*temp;
	char	*ret;

	temp = *head;
	ret = temp->str;
	*head = (*head)->next;
	free(temp);
	return (ret);
}

int	t_q_str_size(t_q_str *q)
{
	int	ret;

	ret = 0;
	while (q != 0)
	{
		q = q->next;
		ret++;
	}
	return (ret);
}

char	**t_q_str_to_str(t_q_str *q)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char *) * (t_q_str_size(q) + 1));
	ft_check_error();
	while (q != 0)
	{
		ret[i] = t_q_str_pop(&q);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
