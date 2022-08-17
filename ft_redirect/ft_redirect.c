/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:43:34 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/17 17:45:17 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirect.h"


// >, >>
int	ft_gt(char *path, int offset)
{
	int	fd;
	
	if (offset)
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (0);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

int	ft_lt(char *path)
{
	char	*ret;
	char	*tmp;
	char	buf[1024];
	int	fd;
	int	read_size;

	fd = open(path, O_RDONLY);

	if (fd < 0)
		return (0);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

static int	ft_dupin(void)
{
	int	fd;

	fd = open(FILE_NAME, O_RDONLY);
	if (fd < 0)
		return (0);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

int	ft_dlt(char *end)
{
	char	*str;
	int		fd;

	fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (0);
	while (1)
	{
		str = readline(">");
		if (!ft_strncmp(str, end, ft_strlen(str) + 1))
			break ;
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
	}
	close(fd);
	return (ft_dupin());
}

int	ft_rm_heredoc(void)
{
	return (unlink(FILE_NAME));
}
