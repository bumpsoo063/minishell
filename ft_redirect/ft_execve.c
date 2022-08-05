#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*ft_execve(char *cmd)
{
	char	**path;
	int	i;
	char	**str;

	str = ft_calloc(sizeof(char*), 2);
	path = ft_calloc(sizeof(char*), 5);
	if (!path)
		return (0);
	path[0] = "/usr/local/sbin";
	path[1] = "/usr/local/bin";
	path[2] = "/usr/sbin";
	path[3] = "/usr/bin";
	i = 0;
	while (i < 4)
	{
		str[0] = ft_strjoin(path[i++], cmd);
		if (!execve(str[0], str, NULL))
			break ;
	}
	free(str[0]);
	free(str);
	free(path);

	return (path);
}

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
