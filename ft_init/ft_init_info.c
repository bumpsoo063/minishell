#include "ft_init.h"
#include <unistd.h>

t_info	ft_init_info(int argc, char **argv, char **env)
{
	t_info	ret;
	t_fd	fd;

	argc = 0;
	argv = 0;
	ret.env = ft_init_env(env);
	fd = (t_fd){
		.in = dup(STDIN_FILENO),
		.out = dup(STDOUT_FILENO),
	};
	if (fd.out < 0 || fd.in < 0)
		ft_check_error();
	ret.fd = fd;
	return (ret);
}
