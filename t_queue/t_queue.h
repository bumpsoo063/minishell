/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_queue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:29:33 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/11 13:49:00 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_QUEUE_H
# define T_QUEUE_H
# include "../const.h"

typedef struct s_q_str
{
	char	*str;
	struct s_q_str	*next;
}	t_q_str;

t_q_str	*t_q_str_new(char *str);
void	t_q_str_push(t_q_str **head, t_q_str *q);
char	*t_q_str_pop(t_q_str **head);
int	t_q_str_size(t_q_str *q);
char	**t_q_str_to_str(t_q_str *q);

typedef struct s_q_re
{
	int	fd;
	int	index;
	char	*buf;
	const char	*re;
	struct s_q_re	*next;
}	t_q_re;

t_q_re	*t_q_re_new(char *str, int index);
void	t_q_re_push(t_q_re **head, t_q_re *q);
t_q_re	t_q_re_pop(t_q_re **head);

/*typedef struct s_q_com
{
	char	**words;
	t_q_re	*re;
	struct s_q_com	*next;
}	t_q_com;

t_q_com	*t_q_com_new(char **words, t_q_re *re);
void	t_q_com_push(t_q_com **head, t_q_com *q);
char	*t_q_com_pop(t_q_com **head);
int	t_q_com_size(t_q_com *q);
char	**t_q_com_to_str(t_q_com *q);*/
#endif
