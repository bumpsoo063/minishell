# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 19:33:42 by bechoi            #+#    #+#              #
#    Updated: 2022/08/17 18:05:17 by bechoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=minishell
SRC=./main.c \
    ./ft_check_error.c \
    ./ft_command.c \
    ./t_info.c \
    ./builtin/ft_cd.c \
    ./builtin/ft_echo.c \
    ./builtin/ft_env.c \
    ./builtin/ft_exit.c \
    ./builtin/ft_export.c \
    ./builtin/ft_export_print.c \
    ./builtin/ft_pwd.c \
    ./builtin/ft_unset.c \
    ./ft_execve/ft_execve.c \
    ./ft_parse/ft_parse.c \
    ./ft_parse/ft_parse_free.c \
    ./ft_parse/ft_parse_syntax.c \
    ./ft_parse/ft_search_env.c \
    ./ft_parse/ft_substitute.c \
    ./ft_pipe/ft_pipe.c \
    ./ft_redirect/ft_red.c \
    ./ft_redirect/ft_redirect.c \
    ./ft_sig/ft_sig.c \
    ./ft_sig/ft_sig2.c \
    ./t_queue/t_q_str.c \

LIBFT=./libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -o $(NAME)

$(LIBFT): 
	make -C libft

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
