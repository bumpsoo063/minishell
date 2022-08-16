/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:43:34 by kyoon             #+#    #+#             */
/*   Updated: 2022/08/10 21:51:34 by kyoon            ###   ########.fr       */
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

char	*ft_dlt(char *end)
{
	char	*str;
	char	*ret;
	char	*tmp;

	ret = ft_calloc(1, 1);
	while (1)
	{
		// minishell 실행 중이므로 rl_redisplay로 변경여부 확인필요	
		str = readline("heredoc>");
		if (!ft_strncmp(str, end, ft_strlen(str) + 1))
			break ;
		tmp = ret;
		ret = ft_strjoin(ret, str);
		free(str);
		free(tmp);
		tmp = ret;
		ret = ft_strjoin(ret, "\n");
	printf("%s\n", ft_dlt(av[1]));
		free(tmp);
	}
	return (ret);
}
