#include "t_queue.h"
#include <stdlib.h>
#include "../minishell.h"

t_q_com	*t_q_com_new(char **words, t_q_re *re)
{
	t_q_com	*com;

	com = malloc(sizeof(t_q_com));
	ft_check_error();
	*com = (t_q_com){
		.words = words,
		.re = re,
		.next = 0
	};
	return (com);
}

void	t_q_com_push(t_q_com **head, t_q_com *q)
{
	t_q_com	*temp;

	if (*head == 0)
		*head = q;
	else
	{
		temp = *head;
		while (temp->next != 0)
			temp = temp->next;
		temp->next = q;
	}
}
