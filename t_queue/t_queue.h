/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_queue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:29:33 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/04 17:31:17 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_QUEUE_H
# define T_QUEUE_H


typedef struct s_queue
{
	char	*str;
	struct s_queue	*next;
}	t_queue;

t_queue	*t_queue_new(char *str);
void	t_queue_push(t_queue **head, t_queue *q);
char	*t_queue_pop(t_queue **head);
int	t_queue_size(t_queue *q);
char	**t_queue_to_str(t_queue *q);
#endif
