#include "cd.h"

void	cd(char *str)
{
	chdir(str);
}

int	main(int argc, char **argv)
{
	char buf[1024];

	cd(argv[1]);
	printf("%s\n", getcwd(buf, 100));
}
