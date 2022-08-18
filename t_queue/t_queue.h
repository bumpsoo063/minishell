/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_queue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:29:33 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/18 21:22:17 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_QUEUE_H
# define T_QUEUE_H
# include "../const.h"

typedef struct s_q_str
{
	char			*str;
	struct s_q_str	*next;
}	t_q_str;

t_q_str	*t_q_str_new(char *str);
void	t_q_str_push(t_q_str **head, t_q_str *q);
char	*t_q_str_pop(t_q_str **head);
int		t_q_str_size(t_q_str *q);
char	**t_q_str_to_str(t_q_str *q);

#endif
