#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// strlen -> ft_strlen
void	ft_check_error()
{
	if (errno > 0)
	{
		write(2, strerror(errno), strlen(strerror(errno)));
		exit(1);
	}
}
