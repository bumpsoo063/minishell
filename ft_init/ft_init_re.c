#include "../t_queue/t_queue.h"
#include "../libft/libft.h"
#include "../const.h"

t_q_re	*ft_init_re(char **parse)
{
	t_q_re	*ret;
	int	i;

	i = 0;
	ret = 0;
	while (parse[i] != 0)
	{
		if (ft_strncmp(parse[i], INPUT, 1)== 0)
			t_q_re_push(&ret, t_q_re_new(INPUT, i));
		else if (ft_strncmp(parse[i], D_INPUT, 2) == 0)
			t_q_re_push(&ret, t_q_re_new(D_INPUT, i));
		else if (ft_strncmp(parse[i], OUTPUT, 1) == 0)
			t_q_re_push(&ret, t_q_re_new(OUTPUT, i));
		else if (ft_strncmp(parse[i], D_OUTPUT, 2) == 0)
			t_q_re_push(&ret, t_q_re_new(D_OUTPUT, i));
		i++;
	}
	return (ret);
}
