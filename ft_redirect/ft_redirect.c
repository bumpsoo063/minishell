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

void	ft_gt(char *path, char *str, int offset)
{
	int	fd;
	
	if (offset)
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, str, ft_strlen(str));
	close(fd);
}

char	*err_return(char *path)
{
	char	*ret;
	char	*tmp;

	ret = ft_strdup("minishell: ");
	tmp = ret;
	ret = ft_strjoin(ret, path);
	free(tmp);
	tmp = ret;
	ret = ft_strjoin(ret, ": No such file or directory\n");
	free(tmp);
	return (ret);
}

char	*ft_lt(char *path)
{
	char	*ret;
	char	*tmp;
	char	buf[1024];
	int	fd;
	int	read_size;

	fd = open(path, O_RDONLY);

	if (fd < 0)
		return (0);
	ret = ft_calloc(1, 1);
	while (1)
	{
		read_size = read(fd, buf, 1023);
		if (read_size <= 0)
			break ;
		buf[read_size] = 0;
		tmp = ret;
		ret = ft_strjoin(ret, buf);
		free(tmp);
		if (read_size < 1023)
			break ;
	}
	return (ret);
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
		if (!ft_strncmp(str, end, ft_strlen(str)))
			break ;
		tmp = ret;
		ret = ft_strjoin(ret, str);
		free(str);
		free(tmp);
		tmp = ret;
		ret = ft_strjoin(ret, "\n");
		free(tmp);
	}
	return (ret);
}

int	main(int ac, char **av)
{
	printf("%s\n", ft_dlt(av[1]));
	return (0);
}
