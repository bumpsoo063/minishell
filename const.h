/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:26:58 by bechoi            #+#    #+#             */
/*   Updated: 2022/08/19 14:56:26 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# define PARSE_ERROR "parse error\n"
# define PROM "minishell $ "
# define HEREDOC "/tmp/.minishell_heredoc_bechoi_kyoon"
# define NOFILE "No such file or directory\n"
# define NOCOMM "command not found\n"
# define NOPERM "Permission denied\n"

# define INPUT "<"
# define D_INPUT "<<"
# define OUTPUT ">"
# define D_OUTPUT ">>"

# define PIPE "|"

# define M_ECHO "echo"
# define CD "cd"
# define PWD "pwd"
# define EXPORT "export"
# define UNSET "unset"
# define ENV "env"
# define EXIT "exit"

enum	e_chars {
	Quote = 39,
	D_Quote = 34,
	Input = 60,
	Output = 62,
	Pipe = 124,
	Equal = 61,
	Space = 32,
	Dollar = 36,
	Brace_O = 123,
	Brace_C = 125,
};

#endif
