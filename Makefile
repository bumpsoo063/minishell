# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 19:33:42 by bechoi            #+#    #+#              #
#    Updated: 2022/08/02 19:36:21 by bechoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=minishell
SRC=main.c \
    ft_parse.c \
    ft_init_env.c \
    ft_check_error.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
