#include "t_queue.h"
#include <stdlib.h>
#include "../minishell.h"

t_q_re	*t_q_re_new(char *str, int index)
{
	t_q_re	*ret;

	ret = malloc(sizeof(t_q_re));
	ft_check_error();
	*ret = (t_q_re) {
		.index = index,
		.fd = 0,
		.buf = 0,
		.re = str,
		.next = 0
	};
	return (ret);
}

void	t_q_re_push(t_q_re **head, t_q_re *q)
{
	t_q_re	*temp;
	
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

// buf should be freed
t_q_re	t_q_re_pop(t_q_re **head)
{
	t_q_re	*temp;
	t_q_re	ret;

	temp = *head;
	ret = *temp;
	*head = (*head)->next;
	free(temp);
	return (ret);
}

void	t_q_re_free(t_q_re **head)
{
	t_q_re	*temp;
	t_q_re	*dup;

	temp = *head;
	while (temp != 0)
	{
		dup = temp;
		free(dup->buf);
		temp = temp->next;
		free(dup);
	}
	*head = 0;
}
