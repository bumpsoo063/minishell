/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:25:06 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/04 13:25:07 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H
# include "../minishell.h"

char	**ft_parse(char *str, t_info *info);
char	*ft_substitute(char *str, t_info *info);
char	*ft_search_env(char *key, t_info *info);

#endif
