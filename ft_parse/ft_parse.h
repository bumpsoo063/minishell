/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:25:06 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/19 14:14:22 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H
# include "../minishell.h"
# include "../t_queue/t_queue.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

char	**ft_parse(char *str, char **env, t_info *info);
char	*ft_substitute(char *str, char **env, t_info *info);
char	*ft_search_env(char *key, char **env);
void	ft_parse_free(char **parse);
int		ft_parse_syntax(char **parse);

#endif
