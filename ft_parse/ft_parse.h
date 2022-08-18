/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:25:06 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/17 17:27:44 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H
# include "../minishell.h"

char	**ft_parse(char *str, char **env, t_info *info);
char	*ft_substitute(char *str, char **env, t_info *info);
char	*ft_search_env(char *key, char **env);
void	ft_parse_free(char **parse);
int	ft_parse_syntax(char **parse);

#endif
