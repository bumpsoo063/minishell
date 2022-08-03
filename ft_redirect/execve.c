#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main()
{
	char	**str;
	int		i;
	int		fd;

	i = 0;
	fd = open("log", O_WRONLY | O_CREAT);
	str = calloc(sizeof(char *), 2);
	str[0] = "/bin/ls";
	str[1] = 0;
	dup2(fd, STDOUT_FILENO);
	execve(str[0], str, NULL);
	return (0);
}
