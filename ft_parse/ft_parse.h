/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:25:06 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/04 14:01:43 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

char	**ft_parse(char *str, char **env);
char	*ft_substitute(char *str, char **env);
char	*ft_search_env(char *key, char **env);

#endif
