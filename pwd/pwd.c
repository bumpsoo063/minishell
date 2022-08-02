#include "pwd.h"

void	pwd()
{
	char	buf[1024];
	
	getcwd(buf, 1024);
	printf("%s\n", buf);
}

int	main()
{
	pwd();
}
