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
#endif
