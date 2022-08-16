/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:10:18 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/16 15:01:01 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_H
# define FT_INIT_H
# include "../t_queue/t_queue.h"
# include "../minishell.h"

char	**ft_init_env(char **env);
t_info	ft_init_info(int argc, char **argv, char **env);

#endif
